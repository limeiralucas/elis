#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <list>
#include <fstream>

using namespace std;

string filename = "new.txt";

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

void file_load(string filename, list<string> &buffer){
	ifstream file;
	string line;
	
	buffer.clear();
	file.open(filename.c_str(), ios::app);
	while(getline(file, line))
		buffer.push_back(line);
	file.close();
}

void save(list<string> &buffer){
	ofstream tmp;
	tmp.open(filename.c_str(), ios::out | ios::trunc);
	for(list<string>::iterator i = buffer.begin(); i != buffer.end(); i++)
		tmp << *i << "\n";
	tmp.close();
}

<<<<<<< HEAD
void menu(bool &detect, bool &exit, list<string> &buffer, bool saved, int &line_edit, list<string>::iterator &it_aux, string &line_buffer){
=======
void menu(bool &detect, bool &exit, list<string> &buffer){
>>>>>>> 25573e05d193eb3031450001e8e3636e3c6579b2
	string cmd[2];
	flip_screen(buffer);
	cout << ": ";
	getline(cin, cmd[0]);
	
	if(cmd[0].find(' ') != string::npos)
	{
		cmd[1] = cmd[0].substr(cmd[0].find(' ')+1);
		cmd[0] = cmd[0].substr(0, cmd[0].find(' '));
	}
	
	switch(cmd[0].c_str()[0]){
		case 'w':
		case 'W':
			if(!(cmd[1].empty()))
				filename = cmd[1];
			save(buffer);
			cout << "saved";
<<<<<<< HEAD
			saved = true;
=======
>>>>>>> 25573e05d193eb3031450001e8e3636e3c6579b2
			_sleep(1000);
		break;
		case 'q':
		case 'Q':
<<<<<<< HEAD
			if(saved == false){
				cout << "Deseja sair sem salvar?\nDigite 'S' para sim e 'N' para nao.\n>";
				char aux;
				aux = getch();
				switch(aux){
					case 's':
					case 'S':
						detect = false;
						exit = true;
						break;
					case 'n':
					case 'N':
						menu(detect, exit, buffer, saved, line_edit, it_aux, line_buffer);
						break;
					default:
					break;
				}
			}else{
				detect = false;
				exit = true;
			}
		break;
		case 'e':
		case 'E':
			if(!(cmd[1].empty())){
				filename = cmd[1];
				file_load(filename, buffer);
				detect = false;
			}else{
				cout << "Nome de arquivo inválido";
				_sleep(1000);
			}
		break;
		case 'd':
		case 'D':
			
		break;
		case 'm':
		case 'M':
			line_edit = atoi( cmd[1].c_str() );
			it_aux = buffer.begin();
			advance(it_aux, line_edit-1);
			line_buffer = *it_aux;
		break;
=======
			detect = false;
			exit = true;
		break;
		case 'e':
		case 'E':
			if(!(cmd[1].empty())){
				filename = cmd[1];
				file_load(filename, buffer);
				detect = false;
			}else{
				cout << "Nome de arquivo inválido";
				_sleep(1000);
			}
		break;
>>>>>>> 25573e05d193eb3031450001e8e3636e3c6579b2
		default:
		break;
	}
}

int main(int argc, char** argv) {
	if(argv[1])
		filename = argv[1];
	
	char key;
	bool exit = false;
	bool detect = false;
<<<<<<< HEAD
	bool saved = true;
=======
>>>>>>> 25573e05d193eb3031450001e8e3636e3c6579b2
	int line_edit;
	list<string> buffer;
	list<string>::iterator it_aux;
	string line_buffer = "";
	
	file_load(filename, buffer);
	
	while(!exit){
		flip_screen(buffer);
		line_edit = getConsoleLine() - 1;
		while(detect){
			key = getch();
			if(kbhit()){
				key = getch();
				switch(key){
					case 72:
						if(line_edit > 1){
							line_edit--;
							it_aux = buffer.begin();
							advance(it_aux, line_edit-1);
							line_buffer = *it_aux;
						}
					break;
					case 80:
						if(line_edit < getConsoleLine() - 1){
							line_edit++;
							if(line_edit != getConsoleLine() - 1){
								it_aux = buffer.begin();
								advance(it_aux, line_edit-1);
								line_buffer = *it_aux;
							}
							else line_buffer = "";
						}
					break;
					case 75:
						//LEFT;
					break;
					case 77:
						//RIGHT;
					break;
					default:
					break;
				}
			}else{
				switch(key){
					case 0x1B:
<<<<<<< HEAD
						menu(detect, exit, buffer, saved, line_edit, it_aux, line_buffer);
					break;
					case 0x0D:
						saved = false;
=======
						menu(detect, exit, buffer);
					break;
					case 0x0D:
>>>>>>> 25573e05d193eb3031450001e8e3636e3c6579b2
						if(line_edit == getConsoleLine() - 1)
							buffer.push_back(line_buffer);
						else
							(*it_aux) = line_buffer;
						detect = false;
					break;
					case 0x08:
<<<<<<< HEAD
						saved = false;
=======
>>>>>>> 25573e05d193eb3031450001e8e3636e3c6579b2
						if(!line_buffer.empty())
							line_buffer.erase(line_buffer.end()-1);
					break;
					default:
						line_buffer += key;
<<<<<<< HEAD
						saved = false;
=======
>>>>>>> 25573e05d193eb3031450001e8e3636e3c6579b2
					break;
				}
			}
			flip_screen(buffer);
			cout << line_edit << "> " << line_buffer;
		}
		detect = true;
		line_buffer = "";
		flip_screen(buffer);
	}
	
	return 0;
}
