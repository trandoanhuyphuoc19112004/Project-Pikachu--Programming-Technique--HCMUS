#include "Players.h"

string PlayerInfo(players& player)
{
	string s;
	do
	{
		SetColor(11);
		LoadandDrawAscii("Logo.txt", 15, 30, 3);
		LoadandDrawAscii("Onix.txt", 15, 1, 11);
		LoadandDrawAscii("Pikachu.txt", 15, 75, 13);
		GoToXY(40, 20);
		cout << " ENTER YOUR NAME:";
		HideCursor(1);
		cin.getline(player.name, 30);
		s = std::string(player.name);
		player.life = 3;
		player.point = 0;
		HideCursor(0);
	} while (s == "");
	return s;
}