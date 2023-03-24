#include "Header.h"
int main()
{
	position pos1;
	position pos2;
	Cell_1** Board = new Cell_1 * [BOARDHEIGTH + 2];
	InitBoard(Board);
	do
	{
		OutputBoard(Board, BOARDHEIGTH + 2 , BOARDWIDTH + 2 );
		cin >> pos1.x >> pos1.y;
		cin >> pos2.x >> pos2.y;
		ConverToNull(Board, pos1.x, pos2.x, pos1.y, pos2.y);
	} while (!CheckEndGame(Board, BOARDHEIGTH + 2, BOARDWIDTH + 2));
	DeleteBoard(Board);
}