#include "Display.h"

// Main Screen UI
void AppTitle(int x, int y)
{
	go(x, y);
	cout << "   _|_|_|    |_|                            _|_|                           "; ++y; go(x, y);
	cout << " _|                _|_|_|       _|_|      _|    _|  _|_|_|    _|_|_|       "; ++y; go(x, y);
	cout << " _|          |_|    _|   _|   _|_|_|_|    _|_|_|_|  _|    _|  _|    _|     "; ++y; go(x, y);
	cout << " _|          |_|    _|    _|   _|         _|    _|  _|    _|  _|    _|     "; ++y; go(x, y);
	cout << "   _|_|_|    |_|    _|    _|    _|_|_|    _|    _|  _|_|_|    _|_|_|       "; ++y; go(x, y);
	cout << "                                                    _|        _|           "; ++y; go(x, y);
	cout << "                                                    _|        _|           ";
}
void SellTicketIcon(Location a, int k )
{
	int x = a.xmin, y = a.ymin;
	DrawRec(a.xmin - 2, a.ymin - 1, 6, 5,k);
	go(x, y);	setcolor(k);
	cout << "     '-."; ++y; go(x, y);
	cout << "        '-. _____"; ++y; go(x, y);
	cout << " .-._      |     '."; ++y; go(x, y);
	cout << ":  ..      |      :"; ++y; go(x, y);
	cout << "'-._+      |    .-'"; ++y; go(x, y);
	cout << " /  |     .'i--i"; ++y; go(x, y);
	cout << "/    | .-'_/____|___"; ++y; go(x, y);
	cout << "    .-'  :"; 
}
void StatisticsIcon(Location a, int k)
{
	int x = a.xmin, y = a.ymin;
	DrawRec(a.xmin - 3, a.ymin - 2, 4, 6,k);
	go(x, y); setcolor(k);
	cout << " __________"; ++y; go(x, y);
	cout << "| ________ |"; ++y; go(x, y);
	cout << "||12345678||"; ++y; go(x, y);
	cout << "|**********|"; ++y; go(x, y);
	cout << "|[M|#|C][-]|"; ++y; go(x, y);
	cout << "|[7|8|9][+]|"; ++y; go(x, y);
	cout << "|[4|5|6][x]|"; ++y; go(x, y);
	cout << "|[1|2|3][%]|"; ++y; go(x, y);
	cout << "|[.|O|:][=]|"; ++y; go(x, y);
	cout << "------------";
}
void RoomUpdatesIcon(Location a, int k )
{
	int x = a.xmin, y = a.ymin;	
	DrawRec(a.xmin - 3, a.ymin - 1, 5, 5,k);
	go(x, y); setcolor(k);
	cout << "      |_|"; ++y; go(x, y);
	cout << "     (* *)"; ++y; go(x, y);
	cout << "    __)#(__"; ++y; go(x, y);
	cout << "   ( )...( )(_)"; ++y; go(x, y);
	cout << "   || |_| ||//"; ++y; go(x, y);
	cout << ">==() | | ()/"; ++y; go(x, y);
	cout << "    _(___)_"; ++y; go(x, y);
	cout << "   [-]   [-]"; 
}


void MainScreen(Location &Title, Location& Sell, Location& Statistics, Location& Updates)
{
	Border();
	int Width = ConsoleWidth; int Height = ConsoleHeight;
	Title.xmin = Width / 2 - 38; 
	Title.ymin = Height / 5; 
	AppTitle(Title.xmin, Title.ymin);
	Sell.xmin = (Width - 16 - 17 - 24) / 4; 
	Sell.ymin = Title.ymin + 6 + 7; 
	SellTicketIcon(Sell);
	Statistics.xmin = Sell.xmin + 23 + (Width - 16 - 17 - 24) / 4; 
	Statistics.ymin = Title.ymin + 6 + 7; 
	StatisticsIcon(Statistics);
	Updates.xmin = (Width - 16 - 17 - 24) / 4 + Statistics.xmin + 15;
	Updates.ymin = Title.ymin + 6 + 7; 
	RoomUpdatesIcon(Updates);
	go(Sell.xmin + 23, Sell.ymin + 20); setcolor(7);
	cout << "PRESS '<' and '>' for moving ||||||| PRESS [ENTER] for choosing\n";
}

