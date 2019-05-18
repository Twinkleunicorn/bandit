#pragma once
#include"automat.h"
#include<Windows.h>
#include<string>
class automatConsole
{
	automat model;
public:
	automatConsole();
	void start();
	void mainMenu();
	void addMoneyMenu();
	void changeBetMenu();
	void CoeffsMenu();

};

