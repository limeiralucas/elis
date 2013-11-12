#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
	bool exit = false;
	
	fstream file;
	string line;
	string tmp;
	file.open("file.txt");
	list<string> scr;
	while(getline(file, line)){
			scr.insert(scr.end(), line);
	}
	
	if(file.is_open())
	{
		while(!exit){
			system("clear");
			for (std::list<string>::iterator it=scr.begin(); it != scr.end(); ++it){
				cout << *it << endl;
			}
			getline(std::cin, tmp);
			scr.insert(scr.end(), tmp);
		}
	}
	return 0;
}
