#include "Header.h"
int main()
{
	position pos1;
	position pos2;
	Cell_1** Board = new Cell_1 * [BOARDHEIGTH + 2];
	InitBoard(Board);
	OutputBoard(Board, BOARDHEIGTH + 2 , BOARDWIDTH + 2);
	cin >> pos1.x >> pos1.y;
	cin >> pos2.x >> pos2.y;
	if ((RowCheck(Board, pos1.y, pos2.y, pos1.x) ) || Colcheck(Board, pos1.x, pos2.x, pos1.y) || Zcheck(Board, pos1.x, pos2.x, pos1.y, pos2.y))
		cout << "True" << endl;
	else cout << "False" << endl;
	DeleteBoard(Board);
}