#pragma once

#include "Singleton.h"
#include <vector>

using namespace std;
class BGM final :public Singleton<BGM>
{
public:
	BGM();
	~BGM() = default;
	void load() {};
	void release();
	void play(int i);

private:
	int myLoadBGM(const char *);
	void change(int i);
	void setBGM();
	
	std::vector<int> _BGM;
	int bgm = 0;

};
