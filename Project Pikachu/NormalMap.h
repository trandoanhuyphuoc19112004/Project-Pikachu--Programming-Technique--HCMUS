#pragma once
#include "InterfaceMenu_1.h"
#include "Players.h"
#include "CheckNormal.h"
#include <conio.h>
void DrawNormalMap(Normal_Board** board, int color);
void NormalMap(players &player);
void drawBox(Normal_Board board, int color);
void moveCursor(Normal_Board** board, position& pos, position selectedPos[], int& pair, players& user, int& FlagCheckExit, int& help);
void checkPair(Normal_Board** board, position& pos, position selectedPos[2], int& pair, players& user);