// Film List and Search Screen
void FilmListScreen()
{
	//hello my friend
}

// Room Detail Screen
void Border()
{
	int Width = ConsoleWidth; int Height = ConsoleHeight;
	int x = 0, y = 0;
	go(x, y);
	cout << " __| |"; 
	for (int i = 0; i < Width - 11; i++) cout << "_";
	cout <<"| |__"; go(x, ++y);
	cout << "(__   ";
	for (int i = 0; i < Width - 11 ; i++) cout << "_";
	cout << "   __)"; go(x, ++y);
	for (int i = 0; i < Height - 4; i++)
	{
		cout << "   | |";
		go(Width - 5,y);
		cout << "| |"; go(x, ++y);
	}
	cout << " __| |";
	for (int i = 0; i < Width - 11; i++) cout << "_";
	cout << "| |__"; go(x, ++y);
	cout << "(__   "; 
	for (int i = 0; i < Width - 11; i++) cout << "_";
	cout << "   __)"; go(x, ++y);
	cout << "   | |";
	for (int i = 0; i < Width - 11; i++) cout << " ";
	cout << "| |"; go(x, ++y);
}
void RoomInfoIcon(Location a,Location b)
{
	int x = a.xmin, y = a.ymin;
	go(x, y);
	cout << "	   ___  ____  ____  __  ___"; go(x, ++y);
	cout << "	  / _ |/ __ |/ __ |/  |/  /";  go(x, ++y);
	cout << "	 / , _/ /_/ / /_/ / /|_/ /"; go(x, ++y);
	cout << "	/_/|_||____/|____/_/  /_/"; go(x, ++y);
	int X = b.xmin, Y = b.ymin;
	go(X, Y);
	cout << "   _____  __________  ___  __  ______ ______________  _  __"; go(X, ++Y);
	cout << "  /  _/ |/ / __/ __ |/ _ |/  |/  / _ /_  __/  _/ __ |/ |/ /"; go(X, ++Y);
	cout << " _/ //    / _// /_/ / , _/ /|_/ / __ |/ / _/ // /_/ /    /"; go(X, ++Y);
	cout << "/___/_/|_/_/  |____/_/|_/_/  /_/_/ |_/_/ /___/|____/_/|_/"; go(X, ++Y);
}
void screen(Location a)
{
	int x = a.xmin, y = a.ymin;
	go(x, y);
	cout << " ___  ___ _ __ ___  ___ _ __  "; go(x, ++y);
	cout << "/ __|/ __| '__/ _ |/ _ | '_ | "; go(x, ++y);
	cout << "|__ | (__| | |  __/  __/ | ||"; go(x, ++y);
	cout << "|___/|___|_|  |___|___|_| |_|"; go(x, ++y);
}
void RoomInfoContent()
{
	int i = 22;
	go(20, i); cout << " ROOM ID: "; i += 4;
	go(20, i); cout << " SHOT NO.: "; i += 4;
	go(20, i); cout << " START TIME: "; i += 4;
	go(20, i); cout << " END TIME: "; i += 4;
	go(20, i); cout << " DURATION: "; i += 4;
	go(20, i); cout << " AVAILABLE SLOTS: "; i += 4;
	go(130, 42); cout << "[INSTRUCTION]"; int k = 8;
	go(72, k); cout << "I"; go(72, ++k); cout << "N";
	go(72, ++k); cout << "L"; go(72, ++k); cout << "E";
	go(72, ++k); cout << "T";
	k = 9;
	go(203, k); cout << "E"; go(203, ++k); cout << "X";
	go(203, ++k); cout << "I"; go(203, ++k); cout << "T";
}
void FrameDecor()
{
	int Height = ConsoleHeight; int Width = ConsoleWidth;
	for (int i = 2; i < Height - 1; i++)
	{
		go(70, i);  cout << "|";
	}
	for (int i = 6; i < 70; i++)
	{
		go(i, 15); cout << "_";
	}
	for (int i = 71; i < Width - 4; i++)
	{
		go(i, 6); cout << "_";
	}
	
}
void Arrow(Location a)
{
	int x = a.xmin, y = a.ymin;
	go(x, y);
	cout << ">>>_____|`-._"; go(x, ++y);
	cout << ">>>     |.-'"; go(x, ++y);
}
void RoomInfoScreen()
{
	Location Room,Info,Screen; Room.xmin = 20; Room.ymin = 3;
	Info.xmin = 10; Info.ymin = 8; Screen.xmin = 120; Screen.ymin = 2;
	Location arrow1; arrow1.xmin = 75; arrow1.ymin = 9;
	Location arrow2; arrow2.xmin = 188; arrow2.ymin = 9;
	RoomInfoIcon(Room,Info);
	screen(Screen);
	Arrow(arrow1); Arrow(arrow2);																																																													
	DrawRec(17, 19, 10, 13); DrawRec(87, 41, 25, 3);
	DrawRec(201, 7, 1, 3); DrawRec(70, 7, 1, 3);
	RoomInfoContent(); FrameDecor(); Border();																																	
}

