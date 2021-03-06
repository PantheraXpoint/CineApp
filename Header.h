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


enum Screen
{
	Blank = 0,
	mainscreen = 1,
	FilmList = 2,
	Statistics = 3,
	Update = 4,
	roomInfo = 5
};
struct Location
{
	int xmin, ymin;
	int xmax, ymax;
};

struct Seat
{
	int x, y;
};

struct Shot
{
	vector<Seat> seat; 
	static int ShotNumcounter;
	float Revenue = 0;
	int ShotNum;
	int startHour = 0;
	int endHour = 0;
	const int slots = 351;
	Shot() : ShotNum (ShotNumcounter++) {}
	int getAvail_slots()
	{
		return this->slots - seat.size();
		
	}
};

struct Film
{
	Shot FilmShot[5];
	float Revenue = 0;
	string FilmName;
	string Description;
	int Duration;
	static int RoomIDcounter;
	int RoomID;
	Film() : RoomID(RoomIDcounter++) {}
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
	void DrawBoard(int x, int y, int width, int height, int color);
	Location getLocation();
};

void DrawRec(int x, int y, int width, int height, int = 7);
#ifndef __Header_h__
#define __Header_h__
extern const float PRICE;
extern int defShot;
//extern int defFilm
extern Film newFilm[10];
extern int RankIndex[5];
#endif

static int cursor = 1;
static int List_first_film = 1;