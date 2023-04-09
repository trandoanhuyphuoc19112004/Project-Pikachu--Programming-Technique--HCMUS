#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "Struct.h"

using namespace std;

void push(Hard_Board*& head, Hard_Board* data);
Hard_Board* findNode(Hard_Board** board, int x, int y);
void initBoardZ(Hard_Board** board);
bool rowCheckZ(Hard_Board** board, int yMin, int yMax, int x);
bool colCheckZ(Hard_Board** board, int xMin, int xMax, int y);
bool lCheckZ(Hard_Board** board, int x1, int x2, int y1, int y2);
bool zCheckZ(Hard_Board** board, int x1, int x2, int y1, int y2);
bool uCheckZ(Hard_Board** board, int x1, int x2, int y1, int y2);
bool canConnectZ(Hard_Board** board, int x1, int x2, int y1, int y2);
void deleteNode(Hard_Board** board, int x, int y);
bool checkOverallZ(Hard_Board** board, position p1, position p2);
void deleteBoardZ(Hard_Board** board);