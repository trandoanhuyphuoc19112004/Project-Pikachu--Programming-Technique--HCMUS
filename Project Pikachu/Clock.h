#pragma once
#include <thread>
#include "InterfaceMenu_1.h"
struct Hour 
{
	int minute;
	int second;
};
char inToA(int k);
void insertarray(char* h, Hour* j);
bool changetime(Hour* h);
void WriteBlockChar(char* Arraych, int row, int col, int x, int y, int color);
void printClock();
void close(DWORD evt);