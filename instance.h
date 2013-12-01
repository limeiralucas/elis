#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include <string>
#include "buffer.h"

class Instance{
public:
	string filename;
	Buffer buffer;
	int cursor;
	bool saved;
	bool exit;
	
	Instance();
};

#endif