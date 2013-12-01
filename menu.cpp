#include <iostream>
#include <conio.h>
#include "menu.h"
#include "file.h"
#include "text.h"

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
			break;
		case 'E':
		case 'e':
			if (!(cmd[1].empty())){
				i.filename = cmd[1];
				File::load_to_buffer(i);
			}
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
			break;
		case 'A':
		case 'a':
			i.buffer.line_buffer.clear();
			i.buffer.mode = INSERT;
			if (!(cmd[1].empty()))
				i.buffer.change_line(atoi(cmd[1].c_str()));
			else
				i.buffer.change_line(i.buffer.getLineNumber());
			break;
		case 't':
			cout << *i.buffer.line;
			getchar();
			break;
		default:
			break;
		}
	}
}