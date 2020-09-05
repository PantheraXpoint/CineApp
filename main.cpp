#include "Display.h"


int main()
{
	string a = "fsdhfdjkahfajkfhskalhjkfahsfjk\n";
	for (int i = 0; i < 10; i++)
	{
		cout << a ; 
		setcolor(i);
		PrintString(0, i, a, i);
	}
	system("pause");
	return 0;
}