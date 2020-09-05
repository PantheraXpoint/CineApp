#include "Header.h"

void FixConsoleWindow() {
	HWND hwnd = GetConsoleWindow(); //fullscreen mode
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
	HWND consoleWindow = GetConsoleWindow(); //fix screen
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void go(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcolor(const int& k) {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}

void setcursor(bool on, DWORD SIZE)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	if (SIZE == 0)
		SIZE = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = on;
	lpCursor.dwSize = SIZE;
	SetConsoleCursorInfo(console, &lpCursor);
}

void PrintString(int where_x, int where_y, string content, int color)
{
	go(where_x, where_y);
	setcolor(color);
	cout << content;
}

void DynamicPrintString(int where_x, int where_y, vector<string> content, int color)
{
	int size = content.size();
	setcolor(color);
	for (int i = 0; i < size; ++i)
	{
		go(where_x, where_y++);
		cout << content[i];
	}
}

bool YN_Check_Box(int where_x, int where_y)
{
	setcursor(false, 0);
	int x = where_x; int y = where_y;

	string question = "Are you sure to continue?";
	string ok = " OK ";
	string no = " NO ";

	PrintString(where_x, where_y, question, 12);
	PrintString(x += 4, y += 2, ok, 15);
	x = where_x; y = where_y;
	PrintString(x += 17, y += 2, no, 15);
	x = where_x; y = where_y;

	int command = -1;
	int side = 1;
	do
	{
		if (side)
		{
			PrintString(x += 17, y += 2, no, 79);
			x = where_x; y = where_y;
		}
		else
		{
			PrintString(x += 4, y += 2, ok, 175);
			x = where_x; y = where_y;
		}
		command = _getch();
		if (command == 'a' || command == 'A' || command == 75)
		{
			if (side == 1)
			{
				PrintString(x += 17, y += 2, no, 15);
				x = where_x; y = where_y;
			}
			side = 0;
		}
		else if (command == 'd' || command == 'D' || command == 77)
		{
			if (side == 0)
			{
				PrintString(x += 4, y += 2, ok, 15);
				x = where_x; y = where_y;
			}
			side = 1;
		}
	} while (!(command == 13 || command == 32));

	setcursor(true, 10);
	setcolor(15);

	return !side;
}
