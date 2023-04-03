#pragma once
#include "InterfaceMenu_1.h"
#include "Players.h"
#include "CheckHard.h"
#include "CheckNormal.h"

void DrawHardMapZ(Hard_Board** board);
void drawBoxZ(Hard_Board board);
void moveCursorZ(Hard_Board** board, position& pos, position selectedPos[], int& pair, players& user, int& FlagCheckExit, int& help);
void HardMap(players& player, int& FlagCheckExit);