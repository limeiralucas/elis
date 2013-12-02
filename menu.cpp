#include <iostream>
#include <conio.h>
#include "menu.h"
#include "file.h"
#include "text.h"
#include "screen.h"

void Menu::detect(Instance &i){
	string line;
	string cmd[3];

	cout << "\n: ";
	getline(cin, line);
	Text::trimht(line);
	if (!(line.empty())){
		cmd[0] = line.substr(0, line.find_first_of(' '));
		line.erase(0, line.find_first_of(' '));
		Text::trimht(line);
		cmd[1] = line.substr(0, line.find_first_of(' '));
		line.erase(0, line.find_first_of(' '));
		Text::trimht(line);
		cmd[2] = line.substr(0, line.find_first_of(' '));

		switch (cmd[0].c_str()[0])
		{
		case 'W':
		case 'w':
			if (!(cmd[1].empty()))
				i.filename = cmd[1];
			if (!(i.filename.empty()))
				File::save(i);
			else{
				cout << "\nNome do arquivo: ";
				string f;
				getline(cin, f);
				Text::trimht(f);
				if(!(f.empty())){
					i.filename = f;
					File::save(i);
				}
			}
			//Screen::update(i);
			break;
		case 'Q':
		case 'q':
			if (i.saved)
				i.exit = true;
			else{
				cout << "Deseja sair sem salvar?(S/n) ";
				char op = _getch();
				if (op == 'S' || op == 's')
					i.exit = true;
			}
			//Screen::update(i);
			break;
		case 'E':
		case 'e':
			if (!(cmd[1].empty())){
				i.filename = cmd[1];
				File::load_to_buffer(i);
			}
			//Screen::update(i);
			break;
		case 'M':
		case 'm':
			i.buffer.mode = EDIT;
			if (cmd[1].empty()){
				i.buffer.reset_line();
				i.buffer.line_buffer.clear();
			}
			else
				i.buffer.change_line(atoi(cmd[1].c_str()));

			//Screen::update(i);
			break;
		case 'A':
		case 'a':
			i.buffer.line_buffer.clear();
			i.buffer.mode = INSERT;
			if (!(cmd[1].empty()))
				i.buffer.change_line(atoi(cmd[1].c_str()));
			else
				i.buffer.change_line(i.buffer.getLineNumber());

			//Screen::update(i);
			break;
		case 'L':
		case 'l':
			if (cmd[1].empty())
				Screen::update(i);
			else if (cmd[2].empty())
				Screen::updateRange(i, 1, atoi(cmd[1].c_str()));
			else
				Screen::updateRange(i, atoi(cmd[1].c_str()), atoi(cmd[2].c_str()));
			break;
		case 'D':
		case 'd':
			if (cmd[1].empty())
				i.buffer.removeLine();
			else if (cmd[2].empty())
				i.buffer.removeLine(atoi(cmd[1].c_str()));
			else
				i.buffer.removeLines(atoi(cmd[1].c_str()), atoi(cmd[2].c_str()) + 1);
			//Screen::update(i);
			break;
		case 'I':
		case 'i':
			i.buffer.line_buffer.clear();
			i.buffer.mode = INSERT_AFTER;
			if (!(cmd[1].empty()))
				i.buffer.change_line(atoi(cmd[1].c_str()));
			else
				i.buffer.change_line(i.buffer.getLineNumber());

			//Screen::update(i);
			break;
		case 'H':
		case 'h':
			Screen::help();
			break;
		default:
			break;
		}
	}
}
