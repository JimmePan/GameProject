#pragma once
class AbstractJudge
{
public:
	AbstractJudge() = default;
	virtual ~AbstractJudge() = default;
	virtual void Judge() const = 0;
};

