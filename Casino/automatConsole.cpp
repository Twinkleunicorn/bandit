#include "automatConsole.h"

automatConsole::automatConsole()
	:model(0, 0)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int r = 10 + rand() % 5;
	int x = 0;
	for (size_t i = 0; i < r; i++)
	{
		cout << "Äîáðî ïîæàëîâàòü â èãðó!\n";
		cout << "Çàãðóçêà\n";
		for (size_t i = 0; i < x; i++)
		{
			cout << ".";
		}
		Sleep(300);
		x++;
		if (x == 4)
		{
			x = 0;
		}
		system("cls");
	}
}

void automatConsole::start()
{
	system("cls");
	addMoneyMenu();
	Sleep(5000);
	changeBetMenu();
	Sleep(5000);


	int choice = 0;
	while (choice != 4)
	{
		mainMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (!model.play())
			{
				cout << "Íåäîñòàòî÷íî ñðåäñòâ" << endl;
				cout << "Ââåäèòå äåíüãè èëè ïîìåíÿéòå ñòàâêó" << endl;
			}
			break;
		case 3:
			addMoneyMenu();
			break;
		case 2:
			changeBetMenu();
			break;
		case 4:
			cout << "Äî ñâèäàíèÿ" << endl;
			cout << "Âàø âûèãðûø ñîñòàâëÿåò " << model.getMoney() << " åâðî";
			break;
		default:
			cout << "Îøèáêà, ïîïðîáóéòå çàíîâî" << endl;
		}
	}
}

void automatConsole::mainMenu()
{
	system("cls");
	cout << "__________________________________________________" << endl;
	cout << ".\t.\t.\t" << model[0] << " " << model[1] << " " << model[2] << "\t.\t.\t." << endl;
	cout << "__________________________________________________" << endl;
	cout << "Âàø áàëàíñ ðàâåí " << model.getMoney() << " åâðî\n";
	cout << "Âàøà ñòàâêà: " << model.getBet() << endl;
	cout << "1.Ñûãðàòü\n2.Èçìåíèòü ñòàâêó\n3.Äîáàâèòü äåíüãè\n4.Âûéòè èç èãðû\n";

}

void automatConsole::addMoneyMenu()
{
	system("cls");
	cout << "Âàø áàëàíñ ðàâåí " << model.getMoney() << " åâðî\n";
	cout << "Ââåäèòå äåíüãè:\n";
	int money;
	cin >> money;
	model.addMoney(money);
	cout << "Òðàíçàêöèÿ ïðîøëà óñïåøíî\n";
}

void automatConsole::changeBetMenu()
{
	system("cls");
	cout << "Âàøà ñòàâêà: " << model.getBet() << endl;
	cout << "Ââåäèòå ñòàâêó\n";
	int money;
	cin >> money;
	model.setBet(money);
	cout << "Ñòàâêà óñòàíîâëåíà\n";
}

void automatConsole::CoeffsMenu()
{
	system("cls");
	cout << "Ñïðàâêà\n";
}