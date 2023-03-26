#include "CheckNormal.h"
void InitBoard(Normal_Board** board)
{
	// Initializing 2d pointer array
	for (int i = 0; i < BOARDHEIGTH + 2 ; i++)
	{
		board[i] = new Normal_Board [BOARDWIDTH + 2 ];
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
void OutputBoard(Normal_Board** board, int nRow, int nCol)
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
void DeleteBoard(Normal_Board** board)
{
	for (int i = 0; i < BOARDHEIGTH; i++)
		delete[] board[i];
	delete[] board;
}
// Check cot + dong 
bool RowCheck(Normal_Board** board, int ymin, int ymax, int x)
{
	for (int i = ymin + 1; i < ymax; i++)
	{
		if (board[x][i].c != 1)
			return false;
	}
	return true;
}
bool Colcheck(Normal_Board** board, int xmin, int xmax, int y)
{
	for (int i = xmin + 1; i < xmax; i++)
	{
		if (board[i][y].c != 1)
			return false;
	}
	return true;
}
bool LCheck(Normal_Board** board, int xMin, int xMax, int  yMin, int yMax)
{
	if (RowCheck(board, yMin, yMax + 1, xMin) && Colcheck(board, xMin - 1, xMax, yMax)) return true;
	if (Colcheck(board, xMin, xMax + 1, yMin) && RowCheck(board, yMin - 1, yMax, xMax)) return true;
	return false;
}
bool Ucheck(Normal_Board** board, int xMin, int xMax, int yMin, int yMax, int R, int C) 
{
	for (int i = yMax + 1; i < C; i++) {
		if (RowCheck(board, yMax, i + 1, xMin) && RowCheck(board, yMin, i + 1, xMax) && Colcheck(board, xMin - 1, xMax + 1, i)) return true;
		if (RowCheck(board, yMin, i + 1, xMin) && RowCheck(board, yMax, i + 1, xMax) && Colcheck(board, xMin - 1, xMax + 1, i)) return true;
	}
	for (int i = yMin - 1; i >= 0; i--) {
		if (RowCheck(board, i - 1, yMin, xMin) && RowCheck(board, i - 1, yMax, xMax) && Colcheck(board, xMin - 1, xMax + 1, i)) return true;
		if (RowCheck(board, i - 1, yMin, xMax) && RowCheck(board, i - 1, yMax, xMin) && Colcheck(board, xMin - 1, xMax + 1, i)) return true;
	}
	for (int i = xMax + 1; i < R; i++) {
		if (Colcheck(board, xMin, i + 1, yMin) && Colcheck(board, xMax, i + 1, yMax) && RowCheck(board, yMin - 1, yMax + 1, i)) return true;
		if (Colcheck(board, xMin, i + 1, yMax) && Colcheck(board, xMax, i + 1, yMin) && RowCheck(board, yMin - 1, yMax + 1, i)) return true;
	}
	for (int i = xMin - 1; i >= 0; i--) {
		if (Colcheck(board, i - 1, xMin, yMin) && Colcheck(board, i - 1, xMax, yMax) && RowCheck(board, yMin - 1, yMax + 1, i)) return true;
		if (Colcheck(board, i - 1, xMin, yMax) && Colcheck(board, i - 1, xMax, yMin) && RowCheck(board, yMin - 1, yMax + 1, i)) return true;
	}
	return false;
}

bool Zcheck(Normal_Board** board, int xMin, int xMax, int yMin, int yMax)
{
	for (int i = yMin - 1; i < yMax; i++) {
		if (RowCheck(board, yMin, i, xMin) && Colcheck(board, xMin - 1, xMax + 1, i) && RowCheck(board, i - 1, yMax, xMax)) return true;
		if (Colcheck(board, xMin, i, yMin) && RowCheck(board, yMin - 1, yMax + 1, i) && Colcheck(board, i - 1, xMax, yMax)) return true;
		else continue;
	}
	return false;
}
bool CheckOverall(Normal_Board** board, int x1, int x2, int y1, int y2, int nRow, int nCol)
{
	if (board[x1][y1].c == board[x2][y2].c && board[x1][y1].c != '\0')
	{
		int xMin, yMin, xMax, yMax;
		if (x1 == x2)
		{
			if (RowCheck(board, y1, y2, x1)) return true;
			else
			{
				xMin = x1; xMax = x1;
			}
		}
		else if (x1 > x2)
		{
			xMin = x2;
			xMax = x1;
		}
		else
		{
			xMin = x1;
			xMax = x2;
		}
		if (y1 == y2)
		{
			if (Colcheck(board, x1, x2, y1)) return true;
			else
			{
				yMin = y1; yMax = y1;
			}
		}
		else if (y1 > y2)
		{
			yMin = y2;
			yMax = y1;
		}
		else {
			yMin = y1;
			yMax = y2;
		}
		if (LCheck(board, xMin, xMax, yMin, yMax)) return true;
		if (Zcheck(board, xMin, xMax, yMin, yMax)) return true;
		if (Ucheck(board, xMin, xMax, yMin, yMax, nRow, nCol)) return true;
		return false;
	}
	return false;
}
void ConverToNull(Normal_Board** board, int x1, int x2, int y1, int y2, int nRow, int nCol)
{
	if (CheckOverall(board, x1, x2, y1, y2, nRow, nCol))
	{
		board[x1][y1].c = 1;
		board[x2][y2].c = 1;
	}
}
bool CheckEndGame(Normal_Board** board, int nRow, int nCol)
{
	bool check_1 = true;
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			CheckOverall(board, i, i + 1, j, j + 1, nRow, nCol);
		}
	}
	return true;
	
}