
#include"NormalMap.h"
void NormalMap(players& player)
{
	system("cls");
	Normal_Board** board = new Normal_Board * [BOARDHEIGTH];
	InitBoard(board);
	char c;
	do
	{
		SetColor(11);
		GoToXY(10, 2);
		cout << "Player:" << player.name;
		GoToXY(35, 2);
		cout << "Life:" << player.life;
		GoToXY(55, 2);
		cout << "Points:" << player.point;
		GoToXY(80, 2);
		cout << "Normal Mode";
		GoToXY(30, 32);
		cout << "Press ESC to exit";
		GoToXY(30, 34);
		cout << "Press Enter to choose";
		GoToXY(30, 36);
		cout << "Use arrow keys to move";
		position selectedPos[] = { {-1, -1}, {-1, -1} };
		position curPosition{ 0, 0 };
		DrawNormalMap(board);
		c = _getch();
	} while (c != ESC); 

}

void DrawNormalMap(Normal_Board** board) 
{
	for (int i = 0; i < BOARDHEIGTH; i++) {
		for (int j = 0; j < BOARDWIDTH; j++) {
			drawBox( board[i][j]);
		}
	}
}
char box[5][10] = { {" ------- "},
					{"|       |"},
					{"|       |"},
					{"|       |"},
					{" ------- "} };
// Toa do trong mang 2 chieu nguoc voi toa do trong ham GotoXY
void drawBox(Normal_Board board) 
{
	// Draw Box
	SetColor(11);
	int i1 = board.i + 1, j1 = board.j + 1;

	for (int i = 0; i < 6; i++)
	{
		GoToXY(j1 * 13, i1 * 6 + i);
		cout << box[i];
	}
			if (board.Is_Selected) 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  (board.c % 6 + 1)); 
				for (int i = 1; i < 4; i++) 
				{
					GoToXY(i1 * 10 + 1, j1 * 4 + i);
					cout << "         ";
				}
				GoToXY(i1 * 10 + 5, j1 * 4 + 2);
				cout << board.c;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			// Add letter to the box
			else
			{
				GoToXY(j1 * 13 + 4, i1 * 6 + 2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), board.c % 4 + 1);
				cout << board.c;

			}
			
}