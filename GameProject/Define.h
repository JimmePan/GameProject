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

	const static float PI;

	const static int PL_POWER[];	//自机子弹威力
	const static int PL_RANGE[];	//自机子弹判定范围

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

