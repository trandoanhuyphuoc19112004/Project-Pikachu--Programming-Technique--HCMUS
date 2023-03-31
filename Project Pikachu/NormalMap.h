#pragma once
#include "InterfaceMenu_1.h"
#include "Players.h"
#include "CheckNormal.h"
#include <conio.h>
void DrawNormalMap(Normal_Board** board);
void NormalMap(players& player, int &flag);
void drawBox( Normal_Board board);
void DeleteBox(Normal_Board** board, int i, int j);
void moveCursor(Normal_Board** board, position& pos, position selectedPos[], int& pair, players& user, int& flag);
void checkPair(Normal_Board** board, position& pos, position selectedPos[2], int& pair, players& user);