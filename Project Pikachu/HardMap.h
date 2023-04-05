#pragma once
#include "InterfaceMenu_1.h"
#include "Players.h"
#include "CheckHard.h"
#include "CheckNormal.h"

void DrawHardMap(Hard_Board** board);
void drawBoxZ(Hard_Board board);
void moveCursorZ(Hard_Board** board, position& pos, position selectedPos[], int& pair, players& user);
void HardMap(players& player);
void removeBox(int x, int y);
void checkPairZ(Hard_Board** board, position& pos, position selectedPos[2], int& pair, players& user);