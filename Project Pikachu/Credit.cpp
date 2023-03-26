#include "Credit.h"
void CreditInfo()
{
        SetColor(14);
        LoadandDrawAscii("Logo.txt", 15, 30, 5);
        LoadandDrawAscii("Onix.txt", 15, 1, 14);
        LoadandDrawAscii("Pikachu.txt", 15, 75, 16);
        GoToXY(32, 13);
        cout << "        POKEMON MATCHING GAME      ";
        GoToXY(32, 15);
        cout << "   TRAN DOAN HUY PHUOC - 22127338  ";
        GoToXY(32, 17);
        cout << "   TRAN QUOC VIET    -    22127454  ";
        GoToXY(30, 19);
        cout << "Project Progamming Techniques - VNU HCMUS";
        char c = _getch();
        if (c == Enter)
            return;
}
