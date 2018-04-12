#pragma once
#include "Task.h"
#include "Item.h"
#include <memory>
#include <list>

class ItemManger :public Task
{
public:
	ItemManger();
	virtual ~ItemManger() = default;
	static void add(float x, float y, float angle, int kind);

	bool update() override;
	void draw() const override;

	std::list<std::shared_ptr<Item>>* getList() { return &_list; }
private:
	static std::list<std::shared_ptr<Item>> _list;
};

