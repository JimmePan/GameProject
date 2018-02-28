#pragma once
#include "Singleton.h"
#include <array>

enum ePad
{
	left,up,right,down,shot,bom,slow,start,change
};

class Pad final :public Singleton<Pad>
{
public:
	Pad();
	~Pad() = default;
	void update();
	int get(ePad eID) const;
private:
	void merge();

	const static int PAD_KEY_NUM = 16;
	std::array<int, PAD_KEY_NUM> _idArray;	//手柄按钮对应按键
	std::array<int, PAD_KEY_NUM> _pad;		//手柄输入按钮状态
};

