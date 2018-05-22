#include "GameScene.h"
#include "Macro.h"

using namespace std;

const char* GameScene::ParameterTagStage = "ParameterTagStage";	//参数stage
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";	//参数level

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter) :AbstractScene(impl, parameter)
{
	//_level = parameter.get(ParameterTagLevel);	//获得难度
	_background = make_shared<Background01>();
	_backgroundSpell = make_shared<Background01spell>();
	_player = make_shared<Player>();
	_board = make_shared<Board>();
	_enemyManager = make_shared<EnemyManager>();
	_bulletManager = make_shared<BulletManager>();
	_playerShotManager = make_shared<PlayerShotManager>();
	_itemManger = make_shared<ItemManger>();
	_judgement = make_shared<Judgement>();
	_effectManager = make_shared<EffectManager>();
}

void GameScene::update() {
	//_backgroundSpell->update();		//对称背景
	_background->update();
	_board->update();
	_player->update();
	_enemyManager->update();
	_bulletManager->update();
	_playerShotManager->update();
	_itemManger->update();
	_judgement->update(_playerShotManager, _enemyManager, _bulletManager, _player, _itemManger);
	_effectManager->update();
}

void GameScene::draw() const {
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "游戏级别为%d级",_level);
	_background->draw();
	//_backgroundSpell->draw();			//对称背景
	_player->draw();
	_playerShotManager->draw();	//射击
	_itemManger->draw();
	_enemyManager->draw();
	_bulletManager->draw();
	_effectManager->draw();
	_board->draw();

}
