#ifndef _ELIS_CONSOLE_
#define _ELIS_CONSOLE_

#include <Windows.h>

class Console{
public:
	static void gotoxy(int x, int y);
	static int gety();
};
#endif


