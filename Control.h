#include "Display.h"

// Control MainScreen

class Main
{
private:

public:
	int PressOption(int &i);
	void SwitchChoice(Location& Sell, Location& Statistics, Location& Updates, int &i);
	void ControlMain();
};
// Control ListFilm  //////// Tri Huynh
class ListFilm
{
private:

public:
	enum Button {
		Up = 1,
		Down = 2,
		Left = 3,
		Right = 4,
		Enter = 5,
		Back = 6
	};
	static int keyBoard = 0;
	int getKeyboard();
	void Control();
	int UpdateCursor();
	void DisplayListBox(int n);//n: number of films =>1->n 

};
// Control RoomInfo
class RoomInfo
{
private:

public:
	int PressOption(int &i);
	int MoveCursor(int& x, int& y, Location b);
	void Cursor(Draw A[], int index);
	void Avail_slots();
	void ChooseSlot();
	void SwitchShot();
	void ControlRI();
};

// Control Statistics
class Stat
{
private:

public:
	int PressOption(int& i);
	void SwitchBar();
	void DetailStat();
	void GeneralStat();
	void ControlStatistics();
};

// Control Update
class Update
{
private:

public:
	void ControlAdd();
	void ControlEdit();
	void ControlDelete();
	void ControlUpdate();
};

