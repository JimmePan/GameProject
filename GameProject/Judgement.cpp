#include "Judgement.h"
#include "PlayerShotJudgeEnemy.h"

Judgement::Judgement()
{
}

bool Judgement::update(std::shared_ptr<PlayerShotManager> &psm, std::shared_ptr<EnemyManager> &em)
{
	PlayerShotJudgeEnemy::Judge(psm,em);
	return true;
}

