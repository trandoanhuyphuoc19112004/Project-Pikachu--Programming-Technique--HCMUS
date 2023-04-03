#pragma once
#include "Players.h"
#include "NormalMap.h"
#include "CheckNormal.h"
#include <fstream>
#include <iostream>
#pragma pack()
using namespace std; 
void SaveFile(string filename, players user);
void LoadFile(string filename, players user);
