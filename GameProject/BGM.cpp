#include "BGM.h"
#include <DxLib.h>

BGM::BGM()
{
	setBGM();
}

void BGM::release()
{
	StopSoundMem(bgm);
	DeleteSoundMem(bgm);
}

void BGM::play(int i)
{
	change(i);
	if (bgm != 0) {
		SetLoopPosSoundMem(26672, bgm);
		PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
	}
}

void BGM::change(int i)
{
	if (bgm != 0) {
		StopSoundMem(bgm);
	}
	if (i == -1) {
		bgm = 0;
		return;
	}
	bgm = _BGM[i];
}

int BGM::myLoadBGM(const char *fileName)
{
	int ret = LoadSoundMem(fileName);
	ChangeVolumeSoundMem(130, ret);
	return ret;
}

void BGM::setBGM()
{
	_BGM.push_back(myLoadBGM("E://dat/bgm/00.mp3"));
	_BGM.push_back(myLoadBGM("E://dat/bgm/01.mp3"));
}


