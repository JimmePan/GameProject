#include "Global.h"

int Global::HIGH_SCORE;
int Global::SCORE;
float Global::PLAYER;
float Global::POWER;
int Global::GRAZE;

Global::Global()
{
	setHighScore();
	setScore();
	setPlayer();
	setPower();
	setGraze();
}


Global::~Global()
{
}

void Global::setHighScore()
{
	HIGH_SCORE = 10000000;
}

