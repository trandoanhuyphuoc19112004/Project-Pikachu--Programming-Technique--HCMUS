#pragma once
#include "InterfaceMenu_1.h"
#include "Players.h"
#include "CheckHard.h"
#include "CheckNormal.h"
// Hard Map Z
void DrawHardMap(Hard_Board** board);
void drawBoxZ(Hard_Board board);
void moveCursorZ(Hard_Board** board, position& pos, position selectedPos[], int& pair, players& user, int& FlagCheckExit);
void HardMap(players& player);
void removeBox(int x, int y);
void checkPairZ(Hard_Board** board, position& pos, position selectedPos[2], int& pair, players& user);
bool checkWin(Hard_Board** board);
// Hard Map Y 
void deleteBoxY(Normal_Board** board, int x, int y);
void checkPairY(Normal_Board** board, position& pos, position selectedPos[2], int& pair, players& user);
void HardMapY(players& player);