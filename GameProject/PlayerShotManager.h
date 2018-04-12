#pragma once
#include "Task.h"
#include "PlayerShot.h"
#include <memory>
#include <list>
class PlayerShotManager :public Task
{
public:
	PlayerShotManager();
	virtual ~PlayerShotManager() = default;
	static void add(float x, float y, int kind);

	bool update() override;
	void draw() const override;

	std::list<std::shared_ptr<PlayerShot>>* getList() { return &_list; }
private:
	static std::list<std::shared_ptr<PlayerShot>> _list;
};

