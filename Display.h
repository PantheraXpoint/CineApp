#include "Header.h"
#define ConsoleWidth 210;
#define ConsoleHeight 50;

void input(Film* newFilm);
// Main Screen UI
void AppTitle(int x, int y);
void SellTicketIcon(Location a, int = 7);
void StatisticsIcon(Location a, int = 7);
void RoomUpdatesIcon(Location a, int = 7);
void MainScreen(Location& Title, Location& Sell, Location& Statistics, Location& Updates);

// Film List and Search Screen ///// TRI HUYNH
//void FilmListScreen();
void DisplayBox(bool side, int posY, int filmth, bool highLight);
void DisplayButton(int _cursor, int KeyBoard);

// Room Detail Screen
void Border();
void RoomInfoIcon(Location a, Location b);
void screen(Location a);
void RoomInfoContent();
void FrameDecor();
void Arrow(Location a);
void RoomInfoScreen();

// Statistics Screen
void BarFrame();
void Border2(int x, int y, int Width, int Height);
void BarGraph(int bar, int color);
void StatisticsLetter(Location a);
void StatisticScreen();

// Update Room Screen
void UpdateRoomIcon(Location a);
void EditIcon(Location a);
void DeleteIcon(Location a);
void AddIcon(Location a);
void UpdateRoomScreen();

// Confirmation Screen
bool ConfirmScreen();

// ADD Room Screen
void AddRoomScreen();

// EDIT Room Screen
void EditRoomScreen();