#include "Operation.h"

int Shot::ShotNumcounter = 1;
int Film::RoomIDcounter = 1;
int main(void)
{
	
	//FixConsoleWindow();
	input(newFilm);
	for (int i = 0; i < 10; i++)
	{
		cout << newFilm[i].FilmName << ' ';
	}
	system("pause");
	return 0;
}