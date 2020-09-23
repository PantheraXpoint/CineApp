#include <iostream>
#include <math.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iomanip>

using namespace std;

struct Location
{
	int xmin, ymin;
	int xmax, ymax;
};

struct Time
{
	int hour, minute;
};
struct Shot
{
	int ShotNum;
	Time Start, End;
	int avail_slots;
	bool seat[10][20];
};

struct Film
{
	string FilmName;
	float Price;
	string Description;
	int Duration;
};

struct Room
{
	Film Movie;
	int ID;
	Shot *Current;
};	

/*
	maximize console screen, call at the beginning of program
*/
void FixConsoleWindow();

/*
	move cursor to (x,y) coordinate on console
*/
void go(int x, int y);

/*
	change console color, run this code to test
	for (int i =0;i<256;++i)
	{
		color(i);
		cout << "123456789abcd" << endl;
	}
*/
void setcolor(const int& k);

/*
	used to hide or show cursor
	on = 0 : hide cursor; on = 1 : show cursor, usually SIZE of a cursor is 10
*/
void setcursor(bool on, DWORD SIZE);

/*
	print content with color at (x,y)
*/
void PrintString(int where_x, int where_y, string content, int color = 15);

/*
	print dynamic content with color at (x,y)
*/
void DynamicPrintString(int where_x, int where_y, vector <string> content, int color = 15);

/*
	Yes/No Check Box
*/
bool YN_Check_Box(int where_x, int where_y);

class Draw
{
private:
	int width, height;
	Location a;
public:
	void DrawBoard(int x, int y, int width, int height);
	Location getLocation();
};

void DrawRec(int x, int y, int width, int height, int = 7);
