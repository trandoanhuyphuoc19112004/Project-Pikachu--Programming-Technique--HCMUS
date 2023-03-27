#pragma once
#include "InterfaceMenu_1.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct players
{
	string name;
	int life = 3;
	int point = 0;
};
void PlayerInfo(players& player);
