#include "Header.h"
void InitBoard(Cell_1** board)
{
	// Initializing 2d pointer array
	for (int i = 0; i < BOARDHEIGTH + 2 ; i++)
	{
		board[i] = new Cell_1[BOARDWIDTH + 2 ];
		for (int j = 0; j < BOARDWIDTH  + 2; j++)
		{
			board[i][j].x = i;
			board[i][j].y = j;
		}
	}
	
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
			//int idx = rand() % 24;
			int row = rand() % BOARDHEIGTH + 1 ;
			int col = rand() % BOARDWIDTH + 1 ;
			if (board[row][col].c == 1)
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
bool RowCheck(Cell_1** board, int ymin, int ymax, int x)
{
		for (int i = ymin + 1; i < ymax; i++)
		{
			if (board[x][i].c != 1)
				return false;
		}
	return true;
}
bool Colcheck(Cell_1** board, int xmin, int xmax, int y)
{

	for (int i = xmin + 1; i < xmax; i++)
	{
		if (board[i][y].c != 1)
			return false;
	}
	return true;
}
bool LCheck(Cell_1 **board, int xMin, int xMax, int  yMin, int yMax)
{
	
	if (RowCheck(board, yMin, yMax + 1, xMin) && Colcheck(board, xMin - 1, xMax, yMax)) return true;
	if (Colcheck(board, xMin, xMax + 1, yMin) && RowCheck(board, yMin - 1, yMax, xMax)) return true;
	return false;
}
/*
bool Ucheck(Cell_1** board, int xMin, int xMax, int yMin, int yMax)
{
	if (RowCheck(board,		) && Colcheck() && RowCheck())
		return true;
	if (Colcheck(board, yMin, yMax, xMin ) && RowCheck(board, yMin - 1, yMax + 1, xMax) && Colcheck(board, xMax - 1, xMin , yMax))
		return true;
}
*/
bool Zcheck(Cell_1 **board, int xMin, int xMax, int yMin, int yMax) 
{
	for (int i = yMin - 1; i < yMax; i++) {
		if (RowCheck(board, yMin, i, xMin) && Colcheck(board, xMin - 1, xMax + 1, i) && RowCheck(board, i - 1, yMax, xMax)) return true;
		if (Colcheck(board, xMin, i, yMin) && RowCheck(board, yMin - 1, yMax + 1, i) && Colcheck(board, i - 1, xMax, yMax)) return true;
		else continue;
	}
	return false;
}
bool CheckOverall(Cell_1** board, int x1, int x2, int y1, int y2)
{
	int xMin, yMin, xMax, yMax;
	if (x1 > x2) {
		xMin = x2;
		xMax = x1;
	}
	else
		if (x2 > x1)
		{
			xMin = x1;
			xMax = x2;
		}
	if (y1 > y2)
	{
		yMin = y2;
		yMax = y1;
	}
	else
		if (y2 > y1)
		{
			yMin = y1;
			yMax = y2;
		}
	if (y1 == y2)
	{
		if (Colcheck(board, xMin, xMax, y1))
		return true;
	}
	if (x1 == x2)
	{
		if (RowCheck(board, yMin, yMax, x1))
			return true;
	}
	
	if (LCheck(board, xMin, xMax, yMin, yMax))
		return true;
	if (Zcheck(board, xMin, xMax, yMin, yMax))
		return true;
	return false;
	
}
void ConverToNull(Cell_1** board, int x1, int x2, int y1, int y2)
{
	if (CheckOverall(board, x1, x2, y1, y2))
	{
		board[x1][y1].c = 1;
		board[x2][y2].c = 1;
	}
}
bool CheckEndGame(Cell_1** board, int nRow, int nCol)
{
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			if (board[i][j].c != 1)
			{
				return false;
			}
		}
	}
	return true;
	
}