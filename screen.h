#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <iostream>
#include "instance.h"
#include "file.h"
#include <conio.h>

class Screen{
public:
	#ifdef _WIN32
	static void clear(){ system("cls"); }
	#else
	static void clear(){ /*clear da courses.h*/ }
	#endif

	static void update(Instance &i);

	static void menu(Instance &i);
};

#endif