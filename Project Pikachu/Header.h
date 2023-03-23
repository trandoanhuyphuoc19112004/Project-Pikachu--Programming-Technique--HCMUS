#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <Windows.h>
#include <cstdlib>
#define BOARDWIDTH 4
#define BOARDHEIGTH 6
using namespace std; 
// x la hang, y la cot 
struct position
{
	int x; // Toa do hang 
	int y; // Toa do cot 
};
struct Cell_1
{
	//int i, j;
	//char c = ' ';
	char c;
	// Check Barrier
	bool Barrier = true, Is_Selected = 0;
};
void InitBoard(Cell_1** board);
void OutputBoard(Cell_1** board);
void DeleteBoard(Cell_1** board);
bool Colcheck(Cell_1** board, int x1, int x2, int y);
bool RowCheck(Cell_1** board, int y1, int y2, int x);
bool Zcheck(Cell_1** board, int x1, int x2, int y1, int y2);
