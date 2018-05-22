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
	int getplayerShot1() const { return _playerShot1; }			//�����ܻ������Լ��ӵ�������
	int getplayerShot2() const { return _playerShot2; }			//�����ܻ������Լ��ӵ�������
	const int* getOnmyou() const { return _onmyou; }
	const int* getEnemyDelEffect() const { return _enemyDelEffect; }
	const int* getEnemyDelEffect2() const { return _enemyDelEffect2; }
	const int* getShotEnemyEffect1() const { return _shotEnemyEffect1; }
	const int* getBulletBreak() { return _bulletBreak; }
	const int* getBoomEffect() { return _boomEffect; }
	int getFront00() const { return _front00; }
	int getFront01() const { return _front01; }
	int getFront02() const { return _front02; }
	int getFront03() const { return _front03; }
	int getFusuma() const { return _fusuma; }
	int getFloor() const { return _floor; }
	int getBackSpell00() const { return _backSpell00; }
	int getBackSpell01() const { return _backSpell01; }
	const int* getEnemyNormal() const { return _enemyNormal; }
	const int* getEnemyBig() const { return _enemyBig; }
	int getPl00BoomA() const { return _pl00BoomA; }
	int getPlayerGraze() const { return _playerGraze; }
	const int* getItem() const { return _item; }
	const int* getBoss01()const { return _boss01; }
	const int* getBoss02()const { return _boss02; }
	const int* getBoss02Shot()const { return _boss02Shot; }
	int getBossHpR() const { return _bossHpR; }
	int getBossHpW() const { return _bossHpW; }
	const int* getBigNumber()const { return _bigNumber; }
	const int* getSmallNumber()const { return _smallNumber; }
	const int* getPlayerHp()const { return _playerHp; }
	const int* getBulletShotEffect()const { return _bulletShotEffect; }
	int getSt01Logo() const { return _st01Logo; }
	

private:
	int myLoadGraph(const char *);		//ԭ���д��벢�ǳ�����ע�⣬�����޸�
	int myLoadDivGraph(const char * filename, int n, int xn, int yn, int w, int h, int *buf);

	std::vector<int> _images;

	int _player[24]; //�Ի��ƶ�
	int _playerMuteki[24];//�Ի��޵��ƶ�
	int _slowPlayer[2];	//�Ի����ٱ���
	int _playerShot1;	//�Ի����ӵ�
	int _playerShot2;	//�Ի����ӵ�
	int _onmyou[3];		//�Ի����ӵ�����1��������
	int _enemyDelEffect[5];//�л�����Ч��
	int _enemyDelEffect2[4];//�л�����Ч��
	int _shotEnemyEffect1[8];	//���ез���Ч
	int _bulletBreak[8];	//������Ч
	int _boomEffect[12];	//boom��Ч
	int _front00;			//��Ϸ����
	int _front01;
	int _front02;
	int _front03;
	int _fusuma, _floor;//3d�����ز�
	int _backSpell00;	//��������
	int _backSpell01;	//��������
	int _enemyNormal[224];	//�еȴ�С����
	int _enemyBig[56];	//��������
	int _pl00BoomA;
	int _playerGraze;	//����Ч��
	int _item[8];
	int _boss01[11];
	int _boss02[8];
	int _boss02Shot[15];
	int _bossHpR;
	int _bossHpW;
	int _bigNumber[15];
	int _smallNumber[15];
	int _playerHp[6];
	int _bulletShotEffect[9];
	int _st01Logo;
};
