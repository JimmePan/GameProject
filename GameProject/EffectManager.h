#pragma once
#include "Task.h"
#include <memory>
#include <list>
#include "Effect.h"
class EffectManager :public Task
{
public:
	EffectManager();
	virtual ~EffectManager() = default;
	bool update() override;
	void draw() const override;
	static void addEnemyDelEffect(float x, float y, int color);
	static void addEnemyDelEffect2(float x, float y, int color);
private:
	static std::list<std::shared_ptr<Effect>> _list;
};
