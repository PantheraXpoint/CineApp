#include "Control.h"

// Control MainScreen

bool CheckBlank(int& x, int& y)
{
	for (int i = 0; i < newFilm[0].FilmShot[defShot].seat.size(); i++)
	{
		if (x == newFilm[0].FilmShot[defShot].seat[i].x && y == newFilm[0].FilmShot[defShot].seat[i].y)
			return false;
	}
	return true;
}

void Main::PressOption(int &i)
{
	char k; k = _getch();
	if (k == 'a' || (int)k == 75) i -= 1;
	if (k == 'd' || (int)k == 77) i += 1;
	if (i < 0) i = 2;
	if (i > 2) i = 0;
	if ((int)k == 13) this->SwitchScreen = 1;
	else if ((int)k == 27) this->SwitchScreen = -1;
	else this->SwitchScreen = 0;
}
void Main::SwitchChoice(Location& Sell, Location& Statistics, Location& Updates, int &i)
{
	Location Highlight[3];
	Highlight[0].xmin = 50; Highlight[0].ymin = 30;
	Highlight[1].xmin = 100; Highlight[1].ymin = 30;
	Highlight[2].xmin = 160; Highlight[2].ymin = 30;
	if (Highlight[i].xmin > Sell.xmin)
	{
		if (Highlight[i].xmin > Statistics.xmin)
		{
			if (Highlight[i].xmin > Updates.xmin)
			{
				RoomUpdatesIcon(Updates, 10);
			}
			else
			{
				StatisticsIcon(Statistics, 10);
			}
		}
		else
		{
			SellTicketIcon(Sell, 10);
		}
	}
}
void Main::ControlMain(int& A)
{
	Location Title, Sell, Statistics, Updates;
	MainScreen(Title, Sell, Statistics, Updates); 
	while (this->getSCindex() == 0)
	{
		PressOption(this->i);
		setcolor(7);
		MainScreen(Title, Sell, Statistics, Updates);
		SwitchChoice(Sell, Statistics, Updates, i);
	}
	A = this->result();
}
int Main::getI()
{
	return this->i;
}
int Main::getSCindex()
{
	return this->SwitchScreen;
}
int Main::result()
{
	if (this->getSCindex() == -1) {
		this->SwitchScreen = 0;
		return Blank;
	}
	else if (this->getSCindex() == 1) {
		this->SwitchScreen = 0;
		return this->getI() + 2;
	}
}
// Control ListFilm