// Statistics Screen
void Border2(int x, int y, int Width, int Height)
{
	go(x, y);
	cout << "   ";
	for (int i = 0; i < Width - 10; i++) cout << "_";
	go(x, ++y);
	cout << " /  |";
	go(x + Width - 7, y); cout << "|.";
	go(x, ++y);
	cout << "|   |";
	go(x + Width - 7, y); cout << "|.";
	go(x, ++y); cout << " |_ |";
	go(x + Width - 7, y); cout << "|.";
	for (int i = 0; i < Height - 7; i++)
	{
		go(x, ++y); cout << "    |";
		go(x + Width - 7, y); cout << "|.";
	}
	go(x, ++y);	cout << "    |   ";
	for (int i = 0; i < Width - 15; i++) cout << "_";
	cout << "|___";
	go(x, ++y);	cout << "    |  /";
	go(x + Width - 7, y); cout << "   /.";
	go(x, ++y);	cout << "    | /_";
	for (int i = 0; i < Width - 15; i++) cout << "_";
	cout << "__/.";
}
void BarFrame()
{
	int Height = ConsoleHeight; int Width = ConsoleWidth;
	for (int i = 17; i < Height - 5; i++)
	{
		go(70, i);  cout << char(179);
	}
	for (int i = 71; i < Width - 10; i++)
	{
		go(i, Height - 6); cout << "_";
	}
}
void BarGraph(int bar, int color)
{
	int Height = ConsoleHeight; int Width = ConsoleWidth;
	if (bar == 0) DrawRec(80, Height - 12, 3, 3, color);
	else DrawRec(80, Height - 12, 3, 3);
	for (int i = 71; i < 80; i++)
	{
		go(i, Height - 12); cout << "-";
	}
	if (bar == 1) DrawRec(100, Height - 16, 3, 5,color);
	else DrawRec(100, Height - 16, 3, 5);
	for (int i = 71; i < 100; i++)
	{
		go(i, Height - 16); cout << "-";
	}
	if (bar == 2) DrawRec(120, Height - 20, 3, 7, color);
	else DrawRec(120, Height - 20, 3, 7);
	for (int i = 71; i < 120; i++)
	{
		go(i, Height - 20); cout << "-";
	}
	if (bar == 3) DrawRec(140, Height - 24, 3, 9, color);
	else DrawRec(140, Height - 24, 3, 9);
	for (int i = 71; i < 140; i++)
	{
		go(i, Height - 24); cout << "-";
	}
	if (bar == 4)DrawRec(160, Height - 28, 3, 11, color);
	else DrawRec(160, Height - 28, 3, 11);
	for (int i = 71; i < 160; i++)
	{
		go(i, Height - 28); cout << "-";
	}
}
void StatisticsLetter(Location a)
{
	int x = a.xmin, y = a.ymin;
	go(x, y);
	cout << " .oooooo..o ooooooooooooo       .o.       ooooooooooooo ooooo  .oooooo..o ooooooooooooo ooooo   .oooooo.    .oooooo..o "; go(x, ++y);
	cout << "d8P'    `Y8 8'   888   `8      .888.      8'   888   `8 `888' d8P'    `Y8 8'   888   `8 `888'  d8P'  `Y8b  d8P'    `Y8 "; go(x, ++y);
	cout << "Y88bo.           888          .8'888.          888       888  Y88bo.           888       888  888          Y88bo.      "; go(x, ++y);
	cout << " `'Y8888o.       888         .8' `888.         888       888   `'Y8888o.       888       888  888           `'Y8888o.  "; go(x, ++y);
	cout << "    `'Y88b       888        .88ooo8888.        888       888       `'Y88b      888       888  888               `'Y88b "; go(x, ++y);
	cout << "oo     .d8P      888       .8'     `888.       888       888  oo     .d8P      888       888  `88b    ooo  oo     .d8P "; go(x, ++y);
	cout << "8''88888P'      o888o     o88o     o8888o     o888o     o888o 8''88888P'      o888o     o888o  `Y8bood8P'  8''88888P'  "; go(x, ++y);
}
void StatisticScreen()
{
	Border(); BarFrame();
	Border2(11, 18, 60, 26);
	Location Statistics; Statistics.xmin = 50; Statistics.ymin = 7;
	StatisticsLetter(Statistics);
}

