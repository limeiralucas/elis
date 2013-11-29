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
	int line;
	bool saved;
	bool exit;
	
	Instance(void);
	Instance(string _filename);

	void update();
};

#endif