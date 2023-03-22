#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <Windows.h>
#include <cstdlib>
#define BOARDWIDTH 4
#define BOARDHEIGTH 6
using namespace std; 
struct position
{
	int x, y;
};
struct Cell_1
{
	//int i, j;
	//char c = ' ';
	char c;
	// Check Identify
	bool Is_Valid = 1, Is_Selected = 0;
};
void Init_Board(Cell_1** board);
void Output_Board(Cell_1** board);
void Delete_Board(Cell_1** board);
bool Next_Check(Cell_1** board, position pos_1, position pos_2);
bool Z_Check(Cell_1** board, position pos_1, position pos_2);