#include "Operation.h"

void operation()
{
	input(newFilm);
	int A = 1; Main a; Stat c; RoomInfo d; ListFilm b;
	while (A != 0)
	{
		switch (A)
		{
		case Blank:
			break;
		case mainscreen:
			system("cls");
			a.ControlMain(A);
			//A = a.result();
			break;
		case FilmList:
			system("cls");
			b.Control(A);
			break;
		case Statistics:
			system("cls");
			c.ControlStatistics(A);
			//A = c.result();
			break;
		case roomInfo:
			system("cls");
			d.ControlRI(A);
			//A = b.result();
			break;
		}
	}
}


