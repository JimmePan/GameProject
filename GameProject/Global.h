#pragma once
#include "Singleton.h"

class Global final :public Singleton<Global>
{
public:
	Global();
	~Global();
	static int HIGH_SCORE;
	static int SCORE;
	static float PLAYER;
	static float POWER;
	static int GRAZE;

	int getHighScore() const { return HIGH_SCORE; }
	void setHighScore();	//从文件中获取最高分数
	void setHighScore(int highScore) { HIGH_SCORE = highScore; }

	int getScore() const { return SCORE; }
	void setScore() { SCORE = 0; }
	void setScore(int score) { SCORE += score; if (SCORE > HIGH_SCORE) HIGH_SCORE = SCORE; }

	float getPlayer() const { return PLAYER; }
	void setPlayer() { PLAYER = 4.0f; }
	void setPlayer(float pl) { PLAYER += pl; }

	float getPower() const { return POWER; }
	void setPower() { POWER = 0.0f; }
	void setPower(float power) { POWER = power; }
	void addPower(float power) { POWER += power; }

	int getGraze() const { return GRAZE; }
	void setGraze() { GRAZE = 0; }
	void addGraze() { GRAZE++; }

};

