#include "CustomMode.h"
void ChooseMode()
{
	char c;
	do
	{
		SetColor(11);
		LoadandDrawAscii("Logo.txt", 15, 30, 3);
		LoadandDrawAscii("Onix.txt", 15, 1, 11);
		LoadandDrawAscii("Pikachu.txt", 15, 75, 13);
		GoToXY(40, 20);
		c = _getch();
	} while (c == Enter);
	
}