#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <string>
#include <list>

using namespace std;

enum Mode{ INSERT, EDIT };

class Buffer{
public:
	string line_buffer;
	list<string> itens;
	list<string>::iterator line;
	Mode mode;

	Buffer();
	void insert(string str);
	void insert();
	void change_line(int l);
	void reset_line();
	int getLineNumber();
	void removeLines(int start, int end);
	void removeLine(int l);
	void removeLine();
};

#endif