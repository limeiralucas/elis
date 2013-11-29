#include <iostream>
#ifdef _WIN32
#include <conio.h>
#else
#include <curses.h>
#endif

using namespace std;

#include "instance.h"
#include "file.h"
#include "screen.h"
#include "keyboard.h"

int main(int argc, char** argv){
	Instance i;
	if (argv[1])
		i.filename = argv[1];
	Keyboard kb;
	File::load_to_buffer(i);
	Screen::update(i);
	while (!(i.exit))
	{
		kb.detect(i);
	}
	return 0;
}