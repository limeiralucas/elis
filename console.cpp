#include "console.h"

void Console::gotoxy(int x, int y){
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

int Console::gety(){
	CONSOLE_SCREEN_BUFFER_INFO csb;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csb);

	return csb.dwCursorPosition.Y;
}