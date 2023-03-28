#pragma once
#include "InterfaceMenu_1.h"
#include "Players.h"
#include "CheckNormal.h"
void DrawNormalMap(Normal_Board** board);
void NormalMap(players& player);
void drawBox( Normal_Board board);
void moveCursor(Normal_Board** board, position& pos, position selectedPos[]);
