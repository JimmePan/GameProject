#pragma once
class Define
{
public:
	const static int WIN_W;
	const static int WIN_H;

	const static int OUT_W;	//外框宽度
	const static int OUT_H;	//外框高度
	const static int IN_W;	//内框宽度
	const static int IN_H;	//内框高度
	const static int CENTER_X;	//移动范围中心点
	const static int CENTER_Y;
	const static int IN_X;	//内部框架位置X
	const static int IN_Y;	//内部框架位置Y
	const static int ITEM_GET_LINE; //道具收集线
	const static int HP_X;	//血条位置
	const static int HP_Y;

	const static float PI;

	const static int PL_POWER[];	//自机子弹威力
	const static float PL_RANGE[];	//自机子弹判定范围

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

