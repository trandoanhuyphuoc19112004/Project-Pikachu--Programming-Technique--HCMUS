#include "Clock.h"
// ref: https://www.youtube.com/watch?v=hbiu9e5ZbuQ
char inToA(int k) 
{
	switch (k)
	{
	case 0:return '0';
	case 1:return '1';
	case 2:return '2';
	case 3:return '3';
	case 4:return '4';
	case 5:return '5';
	case 6:return '6';
	case 7:return '7';
	case 8:return '8';
	case 9:return '9';
	default:
		break;
	}
}
// Process time 
void insertarray(char* h, Hour* j) 
{
	int bait = 0;
	bait = j->second;
	h[4] = inToA(bait % 10);
	h[3] = inToA(bait /= 10);    // 00:00:00

	bait = j->minute;
	h[1] = inToA(bait % 10);
	h[0] = inToA(bait /= 10);
}

bool changetime(Hour* h) // Return 0 if no time remaining
{
	if (h->second > 0) --h->second;
	else if (h->minute > 0) 
	{
		h->second = 59;
		--h->minute;
	}
	else return 0;
	return 1;
}

//dung de in ra mot chuoi thay the ham cout
void WriteBlockChar(char* Arraych,int row, int col,int x, int y,int color)
{
	CHAR_INFO* charater = new CHAR_INFO[row * col];
	for (int i = 0; i < row * col; i++) {
		charater[i].Attributes = color;
		charater[i].Char.AsciiChar = Arraych[i];
	}
	COORD sizebuff = { col,row };
	COORD pos = { 0,0 };
	SMALL_RECT earea = { x,y,x + col - 1,y + row - 1 };
	WriteConsoleOutputA(GetStdHandle(STD_OUTPUT_HANDLE), charater, sizebuff, pos, &earea);
	delete[] charater;
}

