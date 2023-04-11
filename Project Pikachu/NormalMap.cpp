#include"CheckNormal.h"
#include"NormalMap.h"
#include "EndingBackground.h"
#include "BinIO.h"
#include "Players.h"
#include "Clock.h"
#include "InterfaceMenu_1.h"
char box[5][10] = { {" ------- "},
					{"|       |"},
					{"|       |"},
					{"|       |"},
					{" ------- "} };
bool stop = 0; // Clock
bool clear = 0; // BG
// Toa do trong mang 2 chieu nguoc voi toa do trong ham GotoXY
void drawBox(Normal_Board board, int color)
{
	// Draw Box
	SetColor(11);
	int i1 = board.i + 1, j1 = board.j + 1;
    if (board.c != ' ') 
    {
        for (int i = 0; i < 6; i++)
        {
            GoToXY(j1 * 13, i1 * 6 + i);
            cout << box[i];
        }
        if (board.Is_Selected || board.Is_Chosen)
        {
            // Set white in box selected or chosen
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color );
            for (int i = 1; i < 4; i++)
            {
                GoToXY(j1 * 13 + 1, i1 * 6 + i);
                cout << "       ";
            }
            GoToXY(j1 * 13 + 4, i1 * 6 + 2);
            cout << board.c;
            // The leter in white box is black 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        }
        // Add letter to the box
        else
        {
            GoToXY(j1 * 13 + 4, i1 * 6 + 2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), board.c % 8 + 1);
            cout << board.c;
        }
        //
    }
    if (board.movesuggest)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        for (int i = 1; i < 4; i++)
        {
            GoToXY(j1 * 13 + 1, i1 * 6 + i);
            cout << "       ";
        }
        GoToXY(j1 * 13 + 4, i1 * 6 + 2);
        cout << board.c;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    }

}
void checkPair(Normal_Board** board, position& pos, position selectedPos[2], int& pair, players& user)
{
    if (pair == 2)
    {
        if (CheckOverall(board, selectedPos[0], selectedPos[1]))
        {
            // Ref sound: https://pixabay.com/sound-effects/game-start-6104/
            PlaySound(TEXT("Bingo.wav"), NULL, SND_FILENAME | SND_ASYNC);
            user.point += 50;
            GoToXY(45, 2);
            SetColor(11);
            cout << "Points:" << user.point;
            drawBox(board[selectedPos[0].x][selectedPos[0].y], 80);
            Sleep(300);
            drawBox(board[selectedPos[1].x][selectedPos[1].y], 80);
            Sleep(300);
            board[selectedPos[0].x][selectedPos[0].y].c = ' ';
            board[selectedPos[1].x][selectedPos[1].y].c = ' ';
            clear = 1;
        }
        else
        {
            user.life--;
            SetColor(11);
            GoToXY(25, 2);
            cout << "Life:" << user.life;
        }
        board[selectedPos[0].x][selectedPos[0].y].Is_Chosen = 0;
        board[selectedPos[1].x][selectedPos[1].y].Is_Chosen = 0;
        board[selectedPos[0].x][selectedPos[0].y].Is_Selected = 0;
        board[selectedPos[1].x][selectedPos[1].y].Is_Selected = 0;
        // After finshing find a pair, set temp pair is -1 
        selectedPos[0] = { -1, -1 };
        selectedPos[1] = { -1, -1 };
        pair = 0;
    }
    
    else return;
}

