#include "Header.h"
int main()
{
	position pos1;
	position pos2;
	Cell_1** Board = new Cell_1 * [BOARDHEIGTH * BOARDWIDTH];
	InitBoard(Board);
	OutputBoard(Board);
	cin >> pos1.x >> pos1.y;
	cin >> pos2.x >> pos2.y;
	cout << LineCheck(Board, pos1, pos2);
	//cout << Next_Check(Board, pos1, pos2);
	// Check doc duoc	
	DeleteBoard(Board);
}