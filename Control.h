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
	void ControlLF();

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

