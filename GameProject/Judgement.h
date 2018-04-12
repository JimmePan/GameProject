#pragma once
#include "Task.h"
#include "EnemyManager.h"
#include "PlayerShotManager.h"
#include "BulletManager.h"
#include "ItemManger.h"

class Judgement
{
public:
	Judgement();
	virtual ~Judgement() = default;
	bool update(std::shared_ptr<PlayerShotManager> &psm, std::shared_ptr<EnemyManager> &em,
		std::shared_ptr<BulletManager> &bm, std::shared_ptr<Player>& p, std::shared_ptr<ItemManger> &im);
	//void draw() const override;
};

