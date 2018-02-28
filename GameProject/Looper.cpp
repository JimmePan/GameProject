#include "Looper.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Error.h"
#include "Macro.h"
#include "Keyboard.h"
#include "Pad.h"
#include "Image.h"

using namespace std;

Looper::Looper() {													//ջ��ΪTitleSceneʱ�����¼������5֡�ĵ�֡��ԭ����
	Image::getIns()->load();

	Parameter parameter;
	_sceneStack.push(std::make_shared<GameScene>(this, parameter));	//make_shared��һ���ǳ�Ա���������и������������ڴ棬����ֻ����һ���ڴ���ŵ㣬
																		//����ʽͨ�����캯����ʼ����shared_ptr��Ƚϣ�������Ҫ�������η����ڴ�
}

/*����ջ���ĳ���*/
bool Looper::loop() {
	Keyboard::getIns()->update();
	Pad::getIns()->update();
	_sceneStack.top() -> update(); //���¶�������
	_sceneStack.top() -> draw();	//����
	_fps.draw();
	_fps.wait();
	return true;
}

/*
�����ı�
@param scene ����ĳ�������
@param parameter ǰһ�������������Ĳ���
@param stackClear �����ǰ������ջ���ж�
*/
void Looper::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) {
	if (stackClear) {			//��ջ�Ƿ����
		while (!_sceneStack.empty())		//��ջ�ڷǿ�
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
		//ERR("����ĳ�������");
		break;
	}
}