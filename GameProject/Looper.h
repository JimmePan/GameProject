#pragma once
#include <stack>
#include <memory>
#include "AbstractScene.h"
#include "IOnSceneChangedListener.h"
#include "Fps.h"


class Looper final :public IOnSceneChangedListener {
public:
	Looper();
	bool loop();
	~Looper() = default;
	void onSceneChanged(const eScene scene, const Parameter &parameter, const bool stackClear) override;
private:
	std::stack<std::shared_ptr<AbstractScene>> _sceneStack; //场景的堆栈		//shared_ptr智能指针，指向类型为AbstractScene的对象	
	Fps _fps;
};