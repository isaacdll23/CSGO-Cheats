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
	cout << "SUPER MENU V0.2\n";
	cout << "BHOP: " << (bhopStatus ? "ON\n" : "OFF\n");
	cout << "TRIGGETBOT: " << (triggerbotStatus ? "ON\n" : "OFF\n");
}