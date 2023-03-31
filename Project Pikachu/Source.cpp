#include "CheckNormal.h"
#include "InterfaceMenu_1.h"
#include "Credit.h"
#include "Players.h"
#include "NormalMap.h"
#include "EndingBackground.h"
#include "BinIO.h"
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
			
			int flag = 0;
			system("cls");
			PlayerInfo(user, flag);
			system("cls");
			NormalMap(user,flag);
			if (!flag)
			LoseBackGround(user);
			// Esc do nothing
			break;
		
		}
		case 3:
		{
			
			system("cls");
			LoadFile("leaderboard.bin", user);
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