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

void Draw::DrawBoard(int x, int y, int width, int height)
{
	string str1, str2, str3, str4; str1.push_back(char(218));
	str2.push_back(char(179)); str3.push_back(char(195)); str4.push_back(char(192));
	for (int i = 1; i < 4 * width; ++i)
	{
		if (i % 4 == 0 && i < 4 * width)
		{
			str1.push_back(char(194));
			str2.push_back(char(179));
			str3.push_back(char(197));
			str4.push_back(char(193));
		}
		else
		{
			str1.push_back(char(196));
			str2.push_back(' ');
			str3.push_back(char(196));
			str4.push_back(char(196));
		}
	}
	str1.push_back(char(191)); str2.push_back(char(179));
	str3.push_back(char(180)); str4.push_back(char(217));
	vector <string> str;  str.push_back(str1);
	for (int i = 1; i < 2 * height; ++i)
	{
		if (i % 2 == 0) str.push_back(str3);
		else str.push_back(str2);
	}
	str.push_back(str4);
	DynamicPrintString(x, y, str);
	this->a.xmin = x; this->a.ymin = y;
	this->height = height; this->width = width;
}
void DrawRec(int x, int y, int width, int height, int k)
{
	string str1, str2,str4; str1.push_back(char(218));
	str2.push_back(char(179));  str4.push_back(char(192));
	for (int i = 1; i < 4 * width; ++i)
	{
		str2.push_back(' ');
		str1.push_back(char(196));
		str4.push_back(char(196));
	}
	str1.push_back(char(191)); str2.push_back(char(179)); str4.push_back(char(217));
	vector <string> str;  str.push_back(str1);
	for (int i = 1; i < 2 * height; ++i)
	{
		//if (i % 2 == 0) str.push_back(str3);
		//else str.push_back(str2);
		str.push_back(str2);
	}
	str.push_back(str4);
	DynamicPrintString(x, y, str,k);
}

Location Draw::getLocation()
{
	this->a.xmax = this->a.xmin + 4 * this->width;
	this->a.ymax = this->a.ymin + 2 * this->height;
	return this->a;
}
