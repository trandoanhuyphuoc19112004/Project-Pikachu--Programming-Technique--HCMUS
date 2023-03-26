#include "CheckNormal.h"
#include "InterfaceMenu_1.h"
#include "Credit.h"
int main()
{
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
			cout << "abc";
			break;
		}
		case 3:
		{
			system("cls");
			CreditInfo();
			//system("Pause");
		}
		}
	} while (true);

	
}