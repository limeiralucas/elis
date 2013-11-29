#include "keyboard.h"

void Keyboard::detect(Instance &i){
	char key = _getch();
	if (_kbhit()){
		key = _getch();
	}
	else
	{
		switch (key){
		case 0x1B:
			Screen::menu(i);
			cout << i.line_buffer;
			break;
		case 0x0D:
			if (i.line == i.buffer.size())
				i.buffer.push_back(i.line_buffer);
			else
				i.buffer.insert(i.buffer_it, i.line_buffer);
			i.line_buffer.clear();
			i.update();
			Screen::update(i);
			break;
		case 0x08:
			if (!(i.line_buffer.empty())){
				i.line_buffer.erase(i.line_buffer.end() - 1);
				cout << "\b \b";
			}
			else
			{
				if (i.line > 1){
					i.line_buffer = i.buffer.back();
					i.buffer.pop_back();
					i.update();
					Screen::update(i);
					cout << i.line_buffer;
				}
			}
			break;
		default:
			i.line_buffer += key;
			cout << key;
			break;
		}
	}
}