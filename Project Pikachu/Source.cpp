#include "CheckNormal.h"
#include "InterfaceMenu_1.h"
#include "Credit.h"
#include "Players.h"
#include "NormalMap.h"
int main()
{
	players user;
	do
	{
		system("cls");
		CreateWindows();
		int choice = CreateMenuGame();
		switch (choice)
		{
		case 0:
			exit(0);
		case 1:
		{
			system("cls");
			PlayerInfo(user);
			system("cls");
			NormalMap(user);
			break;
		}
		case 4:
		{
			system("cls");
			CreditInfo();
			//system("Pause");
		}
		}
	} while (true);
}