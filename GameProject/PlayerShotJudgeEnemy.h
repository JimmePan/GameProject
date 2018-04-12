#pragma once
#include "AbstractJudge.h"
#include "PlayerShotManager.h"
#include "EnemyManager.h"
#include "EffectManager.h"


using namespace std;
class PlayerShotJudgeEnemy :
	public AbstractJudge
{
public:
	PlayerShotJudgeEnemy();
	virtual ~PlayerShotJudgeEnemy() = default;
	static void Judge(std::shared_ptr<PlayerShotManager> &playShots, std::shared_ptr<EnemyManager> &enemys);
	static void enemy_death_judge(std::list<std::shared_ptr<AbstractEnemy>>::iterator &s);
private:
	//static bool out_judge_shot(std::list<std::shared_ptr<PlayerShot>>::iterator &i, std::list<std::shared_ptr<AbstractEnemy>>::iterator &s);
};

