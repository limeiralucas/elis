#include <string>
#include <list>

class Instance{
public:
	string filename;
	list<string> buffer;
	int line;
	bool exit = false;

	Instance(string _filename){
		this->filename = _filename;
		this->line = 1;
		this->exit = false;
	}

	Instance(){ 
		this->filename = "new.txt";
		this->line = 1;
		this->exit = false;
	}

	void update(){
		this->line = this->buffer.size() + 1;
	}
};