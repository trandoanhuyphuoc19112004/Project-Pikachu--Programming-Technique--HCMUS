#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#define BOARDWIDTH 6
#define BOARDHEIGTH 4
using namespace std; 
// x la hang, y la cot                   
struct position                            
{											
	int x; 			
	int y; 				
};											
struct Normal_Board								
{                
	int i, j;
	char c = ' ';
	bool Is_Selected = 0;
	bool isValid = 1;
};
void InitBoard(Normal_Board** board);
void OutputBoard(Normal_Board** board, int nRow, int nCol);
void DeleteBoard(Normal_Board** board);
bool Colcheck(Normal_Board** board, int xmin, int xmax, int y);
bool RowCheck(Normal_Board** board, int ymin, int ymax, int x);
bool LCheck(Normal_Board** board, int xMin, int xMax, int  yMin, int yMax);
bool Zcheck(Normal_Board** board, int xMin, int xMax, int yMin, int yMax);
bool Ucheck(Normal_Board** board, int xMin, int xMax, int yMin, int yMax, int R, int C);
bool CheckOverall(Normal_Board** board, int x1, int x2, int y1, int y2, int nRow, int nCol);
void ConverToNull(Normal_Board** board, int x1, int x2, int y1, int y2, int nRow, int nCol);
bool CheckEndGame(Normal_Board** board, int nRow, int nCol);
