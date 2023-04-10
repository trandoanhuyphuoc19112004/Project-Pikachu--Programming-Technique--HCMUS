#include "HardMap.h"
#include "EndingBackground.h"
#include "Clock.h"
#include "NormalMap.h"
#include "CheckNormal.h"
#include "BinIO.h"
int stop_1 = 0;
bool clear_1 = 0;
// CHECK PAIR Y 
void deleteBoxY(Normal_Board** board, int x, int y)
{
    while (y < BOARDWIDTH) {
        if (board[x][y + 1].c == ' ' || y+1==BOARDWIDTH) {
            board[x][y].c = ' ';
            return;
        }
        else {
            board[x][y].c = board[x][y + 1].c;
        }
        y++;
    }
    return;
}

void checkPairY(Normal_Board** board, position& pos, position selectedPos[2], int& pair, players& user)
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
            clear_1 = 1;
            if (selectedPos[0].y < selectedPos[1].y) {
                deleteBoxY(board, selectedPos[1].x, selectedPos[1].y);
                deleteBoxY(board, selectedPos[0].x, selectedPos[0].y);
            }
            else {
                deleteBoxY(board, selectedPos[0].x, selectedPos[0].y);
                deleteBoxY(board, selectedPos[1].x, selectedPos[1].y);
            }
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
        for (int i = pos.x; i < BOARDHEIGTH; i++)
        {
            for (int j = pos.y; j < BOARDWIDTH; j++)
            {
                if (board[i][j].c != ' ')
                {
                    pos.y = j;
                    pos.x = i;
                    return;
                }
            }
        }
        for (int i = 0; i <= pos.x; i++)
        {
            for (int j = 0; j <= pos.y; j++)
            {
                if (board[i][j].c != ' ')
                {
                    pos.y = j;
                    pos.x = i;
                    return;
                }
            }
        }
    }
    else return;
}
void printClockY()
{
    Hour h = { 0,60 }; // Set time countdown 
    char a[5] = { '0','0',':','0','0' };
    while (!stop_1)
    {
        if (!changetime(&h)) stop_1 = 1;
        insertarray(a, &h);
        WriteBlockChar(a, 1, 5, 85, 1, 0x004 | 0x060);
        Sleep(970);
    }
    return;
}
void close_1(DWORD evt)
{
    if (evt == CTRL_CLOSE_EVENT) stop_1 = 1;
}
void HardMapY(players& player)
{
    int line = 30;
    string* ptr = new string[line]; // Allocate for background
    int Help = 2;
    BackGround(ptr, line, "BG.txt");
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
    clock = thread(printClockY);
    ClearScreen();
    // Thread run independently from function, so when thread run completed then out function 
    // Game is processing, update the screen 
    while (player.life >= 0 && FlagCheckExit >= 0 && FlagCheckWin == 0 && FlagMoveExist && stop_1 == 0)
    {
        // Print BackGround 
        if (clear_1 || !flag)
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
            clear_1 = 0;
        }
        char c;
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
        cout << "Hard Mode";
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
        if (!FlagMoveExist)
        {
            DeleteBoard(board);
            stop_1 = 1;
            WinBackGround(player);
            SaveFile("Leaderboard.bin", player);
            stop_1 = 0;
            delete[] ptr;
            ptr = nullptr;
            return; // Out function when no pair valid exist 
        }
        FlagCheckWin = CheckWin(board);
        // Check Win
        if (CheckWin(board))
        {
            DeleteBoard(board);
            stop_1 = 1;
            clock.join();
            WinBackGround(player);
            SaveFile("Leaderboard.bin", player);
            stop_1 = 0;
            delete[] ptr;
            ptr = nullptr;
            return; // Out function when you win 
        }
        // Cursor points to the box, the box will be lighted
        board[CurPos.x][CurPos.y].Is_Selected = 1;
        DrawNormalMap(board, 112);
        moveCursor(board, CurPos, selectedPos, pair, player, FlagCheckExit, Help);
        checkPairY(board, CurPos, selectedPos, pair, player);
        flag++;
    }
    // Check lose 
    if (player.life < 0)
    {
        stop_1 = 1;
        clock.join();
        DeleteBoard(board);
        LoseBackGround(player);
        SaveFile("Leaderboard.bin", player);
        stop_1 = 0;
        delete[] ptr;
        ptr = nullptr;
        return;
    }
    if (FlagCheckExit == -1) // If user choose esc
    {
        stop_1 = 1; 
        DeleteBoard(board);
        clock.join();
        stop_1 = 0;
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
    stop_1 = 0;
    delete[] ptr;
    ptr = nullptr;
    return;
}

