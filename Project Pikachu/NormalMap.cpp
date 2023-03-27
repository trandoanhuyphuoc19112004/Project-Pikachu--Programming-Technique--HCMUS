#include "CheckNormal.h"
#include"NormalMap.h"
#include "Players.h"
void NormalMap(players& player)
{
	Normal_Board** board = new Normal_Board * [BOARDHEIGTH + 2];
	InitBoard(board);
	char c;
	do
	{
		system("cls");
		SetColor(11);
		GoToXY(10, 2);
		cout << "Player:" << player.name;
		GoToXY(35, 2);
		cout << "Life:" << player.life;
		GoToXY(55, 2);
		cout << "Points:" << player.point;
		GoToXY(80, 2);
		cout << "Normal Mode";
		//GoToXY(10, 8);
		OutputBoard(board, BOARDHEIGTH + 2, BOARDWIDTH + 2);
		//renderBoard(board);
		c = _getch();
	} while (c == Enter); 

}
void renderBoard(Normal_Board** board) {
	for (int i = 0; i < BOARDHEIGTH + 2; i++) {
		for (int j = 0; j < BOARDWIDTH + 2; j++) {
			drawBox(1, board[i][j]);
		}
	}
}
char box[5][10] = { {" ------- "},
					{"|       |"},
					{"|       |"},
					{"|       |"},
					{" ------- "} };

void drawBox(int color, Normal_Board board) {
	SetColor(11);
	int x1 = board.x + 1, y1 = board.y + 1;
	for (int i = 0; i < 6; i++) {
		GoToXY(x1 * 13, y1 * 6 + i);
		cout << box[i];
	}
	/*if (isSelected) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (c % 6 + 1)); // white background
		for (int i = 1; i < 4; i++) {
			GoToXY(x * 10 + 1, y * 4 + i);
			cout << "         ";
		}
		GoToXY(x1 * 10 + 5, y1 * 4 + 2);
		cout << c;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else {*/
	GoToXY(x1 * 13 + 4, y1 * 6 + 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), board.c % 6 + 1);
	cout << board.c;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	//}
}