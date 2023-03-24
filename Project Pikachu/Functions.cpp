#include "Header.h"
void InitBoard(Cell_1** board)
{
	// Initializing 2d pointer array
	for (int i = 0; i < BOARDHEIGTH + 2; i++)
	{
		board[i] = new Cell_1[BOARDWIDTH + 2];
	}
	//board[BOARDHEIGTH][BOARDWIDTH].c = '\0';
	
	for (int i = 0; i <= BOARDHEIGTH + 1; i++)
	{
		board[i][0].c = '\0';
		board[i][BOARDWIDTH + 1].c = '\0';
	}
	for (int i = 0; i <= BOARDWIDTH + 1; i++)
	{
		board[BOARDHEIGTH + 1][i].c = '\0';
		board[0][i].c = '\0';
	}
	

	
	// Attach values randomly to each elements
	
	srand((char)time(NULL));
	int num = (BOARDHEIGTH * BOARDWIDTH) / 2;
	
	while (num)
	{
		// Random Uppercase Letter
		char random_c;
		random_c = 65 + rand() % 26;
		int  time = 2;
		// Insert the letter to random indexes
		while (time)
		{
			int row = rand() % BOARDHEIGTH + 1;
			int col = rand() % BOARDWIDTH + 1 ;
			if (board[row][col].c == -51)
			{
				board[row][col].c = random_c;
				time--;
			}
		}
		num--;
	}
	
}
void OutputBoard (Cell_1** board, int nRow, int nCol)
{
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			cout << board[i][j].c << " ";
		}
		cout << endl;
	}
}
void DeleteBoard (Cell_1** board)
{
	for (int i = 0; i < BOARDHEIGTH; i++)
		delete[] board[i];
	delete[] board;
}
// Check cot + dong 
bool RowCheck(Cell_1** board, int y1, int y2, int x)
{
	int min, max;
	{
		if (y1 > y2)
		{
			min = y2;
			max = y1;
		}
		else
		{
			min = y1;
			max = y2;
		}
		for (int i = min + 1; i < max; i++)
		{
			if (board[x][i].c != '\0')
				return false;
		}
	}
	return true;
}
bool Colcheck(Cell_1** board, int x1, int x2, int y)
{
	int min, max;
	if (x1 > x2)
	{
		min = x2;
		max = x1;
	}
	else
	{
		min = x1;
		max = x2;
	}
	for (int i = min + 1; i < max; i++)
	{
		if (board[i][y].c != '\0')
			return false;
	}
	return true;
}
bool Zcheck(Cell_1 **board, int x1, int x2, int y1, int y2) 
{
	int xMin, yMin, xMax, yMax;
	if (x1 > x2) {
		xMin = x2;
		xMax = x1;
	}
	else {
		xMin = x1;
		xMax = x2;
	}
	if (y1 > y2) {
		yMin = y2;
		yMax = y1;
	}
	else {
		yMin = y1;
		yMax = y2;
	}
	for (int i = yMin - 1; i < yMax; i++) {
		if (RowCheck(board, yMin, i, xMin) && Colcheck(board, xMin - 1, xMax + 1, i) && RowCheck(board, i - 1, yMax, xMax)) return true;
		if (Colcheck(board, xMin, i, yMin) && RowCheck(board, yMin - 1, yMax + 1, i) && Colcheck(board, i - 1, xMax, yMax)) return true;
		else continue;
	}
	return false;
}

