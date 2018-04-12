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
	std::stack<std::shared_ptr<AbstractScene>> _sceneStack; //�����Ķ�ջ		//shared_ptr����ָ�룬ָ������ΪAbstractScene�Ķ���	
	Fps _fps;
};