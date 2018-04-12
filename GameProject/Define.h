#pragma once
class Define
{
public:
	const static int WIN_W;
	const static int WIN_H;

	const static int OUT_W;	//�����
	const static int OUT_H;	//���߶�
	const static int IN_W;	//�ڿ���
	const static int IN_H;	//�ڿ�߶�
	const static int CENTER_X;	//�ƶ���Χ���ĵ�
	const static int CENTER_Y;
	const static int IN_X;	//�ڲ����λ��X
	const static int IN_Y;	//�ڲ����λ��Y
	const static int ITEM_GET_LINE; //�����ռ���
	const static int HP_X;	//Ѫ��λ��
	const static int HP_Y;

	const static float PI;

	const static int PL_POWER[];	//�Ի��ӵ�����
	const static float PL_RANGE[];	//�Ի��ӵ��ж���Χ

	const static float POWER_MAX;
	const static float POWER_MIN;

	const static float ITEM_POWER[];
	const static int ITEM_SCORE[];



	enum eStage {
		Stage1,
		Stage2,
		Stage3,
		Stage4,
		Stage5,
		StageEX,
		StageNum,
	};

	enum eLevel {
		Easy,
		Normal,
		LevelNum
	};

	const static int BOSS_01_IMG[];
	const static int BOSS_01_MOVER[];
	const static int BOSS_01_SHOTER[];
	const static int BOSS_01_HP[];
	const static int BOSS_01_ITEM[];
};

