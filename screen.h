#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <iostream>
#include <cstdlib>
#include "instance.h"
#include "file.h"
#include <conio.h>

class Screen{
public:
	static void clear();
	static void help();
	static void update(Instance &i);
	static void updateRange(Instance &i, int start, int end);
};

#endif
