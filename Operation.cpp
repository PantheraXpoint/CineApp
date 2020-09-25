#include "Operation.h"



void input(Film* newFilm)
{
	const char* nameFilm[10] = { "Jurassic","Titanic","Annabelle","Robot", "Conqueror", "Godzilla", "Transformer","Prison Break","Sex Education","Spirited Away" };
	for (int i = 0; i < 10; i++) {
		newFilm[i].FilmName = nameFilm[i]; newFilm[i].Description = "Excellent!!"; newFilm[i].Duration = 2;
		for (int j = 0; j < 5; j++)
		{
			if (j == 0)
			{
				newFilm[i].FilmShot[j].startHour = 8;
				newFilm[i].FilmShot[j].endHour = 8 + newFilm[i].Duration;
			}
			else
			{
				newFilm[i].FilmShot[j].startHour = newFilm[i].FilmShot[j - 1].startHour + newFilm[i].Duration + 1;
				newFilm[i].FilmShot[j].endHour = newFilm[i].FilmShot[j].startHour + newFilm[i].Duration;
			}
		}
	}

}
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