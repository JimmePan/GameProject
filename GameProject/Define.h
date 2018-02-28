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

	const static float PI;

	const static int PL_POWER[];	//�Ի��ӵ�����
	const static int PL_RANGE[];	//�Ի��ӵ��ж���Χ

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
};