// Update Room Screen
void UpdateRoomIcon(Location a)
{
	int x = a.xmin, y = a.ymin;
	go(x, y);
	cout << "  _    _           _       _              _____       "; go(x, ++y);
	cout << " | |  | |         | |     | |            |  __ |     "; go(x, ++y);
	cout << " | |  | |_ __   __| | __ _| |_ ___       | |__) |___   ___  _ __ ___  "; go(x, ++y);
	cout << " | |  | | '_ | / _` |/ _` | __/ _ |      |  _  // _ | / _ || '_ ` _ | ";  go(x, ++y);
	cout << " | |__| | |_) | (_| | (_| | ||  __/      | | | | (_)|| (_)| | | | | |"; go(x, ++y);
	cout << " |____/| .__/ |__,_||__,_||__|___|       |_| |_|___/ |___/|_| |_| |_|"; go(x, ++y);
	cout << "        | |          "; go(x, ++y);
	cout << "        |_|         "; go(x, ++y);
}
void EditIcon(Location a)
{
	int x = a.xmin, y = a.ymin;
	go(x, y);
	cout << "	   .---."; go(x, ++y);
	cout << "       |---|"; go(x, ++y);
	cout << "       |---|"; go(x, ++y);
	cout << "       |---|"; go(x, ++y);
	cout << "   .---^ - ^---."; go(x, ++y);
	cout << "   :___________:"; go(x, ++y);
	cout << "      |  |//|"; go(x, ++y);
	cout << "      |  |//|"; go(x, ++y);
	cout << "      |  |//|"; go(x, ++y);
	cout << "      |  |//|"; go(x, ++y);
	cout << "      |  |//|"; go(x, ++y);
	cout << "      |  |//|"; go(x, ++y);
	cout << "      |  |.-|"; go(x, ++y);
	cout << "      |.-'**|"; go(x, ++y);
	cout << "       |***|"; go(x, ++y);
	cout << "        |*|"; go(x, ++y);
	cout << "         V"; go(x - 4, y += 1);
	cout << "    ______     __  _   __ "; go(x - 4, ++y);
	cout << "   / ____/____/ / (_) / /_"; go(x - 4, ++y);
	cout << "  / __/  / __  / / / / __/"; go(x - 4, ++y);
	cout << " / /___ / /_/ / / / / /_  "; go(x - 4, ++y);
	cout << "/_____/ |__,_/ /_/  |__/ "; go(x - 4, ++y);
}
void DeleteIcon(Location a)
{
	int x = a.xmin, y = a.ymin;
	go(x, y);
	cout << "      ##        ##"; go(x, ++y);
	cout << "       ##      ##"; go(x, ++y);
	cout << "        ##|--|##"; go(x, ++y);
	cout << "       | ##  ## |"; go(x, ++y);
	cout << "      |___####___|"; go(x, ++y);
	cout << "     |~~~~####~~~~|"; go(x, ++y);
	cout << "      ===##==##==="; go(x, ++y);
	cout << "     |..##....##..|"; go(x, ++y);
	cout << "    |..##......##..|"; go(x, ++y);
	cout << "   |..##........##..|"; go(x, ++y);
	cout << "  |........__........|"; go(x, ++y);
	cout << " |........|__|........|   "; go(x, ++y);
	cout << "|_________|__|_________|"; go(x - 7, y += 5);
	cout << "    ____           __         __       "; go(x - 7, ++y);
	cout << "   / __ |  ___    / /  ___   / /_  ___ "; go(x - 7, ++y);
	cout << "  / / / / / _ |  / /  / _ | / __/ / _ |"; go(x - 7, ++y);
	cout << " / /_/ / /  __/ / /  /  __// /_  /  __/"; go(x - 7, ++y);
	cout << "/_____/  |___/ /_/   |___/ |__/  |___/ "; go(x - 7, ++y);
}
void AddIcon(Location a)
{
	int x = a.xmin, y = a.ymin;
	go(x, y);
	cout << "___________________"; go(x, ++y);
	cout << "|       | |       |"; go(x, ++y);
	cout << "|       | |       |"; go(x, ++y);
	cout << "|       | |       |"; go(x, ++y);
	cout << "|_______| |_______|"; go(x, ++y);
	cout << "|_______   _______|"; go(x, ++y);
	cout << "|       | |       |"; go(x, ++y);
	cout << "|       | |       |"; go(x, ++y);
	cout << "|       | |       |"; go(x, ++y);
	cout << "|       | |       |"; go(x, ++y);
	cout << "|       | |       |"; go(x, ++y);
	cout << "|       | |       |"; go(x, ++y);
	cout << "|       | |       |"; go(x, ++y);
	cout << "|_______|_|_______|"; go(x - 2, y += 4);
	cout << "    ___       __    __"; go(x - 2, ++y);
	cout << "   /   | ____/ /___/ /"; go(x - 2, ++y);
	cout << "  / /| |/ __  / __  / "; go(x - 2, ++y);
	cout << " / ___ / /_/ / /_/ /  "; go(x - 2, ++y);
	cout << "/_/  |_|__,_/|__,_/   "; go(x - 2, ++y);
}
void UpdateRoomScreen()
{
	Location Add; Add.xmin = 50; Add.ymin = 15;
	Location Edit; Edit.xmin = 100; Edit.ymin = 15;
	Location Delete; Delete.xmin = 150; Delete.ymin = 15;
	Location Update; Update.xmin = 75; Update.ymin = 5;
	EditIcon(Edit); AddIcon(Add); DeleteIcon(Delete);
	DrawRec(60, 41, 25, 3);
	go(105, 42); cout << "[INSTRUCTION]";
	UpdateRoomIcon(Update); Border();
	
}

// Confirmation Screen
bool ConfirmScreen()
{
	return true;
}

// ADD Room Screen
void AddRoomScreen()
{

}

// EDIT Room Screen
void EditRoomScreen()
{

}
