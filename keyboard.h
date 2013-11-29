#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "instance.h"
#include "screen.h"
#include "conio.h"

class Keyboard{
public:
	static void detect(Instance &i);
};

#endif