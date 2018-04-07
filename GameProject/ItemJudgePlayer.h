

#pragma once
#include "AbstractJudge.h"
#include "Player.h"
#include "ItemManger.h"
#include "EffectManager.h"

using namespace std;
class ItemJudgePlayer :
	public AbstractJudge
{
public:
	ItemJudgePlayer();
	virtual ~ItemJudgePlayer() = default;
	static void Judge(std::shared_ptr<ItemManger> &im, std::shared_ptr<Player> &p);
private:
	static void CollectStatus(std::shared_ptr<ItemManger> &im);
};