void moveCursor(Normal_Board** board, position& pos, position selectedPos[], int& pair, players& user, int& FlagCheckExit, int&help)
{ 
    int funckey;
    funckey = _getch();
   
    if (funckey == ESC)
    {
        FlagCheckExit = -1; // Mark flag exit game 
        stop = 1;
        return; 
    }
    if (funckey == TAB && help > 0) // Use help 2 times
    {
        position pos1 = { -1, -1 };
        position pos2 = { -1, -1 };
        HelpSuggestion(board, pos1, pos2);
        GoToXY(10, 0);
        //cout << pos1.x << pos1.y << pos2.x << pos2.y << endl;
        help--;
        GoToXY(65, 2);
        SetColor(11);
        cout << "Help:" << help;
        if (pos1.x != -1 && pos1.y != -1 && pos2.x != -1 && pos2.y != -1)
        {
            board[pos1.x][pos1.y].movesuggest = 1;
            board[pos2.x][pos2.y].movesuggest = 1;
            drawBox(board[pos1.x][pos1.y], 112);
            Sleep(300);
            drawBox(board[pos2.x][pos2.y], 112);
            Sleep(300);
            board[pos1.x][pos1.y].movesuggest = 0;
            board[pos2.x][pos2.y].movesuggest = 0;
            pos1 = { -1, -1 };
            pos2 = { -1, -1 };

        }
        return;
    }
    if (funckey == Enter   && !board[pos.x][pos.y].Is_Chosen) // The point is entered but no ever chosen
    {
        selectedPos[pair].x = pos.x;
        selectedPos[pair].y = pos.y;
        pair++;
        board[pos.x][pos.y].Is_Chosen = 1;
        return;
    }
    else {
        if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)) 
            board[pos.x][pos.y].Is_Selected = 0;
        // Tranversing the board by entering the key and save the pos
        switch (funckey)
        {
        case UP:
            for (int i = pos.y; i < BOARDWIDTH; i++)
            {   //Check tu o phia tren o hien tai cho toi o tren cung, neu tim duoc o hop le thi gan dia chi vao pos
                for (int j = pos.x - 1; j >= 0; j--)
                {   //Neu khong co o hop le trong cot, chuyen sang check tiep cot ben phai cho toi cot cuoi cung
                    if (board[j][i].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = i;
                        pos.x = j;
                        return;
                    }
                }
            }

            for (int i = pos.y - 1; i >= 0; i--)
            {      //Check tu o phia tren o hien tai cho toi o tren cung, neu tim duoc o hop le thi gan dia chi vao pos
                for (int j = pos.x - 1; j >= 0; j--)
                {  //Neu khong co o hop le trong cot, chuyen sang check tiep cot ben trai cho toi cot dau tien
                    if (board[j][i].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = i;
                        pos.x = j;
                        return;
                    }
                }
            }

            for (int i = pos.y; i < BOARDWIDTH; i++)
            {              //Check tu o duoi cung cua cot tro len cho toi o hien tai, neu tim duoc o hop le thi gan dia chi vao pos
                for (int j = BOARDHEIGTH - 1; j > pos.x; j--)
                {     //Neu ko co o hop le trong cot, chuyen sang cot ben trai
                    if (board[j][i].c != ' ')
                    {
                        // Ref sound:https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = i;
                        pos.x = j;
                        return;
                    }
                }
            }

            for (int i = pos.y; i >= 0; i--)
            {
                for (int j = BOARDHEIGTH - 1; j > pos.x; j--)
                {
                    if (board[j][i].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = i;
                        pos.x = j;
                        return;
                    }
                }
            }

            break;
        case DOWN:
            for (int i = pos.y; i < BOARDWIDTH; i++)
            {
                for (int j = pos.x + 1; j < BOARDHEIGTH; j++)
                {
                    if (board[j][i].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = i;
                        pos.x = j;
                        return;
                    }
                }
            }

            for (int i = pos.y - 1; i >= 0; i--)
            {
                for (int j = pos.x + 1; j < BOARDHEIGTH; j++)
                {
                    if (board[j][i].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = i;
                        pos.x = j;
                        return;
                    }
                }
            }

            for (int i = pos.y; i < BOARDWIDTH; i++)
            {
                for (int j = 0; j < pos.x; j++)
                {
                    if (board[j][i].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = i;
                        pos.x = j;
                        return;
                    }
                }
            }

            for (int i = pos.y - 1; i >= 0; i--)
            {
                for (int j = 0; j < pos.x; j++)
                {
                    if (board[j][i].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = i;
                        pos.x = j;
                        return;
                    }
                }
            }
            break;
        case LEFT:
            for (int i = pos.x; i >= 0; i--)
            {
                for (int j = pos.y - 1; j >= 0; j--)
                {
                    if (board[i][j].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = j;
                        pos.x = i;
                        return;
                    }
                }
            }

            for (int i = pos.x + 1; i < BOARDHEIGTH; i++)
            {
                for (int j = pos.y - 1; j >= 0; j--)
                {
                    if (board[i][j].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = j;
                        pos.x = i;
                        return;
                    }
                }
            }

            for (int i = pos.x; i >= 0; i--)
            {
                for (int j = BOARDWIDTH - 1; j > pos.y; j--)
                {
                    if (board[i][j].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = j;
                        pos.x = i;
                        return;
                    }
                }
            }

            for (int i = pos.x + 1; i < BOARDHEIGTH; i++)
            {
                for (int j = BOARDWIDTH - 1; j > pos.y; j--)
                {
                    if (board[i][j].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = j;
                        pos.x = i;
                        return;
                    }
                }
            }
            break;
        case RIGHT:
            for (int i = pos.x; i >= 0; i--)
            {
                for (int j = pos.y + 1; j < BOARDWIDTH; j++)
                {
                    if (board[i][j].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = j;
                        pos.x = i;
                        return;
                    }
                }
            }

            for (int i = pos.x + 1; i < BOARDHEIGTH; i++)
            {
                for (int j = pos.y + 1; j < BOARDWIDTH; j++)
                {
                    if (board[i][j].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = j;
                        pos.x = i;
                        return;
                    }
                }
            }

            for (int i = pos.x; i >= 0; i--)
            {
                for (int j = 0; j < pos.y; j++)
                {
                    if (board[i][j].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = j;
                        pos.x = i;
                        return;
                    }
                }
            }

            for (int i = pos.x + 1; i < BOARDHEIGTH; i++)
            {
                for (int j = 0; j < pos.y; j++)
                {
                    if (board[i][j].c != ' ')
                    {
                        // Ref sound: https://pixabay.com/sound-effects/one-beep-99630/
                        PlaySound(TEXT("Choiceoption.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        pos.y = j;
                        pos.x = i;
                        return;
                    }
                }
            }
        default:
            break;
        }
    }
}
void DrawNormalMap(Normal_Board** board, int color)
{
    for (int i = 0; i < BOARDHEIGTH; i++)
    {
        for (int j = 0; j < BOARDWIDTH; j++)
        {
            drawBox(board[i][j], color);
        }
    }
}
// 

