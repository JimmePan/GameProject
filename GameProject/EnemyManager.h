#pragma once
#include "Task.h"
#include "AbstractEnemy.h"
#include <memory>
#include <list>

class EnemyManager :public Task
{
public:
	EnemyManager();
	virtual ~EnemyManager() = default;
	bool update() override;
	void draw() const override;

	std::list<std::shared_ptr<AbstractEnemy>>* getList() { return &_list; }
private:
	std::list<std::shared_ptr<AbstractEnemy>> _list;
	int _count;

	void state01Play();
};

