#include "Players.h"
void PlayerInfo(players& player)
{
	SetColor(11);
	LoadandDrawAscii("Logo.txt", 15, 30, 3);
	LoadandDrawAscii("Onix.txt", 15, 1, 11);
	LoadandDrawAscii("Pikachu.txt", 15, 75, 13);
	GoToXY(40, 20);
	cout << " ENTER YOUR NAME:";
	HideCursor(1);
	getline(cin, player.name);
	HideCursor(0);
}