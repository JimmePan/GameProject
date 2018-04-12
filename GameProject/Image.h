#pragma once

#include "Singleton.h"
#include<vector>


class Image final :public Singleton<Image>
{
public:
	Image();
	~Image() = default;
	void load() {};
	void release();

	const int* getPlayer() const { return _player; }
	const int* getPlayerMuteki() const { return _playerMuteki; }
	const int* getSlowPlayer() const { return _slowPlayer; }
	int getplayerShot1() const { return _playerShot1; }			//今后可能会做成自己子弹类数组
	int getplayerShot2() const { return _playerShot2; }			//今后可能会做成自己子弹类数组
	const int* getOnmyou() const { return _onmyou; }
	const int* getEnemyDelEffect() const { return _enemyDelEffect; }
	const int* getEnemyDelEffect2() const { return _enemyDelEffect2; }
	const int* getShotEnemyEffect1() const { return _shotEnemyEffect1; }
	const int* getBulletBreak() { return _bulletBreak; }
	const int* getBoomEffect() { return _boomEffect; }
	int getBoard() const { return _board; }
	int getFusuma() const { return _fusuma; }
	int getFloor() const { return _floor; }
	int getBackSpell00() const { return _backSpell00; }
	int getBackSpell01() const { return _backSpell01; }
	const int* getEnemyNormal() const { return _enemyNormal; }
	const int* getEnemyBig() const { return _enemyBig; }
	int getPl00BoomA() const { return _pl00BoomA; }
	const int* getItem() const { return _item; }
	const int* getBoss01()const { return _boss01; }
	int getBossHpR() const { return _bossHpR; }
	int getBossHpW() const { return _bossHpW; }


private:
	int myLoadGraph(const char *);		//原例中传入并非常量，注意，今后会修改
	int myLoadDivGraph(const char * filename, int n, int xn, int yn, int w, int h, int *buf);

	std::vector<int> _images;

	int _player[24]; //自机移动
	int _playerMuteki[24];//自机无敌移动
	int _slowPlayer[2];	//自机慢速背景
	int _playerShot1;	//自机主子弹
	int _playerShot2;	//自机子子弹
	int _onmyou[3];		//自机子子弹背景1（阴阳玉）
	int _enemyDelEffect[5];//敌机死亡效果
	int _enemyDelEffect2[4];//敌机死亡效果
	int _shotEnemyEffect1[8];	//击中敌方特效
	int _bulletBreak[8];	//消弹特效
	int _boomEffect[12];	//boom特效
	int _board;			//游戏背景
	int _fusuma, _floor;//3d背景素材
	int _backSpell00;	//场景背景
	int _backSpell01;	//场景背景
	int _enemyNormal[224];	//中等大小妖精
	int _enemyBig[56];	//大型妖精
	int _pl00BoomA;
	int _item[8];
	int _boss01[11];
	int _bossHpR;
	int _bossHpW;
};
