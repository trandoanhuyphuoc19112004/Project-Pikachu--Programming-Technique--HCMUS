#include"CheckHard.h"
#include"HardMap.h"
//Ham them node vao dau list
void push(Hard_Board*& head, Hard_Board* data) {
	if (head == NULL) {
		head = data;
	}
	else {
		Hard_Board* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = data;
	}
}

//Ham tra ve dia chi cua o can tim
Hard_Board* findNode(Hard_Board** board, int x, int y) 
{
	if (x < 0 || x>4 || y < 0 || y>5)
		return NULL;
	Hard_Board* tmp = board[x];
	if (tmp == NULL) return NULL;
	while (tmp) 
	{
		if (tmp->j == y)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

//Ham tao bang va random
void initBoardZ(Hard_Board** board) 
{
	for (int i = 0; i < BOARDHEIGTH; i++) 
	{
		board[i] = NULL;
		for (int j = 0; j < BOARDWIDTH; j++) 
		{
			Hard_Board* tmp = new Hard_Board;
			tmp->i = i;
			tmp->j = j;
			tmp->next = NULL;
			push(board[i], tmp);
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
			Hard_Board* tmp = findNode(board, row, col);
			if (tmp->c == ' ')
			{
				tmp->c = random_c;
				time--;
			}
		}
		num--;
	}
}
//Ham xoa het bang
void deleteBoardZ(Hard_Board** board)
{
	for (int i = 0; i < BOARDHEIGTH; i++) 
	{
		Hard_Board * temp;
		while (board[i] != nullptr)
		{
			temp = board[i];
			board[i] = board[i]->next;
			delete temp;
		}
	}
	delete[] board;
}
//Ham check 2 o cung hang
bool rowCheckZ(Hard_Board** board, int yMin, int yMax, int x) {
	if (yMax = yMin + 1) return true;
	Hard_Board* tmp = findNode(board, x, yMin + 1);
	int i = yMin + 1, j = yMax;
	if (tmp != NULL) return false;
	while (tmp == NULL) {
		if (i == j) return true;
		if (tmp != NULL) return false;
		i++;
		tmp = findNode(board, x, i);
	}
}
//Ham check 2 o cung cot
bool colCheckZ(Hard_Board** board, int xMin, int xMax, int y) {
	if (xMax = xMin + 1) return true;
	Hard_Board* tmp = findNode(board, xMin + 1, y);
	int i = xMin + 1, j = xMax;
	if (tmp != NULL) return false;
	while (tmp == NULL) {
		if (i == j) return true;
		if (tmp != NULL) return false;
		i++;
		tmp = findNode(board, i, y);
	}
}
//Ham check chu L
bool lCheckZ(Hard_Board** board, int x1, int x2, int y1, int y2) {
	if (x1 > x2) {
		if (y1 > y2) {
			if (colCheckZ(board, x2 - 1, x1, y1) && rowCheckZ(board, y2, y1 + 1, x2)) return true;
			if (colCheckZ(board, x2, x1 + 1, y2) && rowCheckZ(board, y2 - 1, y1, x1)) return true;
		}
		else {
			if (colCheckZ(board, x2, x1 + 1, y2) && rowCheckZ(board, y1, y2 + 1, x1)) return true;
			if (colCheckZ(board, x2 - 1, x1, y1) && rowCheckZ(board, y1 - 1, y2, x2)) return true;
		}
	}
	else {
		if (y1 > y2) {
			if (colCheckZ(board, x1 - 1, x2, y2) && rowCheckZ(board, y2 - 1, y1, x1)) return true;
			if (colCheckZ(board, x1, x2 + 1, y1) && rowCheckZ(board, y2, y1 + 1, x2)) return true;
		}
		else {
			if (colCheckZ(board, x1 - 1, x2, y2) && rowCheckZ(board, y1, y2 + 1, x1)) return true;
			if (colCheckZ(board, x1, x2 + 1, y1) && rowCheckZ(board, y1 - 1, y2, x2)) return true;
		}
	}
	return false;
}
//Ham check chu Z
bool zCheckZ(Hard_Board** board, int x1, int x2, int y1, int y2) {
	//Check Z dung
	if (y2 > y1) {
		for (int i = y1 + 1; i < y2; i++) {
			if (rowCheckZ(board, y1, i + 1, x1) && rowCheckZ(board, i - 1, y2, x2)) {
				if (x2 > x1) {
					if (colCheckZ(board, x1 - 1, x2 + 1, i)) return true;
				}
				else {
					if (colCheckZ(board, x2 - 1, x1 + 1, i)) return true;
				}
			}
		}
	}
	else {
		for (int i = y2 + 1; i < y1; i++) {
			if (rowCheckZ(board, y2, i + 1, x2) && rowCheckZ(board, i - 1, y1, x1)) {
				if (x2 > x1) {
					if (colCheckZ(board, x1 - 1, x2 + 1, i)) return true;
				}
				else {
					if (colCheckZ(board, x2 - 1, x1 + 1, i)) return true;
				}
			}
		}
	}
	//Check Z ngang
	if (x2 > x1) {
		for (int j = x1 + 1; j < x2; j++) {
			if (colCheckZ(board, x1, j + 1, y1) && colCheckZ(board, j - 1, x2, y2)) {
				if (y2 > y1) {
					if (rowCheckZ(board, y1 - 1, y2 + 1, j)) return true;
				}
				else {
					if (rowCheckZ(board, y2 - 1, y1 + 1, j)) return true;
				}
			}
		}
	}
	else {
		for (int j = x2 + 1; j < x1; j++) {
			if (colCheckZ(board, x2, j + 1, y2) && colCheckZ(board, j - 1, x1, y1)) {
				if (y2 > y1) {
					if (rowCheckZ(board, y1 - 1, y2 + 1, j)) return true;
				}
				else {
					if (rowCheckZ(board, y2 - 1, y1 + 1, j)) return true;
				}
			}
		}
	}
	return false;
}
//Ham check chu Z
bool uCheckZ(Hard_Board** board, int x1, int x2, int y1, int y2) {
	int xMin, xMax, yMin, yMax,
		xTmp1, xTmp2, yTmp1, yTmp2; //Tmp: Temp
	if (x1 > x2) {
		xMax = x1;
		xMin = x2;
		yTmp2 = y1;			//yTmp2 lay gia tri y cua o co x lon hon
		yTmp1 = y2;			//yTmp1 thi nguoc lai
	}
	else {
		xMax = x2;
		xMin = x1;
		yTmp2 = y2;
		yTmp1 = y1;
	}
	if (xMin == 0)
		if (colCheckZ(board, -1, xMax, yTmp2)) return true;
	if (xMax == BOARDHEIGTH - 1)
		if (colCheckZ(board, xMin, BOARDHEIGTH, yTmp1)) return true;
	//Check U huong len
	if (colCheckZ(board, xMin - 1, xMax, yTmp1)) {
		for (int i = xMin - 1; i >= 0; i--) {
			if (findNode(board, i, yTmp1) != NULL && findNode(board, i, yTmp2) != NULL) break;
			if (i == 0) return true;
			if (yTmp1 < yTmp2) {
				if (rowCheckZ(board, yTmp1, yTmp2, i)) return true;
			}
			else {
				if (rowCheckZ(board, yTmp2, yTmp1, i)) return true;
			}
		}
	}
	//Check U di xuong
	if (colCheckZ(board, xMin, xMax + 1, yTmp2)) {
		for (int i = xMax + 1; i < BOARDHEIGTH; i++) {
			if (findNode(board, i, yTmp1) != NULL && findNode(board, i, yTmp2) != NULL) break;
			if (i == BOARDHEIGTH - 1) return true;
			if (yTmp1 < yTmp2) {
				if (rowCheckZ(board, yTmp1 - 1, yTmp2 + 1, i)) return true;
			}
			else {
				if (rowCheckZ(board, yTmp2 - 1, yTmp1 + 1, i)) return true;
			}
		}
	}
	if (y1 < y2) {
		yMin = y1;
		yMax = y2;
		xTmp1 = x1;			//xTmp1 lay gia tri x cua o co y be hon
		xTmp2 = x2;			//xTmp2 thi nguoc lai
	}
	else {
		yMin = y2;
		yMax = y1;
		xTmp1 = x2;
		xTmp2 = x1;
	}
	if (yMin == 0) {
		if (rowCheckZ(board, -1, yMax, xTmp2)) return true;
	}
	if (yMax == BOARDWIDTH - 1) {
		if (rowCheckZ(board, yMin, BOARDWIDTH, xTmp1)) return true;
	}
	//Check U huong sang phai
	if (rowCheckZ(board, yMin, yMax + 1, xTmp1)) {
		for (int i = yMax + 1; i < BOARDWIDTH; i++) {
			if (findNode(board, yTmp1, i) != NULL && findNode(board, yTmp2, i) != NULL) break;
			if (i == BOARDWIDTH - 1) return true;
			if (xTmp1 > xTmp2) {
				if (colCheckZ(board, xTmp1 - 1, xTmp2 + 1, i)) return true;
			}
			else {
				if (colCheckZ(board, xTmp1 - 1, xTmp2 + 1, i)) return true;
			}
		}
	}
	//Check U huong sang trai
	if (rowCheckZ(board, yMin - 1, yMax, xTmp1)) {
		for (int i = yMin - 1; i >= 0; i--) {
			if (findNode(board, yTmp1, i) != NULL && findNode(board, yTmp2, i) != NULL) break;
			if (i == 0) return true;
			if (xTmp1 > xTmp2) {
				if (colCheckZ(board, xTmp1 - 1, xTmp2 + 1, i)) return true;
			}
			else {
				if (colCheckZ(board, xTmp1 - 1, xTmp2 + 1, i)) return true;
			}
		}
	}
}
//Ham check duong di
bool canConnectZ(Hard_Board** board, int x1, int x2, int y1, int y2) {
	if (x1 == x2)
	{
		if ((x1 == 0) || (x2 == BOARDHEIGTH - 1)) return true;
		else if (y1 < y2) {
			if (rowCheckZ(board, y1, y2, x1)) return true;
		}
		else {
			if (rowCheckZ(board, y2, y1, x1)) return true;
		}
	}
	if (y1 == y2)
	{
		if ((y1 == 0) || (y1 == BOARDWIDTH - 1)) return true;
		else if (x1 < x2) {
			if (colCheckZ(board, x1, x2, y1)) return true;
		}
		else {
			if (colCheckZ(board, x2, x1, y1)) return true;
		}
	}
	if (lCheckZ(board, x1, x2, y1, y2)) return true;
	if (zCheckZ(board, x1, x2, y1, y2)) return true;
	if (uCheckZ(board, x1, x2, y1, y2)) return true;
}
//Ham xoa o
void deleteNode(Hard_Board** board, int x, int y) 
{
	Hard_Board* tmp = findNode(board, x, y); //Lay dia chi cua o
	if (y == 0) //Neu o nam o cot dau tien
	{
		if (board[x]->next == NULL) //Neu o ben phai trong
		{
			removeBox(tmp->i,tmp->j);	//Xoa o hien tai
			board[x] == NULL;
			board[x]->Is_Clear = 1;		//Is_Clear=1 tuc la hang da trong het cac o
			return;
		}
		board[x]->c = tmp->next->c; //Gan gia tri c o hien tai bang o ben phai
		tmp = board[x]->next;		//Di chuyen con tro sang o ben phai
		if (tmp->next == NULL) {	//Neu o ben phai trong
			removeBox(tmp->i, tmp->j); //Xoa o hien tai
			delete tmp;
			board[x]->next = NULL;
		}
		else 
		{
			while (tmp->next->next != NULL) //Chay con tro tu trai sang phai cho toi khi gap o trong cach 1 o
			{
				tmp->c = tmp->next->c;
				tmp = tmp->next;
			}
			tmp->c = tmp->next->c;
			removeBox(tmp->next->i, tmp->next->j);
			delete tmp->next;
			tmp->next = NULL;
		}
	}
	else if (tmp->next != NULL) //Neu o ben phai khong trong
	{
		while (tmp->next->next != NULL) 
		{
			tmp->c = tmp->next->c;
			tmp = tmp->next;
		}
		tmp->c = tmp->next->c;
		removeBox(tmp->next->i, tmp->next->j);
		delete tmp->next;
		tmp->next = NULL;
	}
	else 
	{
		removeBox(tmp->i, tmp->j); //Neu o ben phai trong
		delete tmp;
		tmp = findNode(board, x, y - 1);
		tmp->next = NULL;
	}
}
//Check tong
bool checkOverallZ(Hard_Board** board, position p1, position p2) {
	if (findNode(board, p1.x, p1.y)->c == findNode(board, p2.x, p2.y)->c) {
		if (canConnectZ(board, p1.x, p2.x, p1.y, p2.y)) {
			return true;
		}
	}
	return false;
}
//Check chien thang
bool checkWin(Hard_Board** board)
{
	for (int i = 0; i < BOARDHEIGTH; i++)
	{
		if (board[i]->Is_Clear != 1)
			return false;
	}
	return true;
}
