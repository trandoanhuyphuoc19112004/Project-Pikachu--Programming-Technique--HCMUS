#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "Struct.h"
void InitBoard(Normal_Board** board);
void DeleteBoard(Normal_Board** board);
bool colCheck(Normal_Board** board, int xmin, int xmax, int y);
bool rowCheck(Normal_Board** board, int ymin, int ymax, int x);
bool LCheck(Normal_Board** board, int xMin, int xMax, int  yMin, int yMax);
bool Zcheck(Normal_Board** board, int xMin, int xMax, int yMin, int yMax);
bool Ucheck(Normal_Board** board, int xMin, int xMax, int yMin, int yMax);
bool CheckOverall(Normal_Board** board, position pos1, position pos2);
bool canConnect(Normal_Board** board, int x1, int x2, int y1, int y2);
bool CheckWin(Normal_Board** board);
bool HelpSuggestion(Normal_Board** board, position& pos1, position& pos2);