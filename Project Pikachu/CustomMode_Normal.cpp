#include "CustomMode_Normal.h"
void InitBoard_Custom(Normal_Board** board, int nrow, int ncol)
{
	// Initializing 2d pointer array
	for (int i = 0; i < nrow; i++)
	{
		board[i] = new Normal_Board[ncol];
		for (int j = 0; j < ncol; j++)
		{
			board[i][j].i = i;
			board[i][j].j = j;
		}
	}

	srand((char)time(NULL));
	int num = (nrow * ncol) / 2;

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
			int row = rand() % nrow;
			int col = rand() % ncol;
			if (board[row][col].c == ' ')
			{
				board[row][col].c = random_c;
				time--;
			}
		}
		num--;
	}
}
void DeleteBoard_Custom(Normal_Board** board, int nrow)
{
	for (int i = 0; i < nrow; i++)
		delete[] board[i];
	delete[] board;
}