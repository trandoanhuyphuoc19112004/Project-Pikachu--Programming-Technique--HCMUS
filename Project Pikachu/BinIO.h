#pragma once
#include "Players.h"
#include "NormalMap.h"
#include "CheckNormal.h"
#include <fstream>
#include <iostream>
using namespace std; 
void SaveFile(string filename, players user);
void LoadFile(string filename, players user);
