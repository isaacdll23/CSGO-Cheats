#include "menu.h"
#include "cheats.h"

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
	cout << "SUPER MENU V0.3\nCreated by Isaac\n\n";
	cout << "BHOP: " << (bhopStatus ? "ON\n" : "OFF\n");
	cout << "TRIGGERBOT: " << (triggerbotStatus ? "ON\n" : "OFF\n");
	cout << "WALLHACK: " << (wallhackStatus ? "ON\n" : "OFF\n");
}