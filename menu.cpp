#include "menu.h"
#include "cheats.h"

#define GREEN 10
#define RED 12
#define RESET 15

using namespace std;

void PrintGameFound(string programName) {
	cout << "Program: " << programName << endl;
	cout << "Status: FOUND\n";
}
void PrintWaiting(string programName) {
	cout << "Waiting for " << programName << endl;
}
void TerminateCheat() {
	cout << "Cheat Closing\n";
	exit(0);
}

void ClearScreen() {
	system("cls");
}

void PrintStatus() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



	cout << "SUPER MENU V0.4\nCreated by eesak\n\n";

	// BHOP
	cout << "BHOP (INS): ";
	if(bhopStatus)
		SetConsoleTextAttribute(hConsole, GREEN);
	else
		SetConsoleTextAttribute(hConsole, RED);

	cout << (bhopStatus ? "ON\n" : "OFF\n") << std::endl;
	SetConsoleTextAttribute(hConsole, RESET);

	// TRIGGERBOT
	cout << "TRIGGERBOT (DEL): ";
	if (triggerbotStatus)
		SetConsoleTextAttribute(hConsole, GREEN);
	else
		SetConsoleTextAttribute(hConsole, RED);

	cout << (triggerbotStatus ? "ON\n" : "OFF\n") << std::endl;
	SetConsoleTextAttribute(hConsole, RESET);

	// WALLHACK
	cout << "WALLHACK (HOME): ";
	if (wallhackStatus)
		SetConsoleTextAttribute(hConsole, GREEN);
	else
		SetConsoleTextAttribute(hConsole, RED);

	cout << (wallhackStatus ? "ON\n" : "OFF\n") << std::endl;
	SetConsoleTextAttribute(hConsole, RESET);

	// RADAR
	cout << "RADAR (END): ";
	if (radarStatus)
		SetConsoleTextAttribute(hConsole, GREEN);
	else
		SetConsoleTextAttribute(hConsole, RED);

	cout << (radarStatus ? "ON\n" : "OFF\n") << std::endl;
	SetConsoleTextAttribute(hConsole, RESET);
}