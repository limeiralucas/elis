#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <list>
#include <fstream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int getConsoleLine(){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.Y + 1;
}

void flip_screen(list<string> &buffer){
	system("cls");
	for(list<string>::iterator i = buffer.begin(); i != buffer.end(); i++)
		cout << getConsoleLine() << " " << *i << "\n";
	cout << "--------------------------------\n";
}

void file_load(ifstream &file, list<string> &buffer){
	string line;
	while(getline(file, line))
		buffer.push_back(line);
}

void save(list<string> &buffer, ofstream &destination){
	for(list<string>::iterator i = buffer.begin(); i != buffer.end(); i++)
		destination << *i << "\n";
}

void menu(bool &detect, bool &exit, list<string> &buffer, ofstream &destination, bool &overwrite){
	char key;
	cout << "\nW - Write\tQ - Quit";
	cout << "\n:";
	key = getch();
	switch(key){
		case 'w':
		case 'W':
			save(buffer, destination);
		break;
		case 'q':
		case 'Q':
			detect = false;
			exit = true;
			overwrite = true;
		break;
		default:
		break;
	}
}

int main(int argc, char** argv) {
	char key;
	bool exit = false;
	bool detect = false;
	bool overwrite = false;
	int line_edit;
	string line_buffer = "";
	list<string> buffer;
	
	ifstream file;
	ofstream tmp;
	file.open("new.txt");
	file_load(file, buffer);
	tmp.open("~new", ios::out | ios::trunc);
	
	while(!exit){
		flip_screen(buffer);
		line_edit = getConsoleLine() - 1;
		while(detect){
			key = getch();
			switch(key){
				case 0x1B:
					menu(detect, exit, buffer, tmp, overwrite);
				break;
				case 0x0D:
					buffer.push_back(line_buffer);
					detect = false;
				break;
				case 0x08:
					if(!line_buffer.empty())
						line_buffer.erase(line_buffer.end()-1);
				break;
				default:
					line_buffer += key;
					cout << key;
				break;
			}
			flip_screen(buffer);
			cout << line_edit << "> " <<line_buffer;
		}
		detect = true;
		line_buffer = "";
		flip_screen(buffer);
	}
	
	file.close();
	tmp.close();
	if(overwrite){
		remove("new.txt");
		rename("~new", "new.txt");
	}
	return 0;
}
