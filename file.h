#include <fstream>

class File{
public:
	static bool load_to_buffer(Instance &i){
		ifstream file;
		string line;

		file.open(i.filename.c_str());
		if (file.is_open()){
			i.buffer.clear();
			while (getline(file, line))
				i.buffer.push_back(line);
			file.close();
			i.update();

			return true;
		} else return false;
	}

	static bool save(Instance &i){
		ofstream file;
		file.open(i.filename.c_str(), ios::trunc);
		if (file.is_open()){
			for (list<string>::iterator it = i.buffer.begin(); it != i.buffer.end(); it++)
				file << *it << "\n";
			file.close();

			return true;
		} else return false;
	}
};