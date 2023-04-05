#include"CheckHard.h"
#include"HardMap.h"
#include"EndingBackground.h"
#include"Struct.h"

char boxZ[5][10] = { {" ------- "},
                    {"|       |"},
                    {"|       |"},
                    {"|       |"},
                    {" ------- "} };

char deleteboxZ[5][10] = { {"         "},
                          {"         "},
                          {"         "},
                          {"         "},
                          {"         "} };

void HardMap(players& player)
{
    system("cls");
    Hard_Board** board = new Hard_Board * [BOARDHEIGTH];
    initBoardZ(board);
    char c;
    SetColor(11);
    GoToXY(10, 2);
    cout << "Player:" << player.name;
    GoToXY(35, 2);
    cout << "Life:" << player.life;
    GoToXY(55, 2);
    cout << "Points:" << player.point;
    GoToXY(80, 2);
    cout << "Normal Mode";
    GoToXY(30, 32);
    cout << "Press ESC to exit";
    GoToXY(30, 34);
    cout << "Press Enter to choose";
    GoToXY(30, 36);
    cout << "Use arrow keys to move";
    position selectedPos[] = { {-1, -1}, {-1, -1} };
    position curPosition{ 0, 0 };
    int pair = 0;
    int Is_Game = 1;
    do
    {
        if (player.life < 0)
        {
            Is_Game = LoseBackGround(player);
            return;
        }

        board[curPosition.x][curPosition.y].Is_Selected = 1;
        DrawHardMap(board);
        moveCursorZ(board, curPosition, selectedPos, pair, player);
        checkPairZ(board, curPosition, selectedPos, pair, player);
    } while (true);
    return;
}

void DrawHardMap(Hard_Board** board)
{
    for (int i = 0; i < BOARDHEIGTH; i++)
    {
        Hard_Board* temp = board[i];
        while (temp != NULL)
        {
            drawBoxZ(*temp);
            temp = temp->next;
        }
    }
}

void drawBoxZ(Hard_Board board)
{
    // Draw Box
    SetColor(11);
    int i1 = board.i + 1, j1 = board.j + 1;
    if (board.c != ' ') {
        for (int i = 0; i < 6; i++)
        {
            GoToXY(j1 * 13, i1 * 6 + i);
            cout << boxZ[i];
        }
        if (board.Is_Selected || board.Is_Chosen)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + (board.c % 6 + 1));
            for (int i = 1; i < 4; i++)
            {
                GoToXY(j1 * 13 + 1, i1 * 6 + i);
                cout << "       ";
            }
            GoToXY(j1 * 13 + 4, i1 * 6 + 2);
            cout << board.c;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        // Add letter to the box
        else
        {
            GoToXY(j1 * 13 + 4, i1 * 6 + 2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), board.c % 4 + 1);
            cout << board.c;
        }
        //
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            GoToXY(j1 * 13, i1 * 6 + i);
            cout << deleteboxZ[i];
        }
    }
}

void removeBox(int x, int y) {
    for (int i = 0; i < 6; i++)
    {
        GoToXY(y * 13, x * 6 + i);
        cout << deleteboxZ[i];
    }
}

void moveCursorZ(Hard_Board** board, position& pos, position selectedPos[], int& pair, players& user)
{
    int funckey;
    funckey = _getch();
    Hard_Board* tmp = findNode(board, pos.x, pos.y);
    if (funckey == Enter && !tmp->Is_Chosen)
    {
        selectedPos[pair].x = pos.x;
        selectedPos[pair].y = pos.y;
        pair++;
        tmp->Is_Chosen = 1;
        return;
    }
    else {
        if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)) // ktra xem o nay co dang duoc chon hay khong
            tmp->Is_Selected = 0;
        // Tranversing the board by entering the key and save the pos
        switch (funckey)
        {
        case UP:
            for (int i = pos.y; i < BOARDWIDTH; i++)
            {   //Check tu o phia tren o hien tai cho toi o tren cung, neu tim duoc o hop le thi gan dia chi vao pos
                for (int j = pos.x - 1; j >= 0; j--)
                {   //Neu khong co o hop le trong cot, chuyen sang check tiep cot ben phai cho toi cot cuoi cung
                    if (findNode(board, j, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, j, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, j, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, j, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, j, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, j, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, j, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, j, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, i, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, i, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, i, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, i, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, i, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, i, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, i, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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
                    if (findNode(board, i, i) != NULL)
                    {
                        // Ref sound: https://www.pond5.com/sound-effects/item/57740945-old-school-video-game-efx
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

void checkPairZ(Hard_Board** board, position& pos, position selectedPos[2], int& pair, players& user) {
    if (pair == 2) {
        if (checkOverallZ(board, selectedPos[0], selectedPos[1]))
        {
            // Ref sound: https://pixabay.com/sound-effects/game-start-6104/
            PlaySound(TEXT("Bingo.wav"), NULL, SND_FILENAME | SND_ASYNC);
            user.point += 50;
            GoToXY(55, 2);
            SetColor(11);
            cout << "Points:" << user.point;
            deleteNode(board, selectedPos[0].x, selectedPos[0].y);
            deleteNode(board, selectedPos[1].x, selectedPos[1].y);
        }
        else
        {
            user.life--;
            SetColor(11);
            GoToXY(35, 2);
            cout << "Life:" << user.life;
        }
        Hard_Board* tmp1 = findNode(board, selectedPos[0].x, selectedPos[0].y);
        Hard_Board* tmp2 = findNode(board, selectedPos[1].x, selectedPos[1].y);
        tmp1->Is_Chosen = 0;
        tmp2->Is_Chosen = 0;
        tmp1->Is_Selected = 0;
        tmp2->Is_Selected = 0;
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