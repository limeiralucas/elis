#include "keyboard.h"
#include "menu.h"
#include "console.h"

void Keyboard::detect(Instance &i){
	char key = _getch();
	if (_kbhit()){
		key = _getch();
		switch (key)
		{
		case 75:
			if(i.cursor > 0)
				Console::gotoxy(--i.cursor, Console::gety());
			break;
		case 77:
			if(i.cursor < i.buffer.line_buffer.size())
				Console::gotoxy(++i.cursor, Console::gety());
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
			if (i.buffer.mode == EDIT){
				cout << i.buffer.line_buffer;
				i.cursor = i.buffer.line_buffer.size();
			} else
				i.cursor = 0;
			break;
		case 0x08:
			if (!(i.buffer.line_buffer.empty())){
				i.buffer.line_buffer.erase(--i.cursor, 1);
				Screen::update(i);
				cout << i.buffer.line_buffer;
				Console::gotoxy(i.cursor, Console::gety());
			}
			break;
		default:
			if(i.cursor == i.buffer.line_buffer.size()){
				cout << key;
				i.buffer.line_buffer += key;
			}
			else{
				i.buffer.line_buffer.insert(i.cursor, 1, key);
				Screen::update(i);
				cout << i.buffer.line_buffer;
				Console::gotoxy(i.cursor, Console::gety());
			}
			i.cursor++;
			break;
		}
	}
}
