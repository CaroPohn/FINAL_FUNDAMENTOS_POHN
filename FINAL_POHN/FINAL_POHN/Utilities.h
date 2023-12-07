#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Vector2
{
	int x;
	int y;
};

enum class Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	WHITE,
	GRAY,
	LBLUE,
	LGREEN,
	LCYAN,
	LRED,
	LMAGENTA,
	YELLOW,
	BWHITE
};

void GoToCoordinates(int x, int y);
void DrawFrame(int upLeftX, int upLeftY, int downRightX, int downRightY);
int GetScreenWidth();
int GetScreenHeight();
void SetBackgroundColor(Color color);
void SetForegroundColor(Color color);
