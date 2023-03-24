#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <Windows.h>
#include <cstdlib>
#define BOARDWIDTH 6
#define BOARDHEIGTH 4
using namespace std; 
// x la hang, y la cot                   
struct position                            
{											
	int x; // Toa do hang					
	int y; // Toa do cot					
};											
struct Cell_1								
{                
	int x, y;
	
	char c = 1;
	// Check Barrier
	bool Is_Selected = 0;

};
void OutputBoard(Cell_1** board, int nRow, int nCol);
void InitBoard(Cell_1** board);
void DeleteBoard(Cell_1** board);
bool Colcheck(Cell_1** board, int x1, int x2, int y);
bool RowCheck(Cell_1** board, int y1, int y2, int x);
bool LCheck(Cell_1** board, int x1, int xMin, int xMax, int  yMin, int yMax);
bool Zcheck(Cell_1** board, int x1, int x2, int y1, int y2);
