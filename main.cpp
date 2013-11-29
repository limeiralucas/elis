#include "elis.h"

int main(int argc, char** argv){
	Instance i;
	if (argv[1])
		i.filename = argv[1];
	File::load_to_buffer(i);
	Screen::update(i);
	while (!(i.exit))
	{
		Keyboard::detect(i);
	}
	return 0;
}