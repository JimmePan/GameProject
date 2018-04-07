#include "BossHp.h"
#include <DxLib.h>
#include "Image.h"
#include "Define.h"

BossHp::BossHp()
{
}

void BossHp::DrawBossHp(int maxHp, int hp, int num) const
{
	int i, j, k = 1;
	for (j = num - 1; j > 0; j--,k++) {
		for (int i = 0; i < 25; i++) {
			if (k % 2 > 0)
				DrawGraph(Define::HP_X + i + (num - j - 1) * 30, 2 + Define::HP_Y, Image::getIns()->getBossHpR(), FALSE);
			else
			{
				DrawGraph(Define::HP_X + i + (num - j - 1) * 30, 2 + Define::HP_Y, Image::getIns()->getBossHpW(), FALSE);
			}
		}
	}
	for (i = 0; i < Define::IN_W*(0.88 - (num - 1)*0.04)*hp / maxHp; i++) {
		if (num % 2 > 0)
			DrawGraph((num - 1) * 30 + Define::HP_X + i, 2 + Define::HP_Y, Image::getIns()->getBossHpR(), FALSE);
		else
		{
			DrawGraph((num - 1) * 30 + Define::HP_X + i, 2 + Define::HP_Y, Image::getIns()->getBossHpW(), FALSE);
		}
	}
}

