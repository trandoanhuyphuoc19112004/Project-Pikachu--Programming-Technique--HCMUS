#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
#define WINDOWSHEIGHT 820
#define WINDOWSWIDTH 1000
#define Enter 13
#define ESC 27
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define TAB 9
// Customize size of console
void HideScrollBar();
void setWindowSizeAndPos();
void HideCursor(bool visible);
void DisableCtrButton(bool Close, bool Min, bool Max);
void CreateWindows();
// Create menu bar 
void TextColor(int x);
void SetColor(int color);
void GoToXY(int x, int y);
void NoHighlightMenuBar(int x, int y);
void HighLightMenuBar(int x, int y);
int CreateMenuGame();
// Load Image to Menu 
void LoadandDrawAscii(string filename, int line, int x, int y);


