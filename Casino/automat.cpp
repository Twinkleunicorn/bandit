#include "automat.h"

automat::automat(int money, int bet)
{
	srand(time(0));
	this->bet = bet;
	this->balance = money;
	for (size_t i = 0; i < 3; i++)
	{
		bar[i].push(36);
		bar[i].push(209);
		bar[i].push(65);
		bar[i].push(66);
		bar[i].push(67);
		bar[i].push(252);
		bar[i].push(64);
		bar[i].push(61);
		bar[i].push(251);
	}
}

void automat::setBet(int bet)
{
	if (bet <= 0)
	{
		return;
	}
	this->bet = bet;
}

void automat::addMoney(int money)
{
	if (money <= 0)
	{
		return;
	}
	this->balance += money;
}

bool automat::play()
{
	if (this->balance < this->bet)
		return false;

	balance -= bet;

	this->rollBars();
	this->balance += bet * getCoef();

}

void automat::rollBars()
{
	int r = 27 + rand() % 28;
	for (size_t i = 0; i < r; i++)
	{
		bar[0].pop(0);
	}

	r = 27 + rand() % 28;
	for (size_t i = 0; i < r; i++)
	{
		bar[1].pop(0);
	}

	r = 27 + rand() % 28;
	for (size_t i = 0; i < r; i++)
	{
		bar[1].pop(0);
	}
}

int automat::getCoef()
{
	int coef = 0;
	if (bar[1].front() == bar[0].front()
		|| bar[1].front() == bar[2].front())
	{
		coef = 2;
	}
	if (bar[1].front() == bar[0].front()
		&& bar[1].front() == bar[2].front())
	{
		coef = 10;
	}
	if (bar[1].front() == bar[0].front()
		&& bar[1].front() == bar[2].front()
		&& bar[0].front() == '$')
	{
		coef = 50;
	}
	return coef;
}