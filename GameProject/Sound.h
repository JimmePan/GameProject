#pragma once

#include "Singleton.h"
#include <vector>


class Sound final :public Singleton<Sound>
{
public:
	Sound();
	~Sound() = default;
	void load() {};
	void release();

	int getPlDead() const { return _plDead; }
	int getPlShot() const { return _plShot; }
	int getEnDamage00() const { return _enDamage00; }
	int getEnDamage01() const { return _enDamage01; }
	int getBoom() const { return _boom; }
	int getItem00() const { return _item00; }
	int getItem01() const { return _item01; }
	int getPowerUp() const { return _powerUp; }
	int getPowerMax() const { return _powerMax; }
	int getEnBreak00() const { return _enBreak00; }
	int getEnBreak01() const { return _enBreak01; }
	int getTan00() const { return _tan00; }
	int getTan01() const { return _tan01; }
	int getTan02() const { return _tan02; }
	int getCh02() const { return _ch02; }
	int getCh03() const { return _ch03; }
	int getFocusFix() const { return _focusFix; }
	int getFocusFix2() const { return _focusFix2; }
	int getKira00() const { return _kira00; }
	int getBonus() const { return _bonus; }
	int getBonus2() const { return _bonus2; }
	int getGraze() const { return _graze; }
	int getTimeout() const { return _timeout; }
	int getLazer00() const { return _lazer00; }
	int getLazer01() const { return _lazer01; }
	int getRain00() const { return _rain00; }
	int getRain01() const { return _rain01; }
	int getUFO() const { return _ufo; }

private:
	int myLoadSound(const char *, int type);

	std::vector<int> _sounds;

	int _plDead;
	int _plShot;
	int _enDamage00;
	int _enDamage01;
	int _boom;
	int _item00;
	int _item01;
	int _powerUp;
	int _powerMax;
	int _enBreak00;
	int _enBreak01;
	int _tan00;
	int _tan01;
	int _tan02;
	int _ch02;
	int _ch03;
	int _focusFix;
	int _focusFix2;
	int _kira00;
	int _bonus;
	int _bonus2;
	int _graze;
	int _timeout;
	int _lazer00;
	int _lazer01;
	int _rain00;
	int _rain01;
	int _ufo;
};
