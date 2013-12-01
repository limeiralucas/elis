#include "keyboard.h"
#include "menu.h"

void Keyboard::detect(Instance &i){
	char key = _getch();
	if (_kbhit()){
		key = _getch();
		switch (key)
		{
		case 75:
			//LEFT
			break;
		case 77:
			//RIGHT
		default:
			break;
		}
	}
	else
	{
		switch (key){
		case 0x1B:
			Menu::detect(i);
			cout << i.buffer.line_buffer;
			break;
		case 0x0D:
			i.buffer.insert();
			i.saved = false;
			Screen::update(i);
			if (i.buffer.mode == EDIT)
				cout << i.buffer.line_buffer;
			break;
		case 0x08:
			if (!(i.buffer.line_buffer.empty())){
				cout << "\b \b";
				i.buffer.line_buffer.pop_back();
			}
			break;
		default:
			cout << key;
			i.buffer.line_buffer += key;
			break;
		}
	}
}