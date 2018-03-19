#include "GameScene.h"
#include <DxLib.h>
#include "Macro.h"
#include "Background01spell.h"
#include "Background01.h"

using namespace std;

const char* GameScene::ParameterTagStage = "ParameterTagStage";	//����stage
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";	//����level

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter) :AbstractScene(impl, parameter)
{
	//_level = parameter.get(ParameterTagLevel);	//����Ѷ�
	_background = make_shared<Background01>();
	_backgroundSpell = make_shared<Background01spell>();
	_player = make_shared<Player>();
	_board = make_shared<Board>();
	_enemyManager = make_shared<EnemyManager>();
	_bulletManager = make_shared<BulletManager>();
	_playerShotManager = make_shared<PlayerShotManager>();
	_judgement = make_shared<Judgement>();
	_effectManager = make_shared<EffectManager>();
}

void GameScene::update() {
	//_backgroundSpell->update();		//�ԳƱ���
	_background->update();
	_player->update();
	_board->update();
	_enemyManager->update();
	_bulletManager->update();
	_playerShotManager->update();
	_judgement->update(_playerShotManager, _enemyManager, _bulletManager,_player);
	_effectManager->update();
}

void GameScene::draw() const {
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "��Ϸ����Ϊ%d��",_level);
	_background->draw();
	//_backgroundSpell->draw();			//�ԳƱ���
	_player->draw();
	_board->draw();
	_enemyManager->draw();
	_bulletManager->draw();
	_playerShotManager->draw();	//���
	_effectManager->draw();

}
