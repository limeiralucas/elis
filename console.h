#ifndef _ELIS_CONSOLE_
#define _ELIS_CONSOLE_

#ifdef _WIN32 || _WIN64
#include <Windows.h>

class Console{
public:
	static void gotoxy(int x, int y);
	static int gety();
};

#endif
#endif


