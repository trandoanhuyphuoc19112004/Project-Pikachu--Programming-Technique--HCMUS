#include "Tutorial.h"
#include "InterfaceMenu_1.h"
void Tutorial()
{

	char box_1[5][10]={ {" ------- "},
						{"|       |"},
						{"|   S   |"},
						{"|       |"},
						{" ------- "} };
	char box_2[5][10]={ {" ------- "},
						{"|       |"},
						{"|   E   |"},
						{"|       |"},
						{" ------- "} };

	GoToXY(1, 1);
	cout << "GAME LAW:";
	cout << " MATCH ALL VALID PAIR AND YOU WILL WIN!";
	GoToXY(1, 2);
	cout << "THE VALID MATCHING PAIR ILLUSTRATED BELOWS:";
	// I check 
	for (int i = 0; i < 5; i++)
	{
		GoToXY(1 * 13, 1 * 3 + i);
		cout << box_1[i];
	}
	for (int i = 8; i < 13; i++)
	{
		GoToXY(17, i);
		cout << "|";
	}
	for (int i = 0; i < 5; i++)
	{
		GoToXY(1 * 13, 1 * 13 + i);
		cout << box_1[i];
	}
	// L check 
	for (int i = 0; i < 5; i++)
	{
		GoToXY(1 * 30, 1 * 3 + i);
		cout << box_1[i];
	}
	for (int i = 8; i < 16; i++)
	{
		GoToXY(34, i);
		cout << "|";
	}
	for (int i = 35; i < 45; i++)
	{
		GoToXY(i, 16);
		cout << "-";
	}
	for (int i = 0; i < 5; i++)
	{
		GoToXY(1 * 42, 1 * 14 + i);
		cout << box_1[i];
	}
	// Z check 
	for (int i = 0; i < 5; i++)
	{
		GoToXY(1 * 53, 1 * 3 + i);
		cout << box_1[i];
	}
	for (int i = 8; i < 13; i++)
	{
		GoToXY(57, i);
		cout << "|";
	}
	for (int i = 58; i < 66; i++)
	{
		GoToXY(i, 13);
		cout << "-";
	}
	for (int i = 14; i < 17; i++)
	{
		GoToXY(66, i);
		cout << "|";
	}
	for (int i = 0; i < 5; i++)
	{
		GoToXY(1 * 62, 1 * 17 + i);
		cout << box_1[i];
	}
	// U check 
	for (int i = 0; i < 5; i++)
	{
		GoToXY(1 * 73, 1 * 3 + i);
		cout << box_1[i];
	}
	for (int i = 0; i < 5; i++)
	{
		GoToXY(1 * 73, 1 * 10 + i);
		cout << box_2[i];
	}
	for (int i = 0; i < 5; i++)
	{
		GoToXY(1 * 73, 1 * 17 + i);
		cout << box_1[i];
	}
	for (int i = 83; i < 94; i++)
	{
		GoToXY(i, 5);
		cout << "-";
	}
	for (int i = 6; i < 19; i++)
	{
		GoToXY(94, i);
		cout << "|";
	}
	for (int i = 83; i < 94; i++)
	{
		GoToXY(i, 19);
		cout << "-";
	}
	// Notice
	GoToXY(1, 24);
	cout << "NOTICE:";
	GoToXY(1, 25);
	cout << "USER CAN TRY 2 GAME MODES: NORMAL AND HARD";
	GoToXY(1, 26);
	cout << "EACH GAME, USER HAS 3 LIFES, 2 HELP";

	char c;
	c = _getch();
	if (c == Enter)
		return;
	
}