#pragma once
#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#define BOARDWIDTH 6
#define BOARDHEIGTH 4
using namespace std;

struct position
{
	int x;
	int y;
};

struct Normal_Board
{
	int i, j;
	char c = ' ';
	bool Is_Selected = 0;
	bool Is_Chosen = 0;
	bool movesuggest = 0;
	bool ishiglight = 0;
};

struct Hard_Board
{
	int i, j;
	bool Is_Selected = 0, Is_Chosen = 0;
	char c = ' ';
	Hard_Board* next;
	bool Is_Clear = 0;
};

