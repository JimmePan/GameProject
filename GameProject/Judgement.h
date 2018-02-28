#pragma once
#include "Task.h"
#include "EnemyManager.h"
#include "PlayerShotManager.h"

class Judgement 
{
public:
	Judgement();
	virtual ~Judgement() = default;
	bool update(std::shared_ptr<PlayerShotManager> &psm, std::shared_ptr<EnemyManager> &em);
	//void draw() const override;
};

