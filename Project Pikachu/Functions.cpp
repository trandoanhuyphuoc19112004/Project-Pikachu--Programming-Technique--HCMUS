#include "Header.h"
void InitBoard (Cell_1** board)
{
	// Initializing 2d pointer array
	for (int i = 0; i < BOARDHEIGTH; i++)
	{
		board[i] = new Cell_1 [BOARDWIDTH];
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
			int row = rand() % BOARDHEIGTH;
			int col = rand() % BOARDWIDTH;
			if (board[row][col].c == -51)
			{
				board[row][col].c = random_c;
				time--;
			}
		}
		num--;
	}
}
void OutputBoard (Cell_1** board)
{
	for (int i = 0; i < BOARDHEIGTH; i++)
	{
		for (int j = 0; j < BOARDWIDTH; j++)
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
bool LineCheck (Cell_1** board, position pos1, position pos2)
{
	int min, max;
	if (pos1.x == pos2.x)
	{
		if (pos1.y > pos2.y)
		{
			min = pos2.y;
			max = pos1.y;
		}
		else
		{
			min = pos1.y;
			max = pos2.y;
		}
		for (int i = min; i <= max; i++)
		{
			if (board[pos1.x][i].Barrier == true)
				return false;
		}
	}
	if (pos1.y == pos2.y)
	{
		if (pos1.x > pos2.x)
		{
			min = pos2.x;
			max = pos1.x;
		}
		else
		{
			min = pos1.x;
			max = pos2.x;
		}
	}
	for (int i = min; i <= max; i++)
	{
		if (board[i][pos1.y].Barrier == true)
			return false;
	}
	return true;
}

bool ZCheck (Cell_1** board, position pos1, position pos2)
{
	if (pos1.x == pos2.y || pos1.y == pos2.y)
		return false;

}