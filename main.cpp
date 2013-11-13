#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstdlib>

using namespace std;

void save(list<string> &l, fstream &f){
	f.clear();

	for (list<string>::iterator it=l.begin(); it != l.end(); ++it){
			f << *it << "\n";
	}
}

int main(int argc, char** argv) {
	bool exit = false;

	fstream file;
	string line;
	string tmp;
	file.open("file.txt", ios_base::in | ios_base::out | ios_base::app);
	list<string> scr;
	while(getline(file, line)){
			scr.insert(scr.end(), line);
	}

	if(file.is_open())
	{
		while(!exit){
            int line_count = 1;
            file.clear();
			system("clear");
			for (std::list<string>::iterator it=scr.begin(); it != scr.end(); ++it){
				cout << line_count++ << " " << *it << endl;
			}
			getline(std::cin, tmp);
			if(tmp == "eof")
                break;
			scr.insert(scr.end(), tmp);
		}

		save(scr, file);
		file.close();
	}
	return 0;
}
