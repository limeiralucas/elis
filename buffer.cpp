#include "buffer.h"

Buffer::Buffer(){
	line_buffer = "";
	mode = INSERT;
}

void Buffer::insert(){
	if (mode == INSERT){
		if (line == --itens.end()){
			itens.push_back(line_buffer);
			reset_line();
		}
		else
		{
			list<string>::iterator aux = line;
			aux++;
			itens.insert(aux++, line_buffer);
		}
		line_buffer.clear();
	}
	else
	{
		*line = line_buffer;
	}
}

void Buffer::change_line(int l){
	if ((l <= itens.size()) && (l > 0)){
		line = itens.begin();
		advance(line, l - 1);
		if (mode == EDIT)
			line_buffer = *line;
	}
	else
	{
		reset_line();
	}
}

void Buffer::reset_line(){
		line = --itens.end();
}

int Buffer::getLineNumber(){
	return distance(itens.begin(), line);
}