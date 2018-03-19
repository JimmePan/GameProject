#include "Judgement.h"
#include "PlayerShotJudgeEnemy.h"
#include "EnemyShotJudgePlayer.h"

Judgement::Judgement()
{
}

bool Judgement::update(std::shared_ptr<PlayerShotManager> &psm, std::shared_ptr<EnemyManager> &em, std::shared_ptr<BulletManager> &bm, std::shared_ptr<Player>& p)
{
	PlayerShotJudgeEnemy::Judge(psm,em);
	EnemyShotJudgePlayer::Judge(bm,p);
	return true;
}

