#include "Header.h"
int main()
{
	position pos1;
	position pos2;
	Cell_1** Board = new Cell_1 * [BOARDHEIGTH * BOARDWIDTH];
	Init_Board(Board);
	Output_Board(Board);
	//cin >> pos1.x >> pos1.y;
	//cin >> pos2.x >> pos2.y;
	//cout << Next_Check(Board, pos1, pos2);
	Delete_Board(Board);
}