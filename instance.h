#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include <string>
#include <list>

using namespace std;

class Instance{
public:
	string filename;
	string line_buffer;
	list<string> buffer;
	list<string>::iterator buffer_it;
	int line;
	int x;
	bool saved;
	bool exit;
	
	Instance(void);
	Instance(string _filename);

	void update();
	void changeLine(int n);
};

#endif