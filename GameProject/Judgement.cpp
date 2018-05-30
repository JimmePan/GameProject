#include "Judgement.h"
#include "PlayerShotJudgeEnemy.h"
#include "EnemyShotJudgePlayer.h"
#include "EnemyJudgePlayer.h"
#include "ItemJudgePlayer.h"

Judgement::Judgement()
{
}

bool Judgement::update(std::shared_ptr<PlayerShotManager> &psm, std::shared_ptr<EnemyManager> &em,
	std::shared_ptr<BulletManager> &bm, std::shared_ptr<Player>& p, std::shared_ptr<ItemManger> &im)
{
	PlayerShotJudgeEnemy::Judge(psm, em);
	EnemyShotJudgePlayer::Judge(bm, p);
	EnemyJudgePlayer::Judge(em, p);
	ItemJudgePlayer::Judge(im, p);
	return true;
}

