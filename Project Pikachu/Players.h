#pragma once
#include "InterfaceMenu_1.h"
#include "CheckNormal.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
using namespace std;
struct players
{
	char name[30]; // 
	int life = 3; // 4 bytes
	int point = 0; // 4 bytes 
};

string PlayerInfo(players& player);
