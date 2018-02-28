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
	const int* getSlowPlayer() const { return _slowPlayer; }
	int getplayerShot1() const { return _playerShot1; }			//�����ܻ������Լ��ӵ�������
	int getplayerShot2() const { return _playerShot2; }			//�����ܻ������Լ��ӵ�������
	const int* getOnmyou() const { return _onmyou; }
	const int* getEnemyDelEffect() const { return _enemyDelEffect; }
	const int* getEnemyDelEffect2() const { return _enemyDelEffect2; }
	int getBoard() const { return _board; }
	int getFusuma() const { return _fusuma; }
	int getFloor() const { return _floor; }
	int getBackSpell00() const { return _backSpell00; }
	int getBackSpell01() const { return _backSpell01; }
	const int* getEnemyNormal() const { return _enemyNormal; }
	const int* getEnemyBig() const { return _enemyBig; }


private:
	int myLoadGraph(const char *);		//ԭ���д��벢�ǳ�����ע�⣬�����޸�
	int myLoadDivGraph(const char * filename, int n, int xn, int yn, int w, int h, int *buf);

	std::vector<int> _images;
	int _player[24]; //�ӻ��ƶ�
	int _slowPlayer[2];	//�ӻ����ٱ���
	int _playerShot1;	//�ӻ����ӵ�
	int _playerShot2;	//�ӻ����ӵ�
	int _onmyou[3];		//�ӻ����ӵ�����1��������
	int _enemyDelEffect[5];//�л�����Ч��
	int _enemyDelEffect2[4];//�л�����Ч��
	int _board;			//��Ϸ����
	int _fusuma, _floor;//3d�����ز�
	int _backSpell00;	//��������
	int _backSpell01;	//��������
	int _enemyNormal[224];	//�еȴ�С����
	int _enemyBig[56];	//��������
};
