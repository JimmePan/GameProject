
#pragma once
#include "AbstractJudge.h"
#include "BulletManager.h"
#include "Player.h"
#include "EnemyManager.h"
#include "EffectManager.h"


using namespace std;
class EnemyShotJudgePlayer :
	public AbstractJudge
{
public:
	EnemyShotJudgePlayer();
	virtual ~EnemyShotJudgePlayer() = default;
	static void Judge(std::shared_ptr<BulletManager> &bullets,  std::shared_ptr<Player> &p);


private:
	static void JudgeBullet(std::list<std::shared_ptr<Bullet>>::iterator & i, std::shared_ptr<Player>& p);
};
