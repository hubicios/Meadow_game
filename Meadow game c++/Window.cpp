#include "Window.h"

#include <iostream>
#include <windows.h>
#include <conio.h>


Window::Window()
{
	SetConsoleTitle("Meadow game");

}

Window::~Window()
{
}
void Window::ClearConsole()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0, 0 };
	DWORD count;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		SetConsoleCursorPosition(hStdOut, coord);
	}
	return;
}

void Window::gotoXY(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}
void Window::setCursor(bool visible) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD size = 20;
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

void Window::drawEmptyWindow(int height,int width)
{
	COORD coord;
	for (short i = 1; i <= height; i++) //y
	{
		coord = { 1, i };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		for (int j = 1; j <= width; j++)//x
		{
			std::cout << ' ';
			//std::cout.flush();
		}
	}

	for (short i = 1;i <= height;i++)
	{
		coord = { 0, i };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << '#';
		coord = { (short)width + 1, i };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << '#';
	}

	coord = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for (short i = 0;i <= width + 1;i++)
	{
		std::cout << '#';
	}
	coord = { 0, (short)height + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for (short i = 0;i <= width + 1;i++)
	{
		std::cout << '#';
	}
}