void printClock()
{
    Hour h = { 2,0 }; // Set time countdown 
    char a[5] = { '0','0',':','0','0' };
    while (!stop)
    {
        if (!changetime(&h)) stop = 1;
        insertarray(a, &h);
        WriteBlockChar(a, 1, 5, 85, 1, 0x004 | 0x060);
        Sleep(970);
    }
    return;
}
void close(DWORD evt)
{
    if (evt == CTRL_CLOSE_EVENT) stop = 1;
}
void NormalMap(players& player)
{
        int line = 30;
        string* ptr = new string[line]; // Allocate for background
        int Help = 2;
        BackGround(ptr,line,"BG.txt");
        ClearScreen();
        Normal_Board** board = new Normal_Board * [BOARDHEIGTH];
        InitBoard(board);
        char c;
        int FlagCheckExit = 0;
        position selectedPos[2] = { {-1, -1}, {-1, -1} };
        position CurPos;
        CurPos.x = 0;
        CurPos.y = 0;
        int pair = 0;
        int FlagCheckWin = 0;
        bool FlagMoveExist = true;
        int flag = 0;
        // Starting countdown
        SetConsoleCtrlHandler((PHANDLER_ROUTINE)close, TRUE);
        thread clock;
        clock = thread(printClock);
        ClearScreen();
        // Thread run independently from function, so when thread run completed then out function 
        // Game is processing, update the screen 
        while (player.life >= 0 && FlagCheckExit >= 0 && FlagCheckWin == 0 && FlagMoveExist && stop == 0)
        {
            // Print BackGround 
            if (clear || !flag)
            {
                ClearScreen();
                int y = 8;
                for (int i = 0; i < line; i++)
                {
                    SetColor(15);
                    GoToXY(35, y);
                    cout << ptr[i] << endl;
                    y++;
                }
                clear = 0;
            }
            SetColor(11);
            GoToXY(5, 2);
            cout << "Player:" << player.name;
            GoToXY(25, 2);
            cout << "Life:" << player.life;
            GoToXY(45, 2);
            cout << "Points:" << player.point;
            GoToXY(65, 2);
            cout << "Help:" << Help;
            GoToXY(85, 2);
            cout << "Normal Mode";
            GoToXY(30, 30);
            cout << "Press ESC to exit";
            GoToXY(30, 32);
            cout << "Press Enter to choose";
            GoToXY(30, 34);
            cout << "Use arrow keys to move";
            GoToXY(30, 36);
            cout << "Press Tab to get help";
            position pos1 = { -1,-1 };
            position pos2 = { -1, -1 };
            FlagMoveExist = HelpSuggestion(board, pos1, pos2); // Check is move exist 
            FlagCheckWin = CheckWin(board);
            // Check Win
            if (!FlagMoveExist && !FlagCheckWin)
            {
                stop = 1;
                clock.join();
                AuthorWin(player);
                SaveFile("Leaderboard.bin", player);
                stop = 0;
               DeleteBoard(board);
                delete[] ptr;
                ptr = nullptr;
                return; // Out function when no pair valid exist 
            }
            if (CheckWin(board))
            {
                DeleteBoard(board);
                stop = 1;
                clock.join();
                WinBackGround(player);
                SaveFile("Leaderboard.bin", player);
                stop = 0;
                delete[] ptr;
                ptr = nullptr;
                return; // Out function when you win 
            }
            // Cursor points to the box, the box will be lighted
            board[CurPos.x][CurPos.y].Is_Selected = 1;
            DrawNormalMap(board, 112);
            moveCursor(board, CurPos, selectedPos, pair, player, FlagCheckExit, Help);
            checkPair(board, CurPos, selectedPos, pair, player);
            flag++;
        }
        // Check lose 
        if (player.life < 0)
        {
            stop = 1; 
            clock.join();
            DeleteBoard(board);
            LoseBackGround(player);
            SaveFile("Leaderboard.bin", player);
            stop = 0;
            delete[] ptr;
            ptr = nullptr;
            return;
        }
        if (FlagCheckExit == -1) // If user choose esc
        {
            DeleteBoard(board);
            clock.join();
            stop = 0;
            delete[] ptr;
            ptr = nullptr;
            return;
        }
        // When player cannot solve all puzzle in game time
        clock.join();
        DeleteBoard(board);
        EndTimeBackGround(player);
        system("Pause");
        SaveFile("Leaderboard.bin", player);
        stop = 0;
        delete[] ptr;
        ptr = nullptr;
        return;
}