#include "Header.h"
void Init_Board(Cell_1** board)
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
		//srand((int)time(NULL));
		// Insert the letter to random indexes
		while (time)
		{
			//srand(time(NULL));
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
void Output_Board(Cell_1** board)
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
void Delete_Board(Cell_1** board)
{
	for (int i = 0; i < BOARDHEIGTH; i++)
		delete[] board[i];
	delete[] board;
}
bool Next_Check(Cell_1** board, position pos_1, position pos_2)
{
	if (((pos_1.x == pos_2.x + 1) || (pos_1.y == pos_2.y + 1)) && (pos_2.x == pos_2.y))
	{
		if(board[pos_1.y][pos_1.x].c == board[pos_2.y][pos_2.x].c)
		return true;
	}
		
	if (((pos_2.x == pos_1.x + 1) || (pos_2.y == pos_1.y + 1)) && (pos_1.x == pos_1.y))
	{
		if (board[pos_1.y][pos_1.x].c == board[pos_2.y][pos_2.x].c)
			return true;
	}
	return false;
}

bool Z_Check(Cell_1** board, position pos_1, position pos_2)
{
	if (pos_1.x == pos_2.y || pos_1.y == pos_2.y)
		return false;

}