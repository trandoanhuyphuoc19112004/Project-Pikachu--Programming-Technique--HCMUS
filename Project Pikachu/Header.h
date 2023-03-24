#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <Windows.h>
#include <cstdlib>
#define BOARDWIDTH 4
#define BOARDHEIGTH 6
using namespace std; 
// x la hang, y la cot                      // 0 0 0 0 0 0
struct position                             // 0 * * * * 0
{											// 0 * * * * 0
	int x; // Toa do hang					// 0 * * * * 0
	int y; // Toa do cot					// 0 * * * * 0
};											// 0 * * * * 0
struct Cell_1								// 0 * * * * 0
{                                           // 0 0 0 0 0 0 
	int i, j;
	//char c = ' ';
	char c;
	// Check Barrier
	bool Is_Selected = 0;

};
void InitBoard(Cell_1** board);
void OutputBoard(Cell_1** board);
void DeleteBoard(Cell_1** board);
bool Colcheck(Cell_1** board, int x1, int x2, int y);
bool RowCheck(Cell_1** board, int y1, int y2, int x);
bool Zcheck(Cell_1** board, int x1, int x2, int y1, int y2);
