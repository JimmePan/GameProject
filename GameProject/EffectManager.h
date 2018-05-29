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
	static void addShotEnemyEffect01(float x, float y);
	static void addShotEnemyEffect02(float x, float y);
	static void addBoomEffect01();
	static void addBoomEffect02(float x, float y, float angle);
	static void addBulletBreakEffect(float x, float y, int color);
	static void addGrazeEffect(float x, float y);
	static void addBulletShotEffect(float x, float y, int color);
	static void addLogoEffect(float x, float y, int num);
	static void addSpellCardEffect(int num);
private:
	static std::list<std::shared_ptr<Effect>> _list;
};

