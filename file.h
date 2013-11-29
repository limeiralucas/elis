#ifndef _ELIS_FILE_H_
#define _ELIS_FILE_H_

#include <fstream>
#include "instance.h"

class File{
public:
	static bool load_to_buffer(Instance &i);

	static bool save(Instance &i);
};

#endif