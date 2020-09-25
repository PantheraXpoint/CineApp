#include "Display.h"

// Control MainScreen
bool CheckBlank(int& x, int& y);
class Main
{
private:
	int SwitchScreen = 0;
	int i = -1;
public:
	void PressOption(int& i);
	void SwitchChoice(Location& Sell, Location& Statistics, Location& Updates, int& i);
	void ControlMain(int& A);
	int getSCindex();
	int getI();
	int result();
};
// Control ListFilm  //////// Tri Huynh
class ListFilm
{
private:
	int keyBoard = 0;
	int SwitchScreen = 0;
public:
	enum Button {
		Up = 1,
		Down = 2,
		Left = 3,
		Right = 4,
		Enter = 5,
		Back = 6
	};
	void PressOption(int& i);
	int getKeyboard();
	void Control(int& A);
	void UpdateCursor(int n);//n: number of films =>1->n 
	void DisplayListBox(int n);//n: number of films =>1->n 
	void FilmListScreen();
	int getSCindex();
	int result();
};
// Control RoomInfo
class RoomInfo
{
private:
	int SwitchScreen = 0;
public:
	void PressOption(int& i);
	int MoveCursor(int& x, int& y, Location b);
	void Cursor(Draw A[], int index);
	void Avail_slots();
	void ChooseSlot();
	void SwitchShot();
	void ControlRI(int& A);
	int getSCindex();
	int result();
};

// Control Statistics
class Stat
{
private:
	int SwitchScreen = 0;
public:
	void PressOption(int& i);
	void SwitchBar();
	void DetailStat();
	void GeneralStat();
	void ControlStatistics(int& A);
	int getSCindex();
	int result();
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

