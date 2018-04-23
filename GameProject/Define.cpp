#include "Define.h"
#include "Image.h"

const int Define::WIN_W = 1280;
const int Define::WIN_H = 960;

const float Define::PI = 3.141592654f;

const int Define::OUT_W = 896;
const int Define::OUT_H = 960;
const int Define::IN_W = 770;
const int Define::IN_H = 880;
const int Define::CENTER_X = (OUT_W / 2);
const int Define::CENTER_Y = (OUT_H / 2);
const int Define::IN_X = (OUT_W - IN_W) / 2;
const int Define::IN_Y = (OUT_H - IN_H) / 2;
const int Define::ITEM_GET_LINE = IN_H / 3;
const int Define::HP_X = IN_X + 36;
const int Define::HP_Y = IN_Y + 12;

//4p ÃëÉË1860
const int Define::PL_POWER[] = { 45,12 };
const float Define::PL_RANGE[] = { 7.f,2.f };

const float Define::POWER_MAX = 4.00f;
const float Define::POWER_MIN = 0.00f;

const float Define::ITEM_POWER[] = { 0.05f,0.f,0.f,1.00f,0.f,4.00f,0.f,0.f };
const int Define::ITEM_SCORE[] = { 0,10,100,0,0,0,0,100 };

//const int Define::BOSS_IMAGE[] = { BOSS_01_IMG };
//const int Define::BOSS_MOVER[] = { BOSS_01_MOVER };
//const int Define::BOSS_SHOTER[] = { BOSS_01_SHOTER };
//const int Define::BOSS_HP[] = { BOSS_01_HP };

//const int Define::BOSS_01_IMG[] = Image::getIns()->getBoss01();
const int Define::BOSS_01_MOVER[] = { 2,3,5,6 };
const int Define::BOSS_01_SHOTER[] = { 2,1,3,4 };
const int Define::BOSS_01_HP[] = { 12000,14000,12000,16000 };
//const int Define::BOSS_01_HP[] = { 2000,2000,2000,5000 };
const int Define::BOSS_01_ITEM[] = { 4,4,4,4 };