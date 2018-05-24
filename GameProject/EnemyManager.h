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

	static void addSpell27(float x, float y, int type,int shotID);
	static void clearNormalEn();

	static int getSize();
	static std::list<std::shared_ptr<AbstractEnemy>>* getList() { return &_list; }
private:
	static std::list<std::shared_ptr<AbstractEnemy>> _list;
	int _count;
	int _halfCount;
	void clearEnemy();
	void state01Play();
	void state02Play();
};

