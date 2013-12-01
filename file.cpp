#include "file.h"

bool File::load_to_buffer(Instance &i){
	ifstream file;
	string line;

	file.open(i.filename);
	if (file.is_open()){
		while (getline(file, line))
			i.buffer.itens.push_back(line);

		i.buffer.reset_line();
		i.saved = true;

		return true;
	}
	else
		return false;
}

bool File::save(Instance &i){
	ofstream file;
	file.open(i.filename.c_str(), ios::trunc);
	if (file.is_open()){
		for (list<string>::iterator it = i.buffer.itens.begin(); it != i.buffer.itens.end(); it++)
			file << *it << "\n";
		file.close();

		i.saved = true;

		return true;
	}
	else
		return false;
}