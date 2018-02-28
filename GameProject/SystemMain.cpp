#include <DxLib.h>
#include "SystemMain.h"
#include "Define.h"
#include "Looper.h"

/*dx库以及游戏初始化*/
bool SystemMain::initialize() const {
	SetAlwaysRunFlag(TRUE);		//窗口活动
	SetWindowSizeChangeEnableFlag(TRUE);	//自由更变窗口大小
	SetOutApplicationLogValidFlag(FALSE);	//不记录输出
	SetWindowText("东方逗你玩");	//窗口标题
	ChangeWindowMode(TRUE);			//窗口模式启动
	//SetWindowSizeExtendRate(1.0);	//改变窗口大小，在放大比例
	const int COLOR_BIT = 32;		//颜色位数
	SetGraphMode(Define::WIN_W, Define::WIN_H, COLOR_BIT);	//设置分辨率
	if (DxLib_Init()) {
		return FALSE;		//异常状态终止
	}
	SetDrawScreen(DX_SCREEN_BACK);		//绘图目标图形区域的指定
	return TRUE;
}

/*
*简要的DX库和游戏终止处理
*/
void SystemMain::finalize() const
{
	DxLib_End();
}

/*main*/
void SystemMain::main() const {
	Looper looper;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		if (!looper.loop()) {
			break;
		}
	}
}