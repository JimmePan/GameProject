#include "Image.h"
#include <DxLib.h>


Image::Image()
{

	myLoadDivGraph("E://dat/image/player/body/pl00a.png", 24, 8, 3, 32, 48, _player);
	myLoadDivGraph("E://dat/image/player/body/pl00b.png", 24, 8, 3, 32, 48, _playerMuteki);
	myLoadDivGraph("E://dat/image/effect/slowplayer.png", 2, 2, 1, 64, 64, _slowPlayer);
	_playerShot1 = myLoadGraph("E://dat/image/player/player_shot1.png");
	_playerShot2 = myLoadGraph("E://dat/image/player/player_shot2.png");
	myLoadDivGraph("E://dat/image/player/player1_shot_onmyou.png", 3, 3, 1, 16, 16, _onmyou);
	myLoadDivGraph("E://dat/image/effect/del_effect.png", 5, 5, 1, 140, 140, _enemyDelEffect);
	myLoadDivGraph("E://dat/image/effect/del_effect2.png", 4, 4, 1, 64, 64, _enemyDelEffect2);
	myLoadDivGraph("E://dat/image/player/player_shot_effect1.png", 8, 4, 2, 16, 16, _shotEnemyEffect1);
	myLoadDivGraph("E://dat/image/effect/etbreak.png", 8, 4, 2, 64, 64, _bulletBreak);
	myLoadDivGraph("E://dat/image/effect/boom_effect.png", 12, 3, 4, 157, 81, _boomEffect);
	_front00 = myLoadGraph("E://dat/Image/front/front00.png");
	_front01 = myLoadGraph("E://dat/Image/front/front01.png");
	_front02 = myLoadGraph("E://dat/Image/front/front02.png");
	_front03 = myLoadGraph("E://dat/Image/front/front03.png");
	myLoadDivGraph("E://dat/Image/front/player_hp.png", 6, 6, 1, 28, 28, _playerHp);
	_fusuma = myLoadGraph("E://dat/image/background/fusuma.png");
	_floor = myLoadGraph("E://dat/image/background/floor.png");
	_backSpell00 = myLoadGraph("E://dat/image/background/stage01a.png");
	_backSpell01 = myLoadGraph("E://dat/image/background/stage01a.png");
	myLoadDivGraph("E://dat/image/enemy/enemy.png", 224, 16, 14, 32, 32, _enemyNormal);
	myLoadDivGraph("E://dat/image/enemy/enemy.png", 56, 8, 7, 64, 64, _enemyBig);
	_pl00BoomA = myLoadGraph("E://dat/image/player/pl00BoomA.png");
	_playerGraze = myLoadGraph("E://dat/image/player/player_graze.png");
	myLoadDivGraph("E://dat/image/bullet/item.png", 8, 8, 1, 16, 16, _item);
	myLoadDivGraph("E://dat/image/stgenm/stage01/enm1m.png", 11, 4, 3, 64, 80, _boss01);
	_bossHpR = myLoadGraph("E://dat/image/enemy/hp_boss.png");
	_bossHpW = myLoadGraph("E://dat/image/enemy/hp.png");
	myLoadDivGraph("E://dat/image/ascii/BNumber.png", 15, 15, 1, 32, 32, _bigNumber);
	myLoadDivGraph("E://dat/image/ascii/SNumber.png", 15, 15, 1, 16, 18, _smallNumber);
	myLoadDivGraph("E://dat/image/bullet/05.sparkBig.png", 9, 9, 1, 76, 76, _bulletShotEffect);
	_st01Logo = myLoadGraph("E://dat/image/front/logo/st01logo.png");
}

void Image::release()
{
	const int size = _images.size();
	for (int i = 0; i < size; i++) {
		DeleteGraph(_images[i]);
	}
	_images.clear();

}

//加载图片，并将其句柄添加到成员变量中(单张)
int Image::myLoadGraph(const char * fileName)
{
	int ret = LoadGraph(fileName);
	_images.push_back(ret);
	return ret;
}
//加载图片，并将其句柄添加到成员变量中(单张素材表)
int Image::myLoadDivGraph(const char * fileName, int n, int xn, int yn, int w, int h, int * buf)
{
	int ret = LoadDivGraph(fileName, n, xn, yn, w, h, buf);
	for (int i = 0; i < n; i++) {
		_images.push_back(buf[i]);
	}
	return ret;
}
