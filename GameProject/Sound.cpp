#include "Sound.h"
#include <DxLib.h>


Sound::Sound()
{
	_plDead = myLoadSound("E://dat/se/se_pldead00.wav",1);
	_boom = myLoadSound("E://dat/se/se_boom00.wav", 1);
	_item00 = myLoadSound("E://dat/se/se_item00.wav", 1);
	_item01 = myLoadSound("E://dat/se/se_item01.wav", 1);
	_plShot = myLoadSound("E://dat/se/se_plst00.wav",2);
	_enDamage00 = myLoadSound("E://dat/se/se_damage00.wav",2);
	_enDamage01 = myLoadSound("E://dat/se/se_damage01.wav", 2);
	_powerUp = myLoadSound("E://dat/se/se_powerup.wav", 1);
	_powerMax = myLoadSound("E://dat/se/se_powermax.wav", 1);
	_enBreak00 = myLoadSound("E://dat/se/se_enep00.wav", 1);
	_enBreak01 = myLoadSound("E://dat/se/se_enep01.wav", 1);
	_tan00 = myLoadSound("E://dat/se/se_tan00.wav", 1);
	_tan01 = myLoadSound("E://dat/se/se_tan01.wav", 1);
	_tan02 = myLoadSound("E://dat/se/se_tan02.wav", 1);
	_ch02 = myLoadSound("E://dat/se/se_ch02.wav", 1);
	_ch03 = myLoadSound("E://dat/se/se_ch03.wav", 2);
	_focusFix = myLoadSound("E://dat/se/se_focusfix.wav", 1);
	_focusFix2 = myLoadSound("E://dat/se/se_focusfix2.wav", 1);
	_kira00 = myLoadSound("E://dat/se/se_kira00.wav", 1);
	_bonus = myLoadSound("E://dat/se/se_bonus.wav", 1);
	_bonus2 = myLoadSound("E://dat/se/se_bonus2.wav", 1);
	_graze = myLoadSound("E://dat/se/se_graze.wav", 1);
	_timeout = myLoadSound("E://dat/se/se_timeout.wav", 1);
	_lazer00 = myLoadSound("E://dat/se/se_lazer00.wav", 2);
	_lazer01 = myLoadSound("E://dat/se/se_lazer01.wav", 2);
	_rain00 = myLoadSound("E://dat/se/se_rain00.wav", 1);
	_rain01 = myLoadSound("E://dat/se/se_rain01.wav", 1);
	_ufo = myLoadSound("E://dat/se/se_ufoalert.wav", 2);
	_extend = myLoadSound("E://dat/se/se_extend.wav", 1);
} 

void Sound::release()
{
	const int size = _sounds.size();
	for (int i = 0; i < size; i++) {
		DeleteSoundMem(_sounds[i]);
	}
	_sounds.clear();
}

int Sound::myLoadSound(const char * fileName,int type)
{
	int ret = LoadSoundMem(fileName);
	switch (type)
	{
	case 1:
		ChangeVolumeSoundMem(130,ret);
		break;
	case 2:
		ChangeVolumeSoundMem(80, ret);
		break;
	default:
		break;
	}
	_sounds.push_back(ret);
	return ret;
}