void ListFilm::PressOption(int& i)
{

}
int ListFilm::UpdateCursor() {
	int keyBoard = getKeyboard();
	(keyBoard == 1) ? cursor -= 2 : // UP
		(keyBoard == 2) ? cursor += 2 ://DOWN
		(keyBoard == 3) ? cursor-- ://LEFT
		(keyBoard == 4) ? cursor++ : cursor = cursor;//RIGHT
	return cursor;
}
void ListFilm::DisplayListBox(int n) { //n: number of films =>1->n 

	int cursor = UpdateCursor(); int Height = ConsoleHeight; int Width = ConsoleWidth;
	if (cursor >= List_first_film + 4) { List_first_film += 2; }
	else if (cursor < List_first_film) { List_first_film -= 2; }

	DisplayBox(true, Height / 6, List_first_film, cursor == List_first_film);
	DisplayBox(false, Height / 6, List_first_film + 1, cursor == List_first_film + 1);
	DisplayBox(true, Height / 1.9, List_first_film + 2, cursor == List_first_film + 2);
	DisplayBox(false, Height / 1.9, List_first_film + 3, cursor == List_first_film + 3);
	DisplayButton(cursor, getKeyboard());
}
int ListFilm::getKeyboard() {
	return keyBoard;
}
void ListFilm::FilmListScreen()
{
	//hello my friend
	const char* Title = "LIST FILM";
	int Width = ConsoleWidth; int Height = ConsoleHeight;
	go(Width / 2 - strlen(Title) / 2, Height / 10);
	cout << Title;
	int n = 10;// number of films
	int i = 1;
	DisplayListBox(n);
}
void ListFilm::Control(int &A)
{
	FilmListScreen();
	int change = 0;
	while (keyBoard != Enter && keyBoard != Back) {
		if (_kbhit())
		{
			int key = _getch();
			switch (key) {
			case 72:
				change++;
				keyBoard = Up;
				break;
			case 80:  
				change++;
				keyBoard = Down;
				break;
			case 75:
				change++;
				keyBoard = Left;
				break;
			case 77:
				change++;
				keyBoard = Right;
				break;
			case 13:
				change++;
				keyBoard = Enter;
				A = roomInfo;
				break;
			case 8:
				change++;
				keyBoard = Back;
				A = mainscreen;
				break;
			default:break;
			}
		}
		if (change) { FilmListScreen(); change--; }
	}
	if (this->keyBoard == Enter || this->keyBoard == Back)
	{
		this->keyBoard = 0;
	}
}
int ListFilm::getSCindex()
{
	return this->SwitchScreen;
}
int ListFilm::result()
{
	if (this->getSCindex() == -1) {
		this->SwitchScreen = 0;
		return mainscreen;
	}
	else if (this->getSCindex() == 1) {
		this->SwitchScreen = 0;
		return roomInfo;
	}
}
// CONTROL ROOMINFO
void RoomInfo::PressOption(int &i)
{
	char k; k = _getch();
	if (k == 'a' || (int)k == 75) i -= 1;
	if (k == 'd' || (int)k == 77) i += 1;
	//if ((int)k == 13) this->SwitchScreen = 1;
	if ((int)k == 27) this->SwitchScreen = -1;
	else this->SwitchScreen = 0;
}
int RoomInfo::MoveCursor(int& x, int& y, Location b)
{
	char k = _getch();
	if (k == 'd')
	{
		if (x + 4 < b.xmax) go(x += 4, y);
		else return 1;
	}
	else if (k == 'a')
	{
		if (x - 4 > b.xmin) go(x -= 4, y);
		else return -1;
	}
	else if (k == 'w')
	{
		if (y - 2 > b.ymin) go(x, y -= 2);
	}
	else if (k == 's')
	{
		if (y + 2 < b.ymax) go(x, y += 2);
	}
	else if (k == 'e')
	{
		if (!CheckBlank(x, y))
		{
			go(x, y);  cout << ' ';
			for (int i = 0; i < newFilm[0].FilmShot[defShot].seat.size(); i++)
			{
				if (x == newFilm[0].FilmShot[defShot].seat[i].x && y == newFilm[0].FilmShot[defShot].seat[i].y)
					newFilm[0].FilmShot[defShot].seat.erase(newFilm[0].FilmShot[defShot].seat.begin() + i);
			}
		}
	}
	else if ((int)k == 27)
	{
		defShot = 0;
		this->SwitchScreen = -1;
	}
	else if (k == 'x')
	{
		if (CheckBlank(x, y))
		{
			cout << k;
			Seat a; a.x = x; a.y = y;
			newFilm[0].FilmShot[defShot].seat.push_back(a);
			if (x + 4 < b.xmax) go(x += 4, y);
		}
	}
	else if ((int)k == 32)
	{
		return 2;
	}
	return 0;
}
void RoomInfo::Cursor(Draw A[], int index)
{
	setcolor(7); RoomInfoScreen();
	int i = A[index].getLocation().xmin - 2, j = A[index].getLocation().ymin + 1; int k;
	for (int m = 0; m < newFilm[0].FilmShot[defShot].seat.size(); m++)
	{
		go(newFilm[0].FilmShot[defShot].seat[m].x, newFilm[0].FilmShot[defShot].seat[m].y);  cout << 'x';
	}
	while (this->getSCindex() == 0)
	{
		k = MoveCursor(i, j, A[index].getLocation());
		if (k == 1 && index < 2)
		{
			index++; if (index > 2) index = 2;
			i = A[index].getLocation().xmin + 2;
			go(i, j);
		}
		else if (k == -1 && index > 0)
		{
			index--; if (index < 0) index = 0;
			i = A[index].getLocation().xmax - 2;
			go(i, j);
		}
		else if (k == 2)
		{
			if (defShot + 1 < 5) defShot += 1;
			else defShot = 0;
			this->SwitchScreen = 1;
		}
	}
}
void RoomInfo::Avail_slots()
{

}
void RoomInfo::ChooseSlot()
{

}
void RoomInfo::SwitchShot()
{

}
void RoomInfo::ControlRI(int& B)
{
	Draw A[3];
	A[0].DrawBoard(75, 13, 7, 13); A[1].DrawBoard(112, 13, 13, 13);
	A[2].DrawBoard(172, 13, 7, 13); setcursor(true, 10); int index = 0;
	Cursor(A, index);
	B =  this->result();
}
int RoomInfo::getSCindex()
{
	return this->SwitchScreen;
}
int RoomInfo::result()
{
	if (this->getSCindex() == -1) {
		this->SwitchScreen = 0;
		return FilmList;
	}
	else if (this->getSCindex() == 1)
	{
		this->SwitchScreen = 0;
		return roomInfo;
	}
}
// CONTROL STATISTICS
void Stat::PressOption(int& i)
{
	char k; k = _getch();
	if (k == 'a' || (int)k == 75) i -= 1;
	if (k == 'd' || (int)k == 77) i += 1;
	if (i < 0) i = 4;
	if (i > 4) i = 0;
	if ((int)k == 27) this->SwitchScreen = -1;
	else this->SwitchScreen = 0;
}
void Stat::SwitchBar()
{

}
void Stat::DetailStat()
{

}
void Stat::GeneralStat()
{

}
void Stat::ControlStatistics(int& A)
{
	StatisticScreen(); int i = -1;
	while (this->getSCindex() == 0)
	{
		PressOption(i);
		//StatisticScreen();
		BarGraph(i, 10);
	}
	A = this->result();
}
int Stat::getSCindex()
{
	return this->SwitchScreen;
}
int Stat::result()
{
	if (this->getSCindex() == -1) {
		this->SwitchScreen = 0;
		return mainscreen;
	}
}
// Control Update
void Update::ControlAdd()
{

}
void Update::ControlEdit()
{

}
void Update::ControlDelete()
{

}
void Update::ControlUpdate()
{

}
