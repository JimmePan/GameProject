#include "ItemJudgePlayer.h"
#include "Define.h"
#include "Global.h"
#include "CalcUtils.h"
#include "Sound.h"

ItemJudgePlayer::ItemJudgePlayer()
{
}

void ItemJudgePlayer::Judge(std::shared_ptr<ItemManger>& im, std::shared_ptr<Player>& p)
{
	if (p->getY() < Define::ITEM_GET_LINE && p->getFlag()!=2) {	//�����ռ���,�ı�����ƶ�״̬
		float a = p->getY();
		int b = p->getFlag();
		CollectStatus(im);
	}

	for (auto i = im->getList()->begin(); i != im->getList()->end();) {
		if ((*i)->getFlag() > 0) {
			if ((*i)->getFlag() == 1) {
				int rate = p->getSlow() ? 22 : 10;
				float x = (*i)->getX() - p->getX();
				float y = (*i)->getY() - p->getY();
				float r = (*i)->getRange() + p->getRange()*rate;
				if (x*x + y * y < r*r) {
					(*i)->setFlag(3);		//���Ի������ƶ�
				}

			}
			if (CalcUtils::out_judge_shot(i, &p)) {		//ʰȡ
				int kind = (*i)->getKind();
				switch (kind)
				{
				case 0:case 3:
				{
					float before = Global::POWER;
					if (before < Define::POWER_MAX) {		//С����������ʰȡ
						before + Define::ITEM_POWER[kind] >= Define::POWER_MAX ? Global::getIns()->setPower(Define::POWER_MAX) : Global::getIns()->addPower(Define::ITEM_POWER[kind]);
						if ((int)before < (int)Global::POWER) {
							//��1����������upЧ��
							PlaySoundMem(Sound::getIns()->getPowerUp(), DX_PLAYTYPE_BACK);
						}
						if (Global::POWER > Define::POWER_MAX - 0.001f) {
							p->setPowerMax(true);
							if (!CheckSoundMem(Sound::getIns()->getPowerMax())) {
								PlaySoundMem(Sound::getIns()->getPowerMax(), DX_PLAYTYPE_BACK);
							}
						}
					}
					(*i)->setFlag(0);
				}
				case 1:
					(*i)->setFlag(0);
					break;
				case 2:
					(*i)->setFlag(0);
					break;
				case 4:
					(*i)->setFlag(0);
					break;
				case 5:
					(*i)->setFlag(0);
					break;
				case 6:
					(*i)->setFlag(0);
					break;
				case 7:
					(*i)->setFlag(0);
					break;
				default:
					break;
				}
				if ((*i)->getFlag() >= 7) {
					if (!CheckSoundMem(Sound::getIns()->getItem01())) {
						PlaySoundMem(Sound::getIns()->getItem01(), DX_PLAYTYPE_BACK);
					}
				}
				else
				{
					PlaySoundMem(Sound::getIns()->getItem00(), DX_PLAYTYPE_BACK);
				}
			}


		}
		i++;
	}

}

void ItemJudgePlayer::CollectStatus(std::shared_ptr<ItemManger>& im)
{
	for (auto i = im->getList()->begin(); i != im->getList()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(7);		//ͬʱ�����ƶ��ٶ�
		}
		i++;
	}
}



