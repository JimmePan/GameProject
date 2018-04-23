#pragma once

#include "AbstractScene.h"
#include <memory>
#include "Player.h"
#include "Board.h"
#include "AbstractBackground.h"
#include "EnemyManager.h"
#include "PlayerShotManager.h"
#include "Judgement.h"
#include "EffectManager.h"
#include "BulletManager.h"
#include "ItemManger.h"
#include "Background01spell.h"
#include "Background01.h"

class GameScene : public AbstractScene
{
public:
	const static char* ParameterTagStage;
	const static char* ParameterTagLevel;

	GameScene(IOnSceneChangedListener* impl, const Parameter& parameter);
	virtual ~GameScene() = default;

	void update() override;
	void draw() const override;

private:
	int _level;
	std::shared_ptr<Player> _player;
	std::shared_ptr<PlayerShotManager> _playerShotManager;
	std::shared_ptr<Board> _board;
	std::shared_ptr<AbstractBackground> _background;
	std::shared_ptr<AbstractBackground> _backgroundSpell;
	std::shared_ptr<EnemyManager> _enemyManager;
	std::shared_ptr<BulletManager> _bulletManager;
	std::shared_ptr<EffectManager> _effectManager;
	std::shared_ptr<ItemManger> _itemManger;
	std::shared_ptr<Judgement> _judgement;
};

