#include "Parameter.h"

/*
@参数设置
*/

void Parameter::set(std::string key, int val) {
	_map[key] = val;
}

/*
@参数获得
*/
int Parameter::get(std::string key)const {
	auto it = _map.find(key);
	if (_map.end() == it) {			//如果不存在
		return Error;
	}
	else
	{
		return it->second;
	}
}
