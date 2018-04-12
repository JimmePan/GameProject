#pragma once
#include "Task.h"
class Effect : public Task
{
public:
	Effect();
	virtual ~Effect() = default;
	virtual bool update() override = 0;

	int getEff() const { return _eff; }
	void setEff(int eff) { _eff = eff; }
	int getImg() const { return _img; }
	void setImg(int img) { _img = img; }
	int getBrt() const { return _brightness; }
	void setBrt(int brt) { _brightness = brt; }

	float getX() const { return _x; }
	void setX(float x) { _x = x; }
	float getY() const { return _y; }
	void setY(float y) { _y = y; }
	float getR() const { return _r; }
	void setR(float r) { _r = r; }
	float getAngle() const { return _angle; }
	void setAngle(float angle) { _angle = angle; }

protected:
	int _flag; //存在
	int _count; //效果计时
	int _color; //颜色
	int _kind;//效果分歧
	int _img;
	int _eff;	//特效形势		//1：带亮度变化特效 
	int _brightness;//亮度

	float _x;
	float _y;
	float _r;	//大小比例
	float _angle;
};

