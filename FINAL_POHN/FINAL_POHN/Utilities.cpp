#include "Utilities.h"

void GoToCoordinates(int x, int y)
{
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(outputHandle, coord);
}

void DrawFrame(int upLeftX, int upLeftY, int downRightX, int downRightY)
{
	GoToCoordinates(upLeftX, upLeftY);
	cout << (char)201;
	GoToCoordinates(downRightX, upLeftY);
	cout << (char)187;
	GoToCoordinates(downRightX, downRightY);
	cout << (char)188;
	GoToCoordinates(upLeftX, downRightY);
	cout << (char)200;

	for (int i = upLeftX + 1; i < downRightX; i++)
	{
		GoToCoordinates(i, upLeftY);
		cout << (char)205;
		GoToCoordinates(i, downRightY);
		cout << (char)205;
	}

	for (int i = upLeftY + 1; i < downRightY; i++)
	{
		GoToCoordinates(downRightX, i);
		cout << (char)186;
		GoToCoordinates(upLeftX, i);
		cout << (char)186;
	}
}

int GetScreenWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	return (!GetConsoleScreenBufferInfo(outputHandle, &screenBufferInfo)) ? 80 : screenBufferInfo.srWindow.Right + 1;
}

int GetScreenHeight()
{
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	return (!GetConsoleScreenBufferInfo(outputHandle, &screenBufferInfo)) ? 80 : screenBufferInfo.srWindow.Bottom + 1;
}

void SetBackgroundColor(Color color)
{
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wAttrib = 0;
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;

	GetConsoleScreenBufferInfo(outputHandle, &screenBufferInfo);
	wAttrib = screenBufferInfo.wAttributes;

	wAttrib &= ~(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);

	int c = (int)color;

	if (c & 1)
		wAttrib |= BACKGROUND_BLUE;
	if (c & 2)
		wAttrib |= BACKGROUND_GREEN;
	if (c & 4)
		wAttrib |= BACKGROUND_RED;
	if (c & 8)
		wAttrib |= BACKGROUND_INTENSITY;

	SetConsoleTextAttribute(outputHandle, wAttrib);
}

void SetForegroundColor(Color color)
{
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wAttrib = 0;
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;

	GetConsoleScreenBufferInfo(outputHandle, &screenBufferInfo);
	wAttrib = screenBufferInfo.wAttributes;

	wAttrib &= ~(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

	int c = (int)color;

	if (c & 1)
		wAttrib |= FOREGROUND_BLUE;
	if (c & 2)
		wAttrib |= FOREGROUND_GREEN;
	if (c & 4)
		wAttrib |= FOREGROUND_RED;
	if (c & 8)
		wAttrib |= FOREGROUND_INTENSITY;

	SetConsoleTextAttribute(outputHandle, wAttrib);
}

void SetConsoleSize(int width, int height)
{
	HANDLE hwnd;
	SMALL_RECT rect;
	COORD coord;
	CONSOLE_CURSOR_INFO cci;

	coord.X = width;
	coord.Y = height;

	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = coord.Y - 1;
	rect.Right = coord.X - 1;

	hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hwnd, coord);
	SetConsoleWindowInfo(hwnd, TRUE, &rect);

	HWND hand = GetConsoleWindow();
	SetWindowLong(hand, GWL_STYLE, GetWindowLong(hand, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}