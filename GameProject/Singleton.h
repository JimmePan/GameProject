#pragma once

template <typename _T>
class Singleton {
protected:
	Singleton() = default;
	virtual ~Singleton() = default;
	Singleton(const Singleton& r) = default;			//复制构造函数和赋值运算符设置为保护确保单例唯一
	Singleton& operator = (const Singleton& r) = default;

public:
	static _T* getIns() {

		static _T inst;
		return &inst;
	}

};


