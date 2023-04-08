#include "CheckNormal.h"
#include "InterfaceMenu_1.h"
#include "Credit.h"
#include "Players.h"
#include "NormalMap.h"
#include "EndingBackground.h"
#include "BinIO.h"
#include "CheckHard.h"
#include "HardMap.h"
#include "Tutorial.h"
#include "Clock.h"
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
			int flag = -1;
			system("cls");
			string s;
			s = PlayerInfo(user);
			system("cls");
			NormalMap(user);
			// Esc do nothing
			break;

		}
		case 2:
		{

			int flag = 0;
			system("cls");
			PlayerInfo(user);
			system("cls");
			HardMap(user);
			// Esc do nothing
			break;

		}
		case 3:
		{
			
			//Tutorial();
			break;
		}
		case 4:
		{
			
			system("cls");
			LoadFile("leaderboard.bin", user);
			break;
			
		}
		case 5:
		{
			system("cls");
			CreditInfo();
		}
		}
	} while (true);
}