#include <DxLib.h>
#include "SystemMain.h"
#include "Define.h"
#include "Looper.h"

/*dx���Լ���Ϸ��ʼ��*/
bool SystemMain::initialize() const {
	SetAlwaysRunFlag(TRUE);		//���ڻ
	SetWindowSizeChangeEnableFlag(TRUE);	//���ɸ��䴰�ڴ�С
	SetOutApplicationLogValidFlag(FALSE);	//����¼���
	SetWindowText("����������");	//���ڱ���
	ChangeWindowMode(TRUE);			//����ģʽ����
	//SetWindowSizeExtendRate(1.0);	//�ı䴰�ڴ�С���ڷŴ����
	const int COLOR_BIT = 32;		//��ɫλ��
	SetGraphMode(Define::WIN_W, Define::WIN_H, COLOR_BIT);	//���÷ֱ���
	if (DxLib_Init()) {
		return FALSE;		//�쳣״̬��ֹ
	}
	SetDrawScreen(DX_SCREEN_BACK);		//��ͼĿ��ͼ�������ָ��
	return TRUE;
}

/*
*��Ҫ��DX�����Ϸ��ֹ����
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