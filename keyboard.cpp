#include "keyboard.h"
#include "console.h"

void Keyboard::detect(Instance &i){
	char key = _getch();
	if (_kbhit()){
		key = _getch();
		switch (key)
		{
		case 75:
			if (i.x > 0)
				i.x--;
			break;
		case 77:
			if (i.x < i.line_buffer.size())
				i.x++;
		default:
			break;
		}
	}
	else
	{
		switch (key){
		case 0x1B:
			Screen::menu(i);
			cout << i.line_buffer;
			break;
		case 0x0D:
			if (i.line - 1 == i.buffer.size())
				i.buffer.push_back(i.line_buffer);
			else
				*(i.buffer_it) = i.line_buffer;
			i.line_buffer.clear();
			i.update();
			Screen::update(i);
			break;
		case 0x08:
			if (!(i.line_buffer.empty())){
				i.line_buffer.erase(i.line_buffer.begin() + i.x - 1);
				Screen::update(i);
				cout << i.line_buffer;
				i.x--;
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
			if (i.x == i.line_buffer.size()){
				i.line_buffer += key;
				cout << key;
			}
			else{
				i.line_buffer.insert(i.x, 1, key);
				Screen::update(i);
				cout << i.line_buffer;
			}
			i.x++;
			break;
		}
	}
	Console::gotoxy(to_string(i.line).size() + 2 + i.x, Console::gety());
}