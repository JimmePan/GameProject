#pragma once
#include "Task.h"
#include "Bullet.h"
#include <memory>
#include <list>
class BulletManager :public Task
{
public:
	BulletManager();
	virtual ~BulletManager() = default;
	static void add(float x, float y, unsigned int type, unsigned int color, int eff, float angle, float base_angle, float speed, float rate);

	bool update() override;
	void draw() const override;

	std::list<std::shared_ptr<Bullet>>* getListSmall() { return &_list_small; }
	std::list<std::shared_ptr<Bullet>>* getListNormal() { return &_list_normal; }
	std::list<std::shared_ptr<Bullet>>* getListBig() { return &_list_big; }
private:
	static std::list<std::shared_ptr<Bullet>> _list_small;
	static std::list<std::shared_ptr<Bullet>> _list_normal;
	static std::list<std::shared_ptr<Bullet>> _list_big;
};

