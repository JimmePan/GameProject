#pragma once
#include "AbstractJudge.h"
#include "Player.h"
#include "EnemyManager.h"
#include "EffectManager.h"

using namespace std;
class EnemyJudgePlayer :
	public AbstractJudge
{
public:
	EnemyJudgePlayer();
	virtual ~EnemyJudgePlayer() = default;
	static void Judge(std::shared_ptr<EnemyManager> &em, std::shared_ptr<Player> &p);
private:
	static void EnemyHpDe(std::shared_ptr<EnemyManager> &em);
};
