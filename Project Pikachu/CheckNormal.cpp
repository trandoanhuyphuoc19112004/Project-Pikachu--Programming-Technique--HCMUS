#include "CheckNormal.h"
#include "NormalMap.h";
void InitBoard(Normal_Board** board)
{
	// Initializing 2d pointer array
	for (int i = 0; i < BOARDHEIGTH; i++)
	{
		board[i] = new Normal_Board[BOARDWIDTH];
		for (int j = 0; j < BOARDWIDTH; j++)
		{
			board[i][j].i = i;
			board[i][j].j = j;
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
			int row = rand() % BOARDHEIGTH;
			int col = rand() % BOARDWIDTH;
			if (board[row][col].c == ' ')
			{
				board[row][col].c = random_c;
				time--;
			}
		}
		num--;
	}

}

void DeleteBoard(Normal_Board** board)
{
	for (int i = 0; i < BOARDHEIGTH; i++)
		delete[] board[i];
	delete[] board;
}
// Check cot + dong 
bool rowCheck(Normal_Board** board, int ymin, int ymax, int x)
{
	for (int i = ymin + 1; i < ymax; i++)
	{
		if (board[x][i].c != ' ')
			return false;
	}
	return true;
}
bool colCheck(Normal_Board** board, int xmin, int xmax, int y)
{
	for (int i = xmin + 1; i < xmax; i++)
	{
		if (board[i][y].c != ' ')
			return false;
	}
	return true;
}
bool LCheck(Normal_Board** board, int xMin, int xMax, int  yMin, int yMax)
{
	if (xMin == xMax && yMin == yMax)
		return false;
	if (rowCheck(board, yMin, yMax + 1, xMax) && colCheck(board, xMin, xMax + 1, yMax)) return true;
	if (rowCheck(board, yMin, yMax + 1, xMin) && colCheck(board, xMin - 1, xMax, yMax)) return true;
	if (rowCheck(board, yMin - 1, yMax, xMax) && colCheck(board, xMin, xMax + 1, yMin)) return true;
	if (rowCheck(board, yMin - 1, yMax, xMin) && colCheck(board, xMin - 1, xMax, yMin)) return true;
	return false;
}
bool Ucheck(Normal_Board** board, int x1, int x2, int y1, int y2)
{
	int xMin, xMax, yMin, yMax;
	int xTmp1, xTmp2, yTmp1, yTmp2;
	if (x1 < x2) {
		xMin = x1;
		xMax = x2;
		yTmp1 = y1;					//yTmp1 se lay toa do Y cua xMin
		yTmp2 = y2;					//yTmp2 se lay toa do Y cua xMax
	}
	else if (x1 == x2) {
		xMin = x1; xMax = x2; yTmp1 = y1; yTmp2 = y2;
	}
	else {
		xMin = x2;
		xMax = x1;
		yTmp1 = y2;
		yTmp2 = y1;
	}
	if (xMin == 0)
		if (colCheck(board, xMin-1, xMax, yTmp2)) return true;
	if (xMax == BOARDHEIGTH - 1)
		if (colCheck(board, xMin, xMax+1, yTmp1)) return true;
	// Check U di xuong
	if (colCheck(board, xMin, xMax + 1, yTmp1) || xMin == xMax) {
		for (int i = xMax + 1; i < BOARDHEIGTH; i++) {
			if (board[i][yTmp1].c != ' ' || board[i][yTmp2].c != ' ') break; 
			if (i == BOARDHEIGTH - 1) return true; 
			if (yTmp1 < yTmp2)
				if (rowCheck(board, yTmp1 - 1, yTmp2 + 1, i)) return true;
				else
					if (rowCheck(board, yTmp2 - 1, yTmp1 + 1, i)) return true;
		}
	}
	// Check U di len
	if (colCheck(board, xMin - 1, xMax, yTmp2) || xMin == xMax) {
		for (int i = xMin - 1; i >= 0; i--) {
			if (board[i][yTmp1].c != ' ' || board[i][yTmp2].c != ' ') break; 
			if (i == 0) return true; 
			if (yTmp1 < yTmp2) {
				if (rowCheck(board, yTmp1 - 1, yTmp2 + 1, i)) return true;
			}
			else {
				if (rowCheck(board, yTmp2 - 1, yTmp1 + 1, i)) return true;
			}
		}
	}
	if (y1 < y2) {
		yMin = y1;
		yMax = y2;
		xTmp1 = x1;					//xTmp1 se lay toa do X cua yMin
		xTmp2 = x2;					//xTmp2 se lay toa do X cua yMax
	}
	else if (y1 == y2) {
		yMin = y1; yMax = y2; xTmp1 = x1; xTmp2 = x2;
	}
	else {
		yMin = y2;
		yMax = y1;
		xTmp1 = x2;
		xTmp2 = x1;
	}
	if (yMin == 0) {
		if (rowCheck(board, yMin-1, yMax, xTmp2)) return true;
	}
	if (yMax == BOARDWIDTH - 1) {
		if (rowCheck(board, yMin, yMax+1, xTmp1)) return true;
	}
	// Check U huong sang phai
	if (rowCheck(board, yMin, yMax + 1, xTmp1) || yMin == yMax) 
	{
		for (int i = yMax + 1; i < BOARDWIDTH; i++) {
			if (board[xTmp1][i].c != ' ' || board[xTmp2][i].c != ' ') break; 
			if (i == BOARDWIDTH - 1) return true; 
			if (xTmp1 < xTmp2) {
				if (colCheck(board, xTmp1 - 1, xTmp2 + 1, i)) return true;
			}
			else {
				if (colCheck(board, xTmp2 - 1, xTmp1 + 1, i)) return true;
			}
		}
	}
	// Check U huong sang trai
	if (rowCheck(board, yMin - 1, yMax, xTmp2) || yMin == yMax) {
		for (int i = yMin - 1; i >= 0; i--) {
			if (board[xTmp1][i].c != ' ' || board[xTmp2][i].c != ' ') break; 
			if (i == 0) return true; 
			if (xTmp1 < xTmp2) {
				if (colCheck(board, xTmp1 - 1, xTmp2 + 1, i)) return true;
			}
			else {
				if (colCheck(board, xTmp2 - 1, xTmp1 + 1, i)) return true;
			}
		}
	}
	return false;
}
bool Zcheck(Normal_Board** board, int xMin, int xMax, int yMin, int yMax)
{
	if (xMin == xMax && yMin == yMax)
		return false;
	for (int i = yMin + 1; i <= yMax; i++) {
		if (colCheck(board, xMin - 1, xMax + 1, i)) {
			if (rowCheck(board, yMin, i + 1, xMin) && rowCheck(board, i - 1, yMax, xMax)) return true;
			if (rowCheck(board, yMin, i + 1, xMax) && rowCheck(board, i - 1, yMax, xMin)) return true;
		}
	}
	for (int i = xMin + 1; i <= xMax; i++) {
		if (rowCheck(board, yMin - 1, yMax + 1, i)) {
			if (colCheck(board, xMin, i + 1, yMin) && colCheck(board, i - 1, xMax, yMax)) return true;
			if (colCheck(board, xMin, i + 1, yMax) && colCheck(board, i - 1, xMax, yMin)) return true;
		}
	}
	return false;
}
bool canConnect(Normal_Board** board, int x1, int x2, int y1, int y2)
{
	int xMin, yMin, xMax, yMax;
	if (x1 == x2)
	{
		xMin = x1;
		xMax = x1;
		if ((x1 == 0) || (x2 == BOARDHEIGTH - 1)) return true;
		else if (y1 < y2) {
			if (rowCheck(board, y1, y2, x1)) return true;
		}
		else {
			if (rowCheck(board, y2, y1, x1)) return true;
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
		yMin = y1; yMax = y1;
		if ((y1 == 0) || (y1 == BOARDWIDTH - 1)) return true;
		else if (x1 < x2) {
			if (colCheck(board, x1, x2, y1)) return true;
		}
		else {
			if (colCheck(board, x2, x1, y1)) return true;
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
	if (Ucheck(board, x1, x2, y1, y2)) return true;
	return false;
}

bool CheckOverall(Normal_Board** board, position pos1, position pos2) 
{
	if (board[pos1.x][pos1.y].c == board[pos2.x][pos2.y].c) {
		if (canConnect(board, pos1.x, pos2.x, pos1.y, pos2.y))
			return true;
	}
	return false;
}

bool CheckWin(Normal_Board** board)
{
	for (int i = 0; i < BOARDHEIGTH; i++)
	{
		for (int j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j].c != ' ')
				return false;
		}
	}
	return true;
}

// This function also used to check valid pair exist.
bool  HelpSuggestion(Normal_Board** board, position &pos1, position &pos2)
{
	for (int i = 0; i < BOARDHEIGTH; i++)
		for (int j = 0; j < BOARDWIDTH; j++)
		{
			if (board[i][j].c == ' ')
				continue;
			for (int g = 0; g < BOARDHEIGTH; g++)
				for (int h = 0; h < BOARDWIDTH; h++)
				{
					if (CheckOverall(board, { i,j }, { g,h }) && i!=g && g!=h)
					{
						pos1 = { i,j };
						pos2 = { g,h };
						return true;
					}
				}
		}
	return false; 
}
	
