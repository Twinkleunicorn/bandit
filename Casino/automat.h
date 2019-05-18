#pragma once
#include"cycleQueue.h"
#include<time.h>
class automat
{
	cycleQueue<char> bar[3];
	int balance;
	int bet;

public:
	automat(int money, int bet);
	void setBet(int bet);
	void addMoney(int money);
	int getMoney()const { return balance; }
	int getBet()const { return bet; }
	bool play();
	char operator[](int index)const { return bar[index].front(); }
private:
	void rollBars();
	int getCoef();
};
