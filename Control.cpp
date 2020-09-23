#include "Control.h"

// Control MainScreen

int Main::PressOption(int &i)
{
	char k; k = _getch();
	if (k == 'a' || (int)k == 75) i -= 1;
	if (k == 'd' || (int)k == 77) i += 1;
	if (i < 0) i = 2;
	if (i > 2) i = 0;
	return 0;
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
void Main::ControlMain()
{
	Location Title, Sell, Statistics, Updates;
	MainScreen(Title, Sell, Statistics, Updates); 
	int i = -1;
	while (1)
	{
		int temp = PressOption(i);
		setcolor(7);
		MainScreen(Title, Sell, Statistics, Updates);
		SwitchChoice(Sell, Statistics, Updates, i);
	}
}
// Control ListFilm
void ListFilm::ControlLF()
{

}
// Control RoomInfo
int RoomInfo::PressOption(int &i)
{
	char k; k = _getch();
	//cin >> k;
	if (k == 'a' || (int)k == 75) i -= 1;
	if (k == 'd' || (int)k == 77) i += 1;
	if ((int)k == 13) return 1;
	if ((int)k == 27) return -1;
	return 0;
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
		go(x, y);  cout << ' ';
	}
	else
	{
		cout << k;
	}
	return 0;
}
void RoomInfo::Cursor(Draw A[], int index)
{
	int i = A[index].getLocation().xmin - 2, j = A[index].getLocation().ymin + 1; int k;
	while (1)
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
void RoomInfo::ControlRI()
{
	Draw A[3];
	A[0].DrawBoard(75, 13, 7, 13); A[1].DrawBoard(112, 13, 13, 13);
	A[2].DrawBoard(172, 13, 7, 13); setcursor(true, 10); int index = 0;
	RoomInfoScreen(); Cursor(A, index); 
	int i = -1;
	while (1)
	{
		int temp = PressOption(i);
		setcolor(7);
		RoomInfoScreen();
		if (temp == 1)
		{
			break;
		}
		else if (temp == -1)
		{
			system("cls");
			Main a;
			a.ControlMain(); break;
		}
		else
		{
			system("cls");
			RoomInfoScreen();
		}

	}
}
// Control Statistics
int Stat::PressOption(int& i)
{
	char k; k = _getch();
	if (k == 'a' || (int)k == 75) i -= 1;
	if (k == 'd' || (int)k == 77) i += 1;
	if (i < 0) i = 4;
	if (i > 4) i = 0;
	return 0;
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
void Stat::ControlStatistics()
{
	StatisticScreen(); int i = -1;
	while (1)
	{
		PressOption(i);
		BarGraph(i, 10);
		
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
