#pragma once
class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void Update(int& total_coins, float& totalFule) = 0;
protected:

};

