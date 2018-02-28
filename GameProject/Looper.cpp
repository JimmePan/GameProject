#include "Looper.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Error.h"
#include "Macro.h"
#include "Keyboard.h"
#include "Pad.h"
#include "Image.h"

using namespace std;

Looper::Looper() {													//栈底为TitleScene时，按下键会出现5帧的掉帧，原因不明
	Image::getIns()->load();

	Parameter parameter;
	_sceneStack.push(std::make_shared<GameScene>(this, parameter));	//make_shared是一个非成员函数，具有给共享对象分配内存，并且只分配一次内存的优点，
																		//和显式通过构造函数初始化的shared_ptr相比较，后者需要至少两次分配内存
}

/*处理栈顶的场景*/
bool Looper::loop() {
	Keyboard::getIns()->update();
	Pad::getIns()->update();
	_sceneStack.top() -> update(); //更新顶部场景
	_sceneStack.top() -> draw();	//绘制
	_fps.draw();
	_fps.wait();
	return true;
}

/*
场景改变
@param scene 変更的场景参数
@param parameter 前一个场景传递来的参数
@param stackClear 清楚当前场景堆栈的判断
*/
void Looper::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) {
	if (stackClear) {			//堆栈是否清空
		while (!_sceneStack.empty())		//若栈内非空
		{
			_sceneStack.pop();
		}
	}
	switch (scene)
	{
	case Title:
		_sceneStack.push(std::make_shared<TitleScene>(this, parameter));
		break;
	case Game:
		_sceneStack.push(std::make_shared<GameScene>(this, parameter));
		break;
	default:
		//ERR("错误的场景加载");
		break;
	}
}