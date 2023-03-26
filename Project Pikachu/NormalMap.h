#pragma once
#include "InterfaceMenu_1.h"
#include "Players.h"
void NormalMap(players& player)
{
	char c;
	do
	{
		system("cls");
		GoToXY(10, 2);
		cout << "Player:" << player.name;
		GoToXY(35, 2);
		cout << "Life:" << player.life;
		GoToXY(55, 2);
		cout << "Points:" << player.point;
		GoToXY(80, 2);
		cout << "Normal Mode";
		 c = _getch();
	} while (c == Enter);
		

}
