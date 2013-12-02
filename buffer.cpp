#include <iostream>
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
			itens.insert(++aux, line_buffer);
			line++;
		}
		line_buffer.clear();
	}
	else if(mode == EDIT)
	{
		*line = line_buffer;
	}
	else{
		list<string>::iterator aux = line;
		if(line != itens.begin())
		{
			itens.insert(aux, line_buffer);
		}
		line_buffer.clear();
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

void Buffer::removeLines(int start, int end){
	if ((start < end) && (start > 0) && (end <= itens.size())){
		list<string>::iterator s = itens.begin();
		list<string>::iterator e = itens.begin();

		advance(s, start - 1);
		advance(e, end - 1);

		itens.erase(s, e);
		reset_line();
	}
}

void Buffer::removeLine(int l){
	if ((l > 0) && (l <= itens.size())){
		list<string>::iterator it = itens.begin();
		advance(it, l - 1);
		itens.erase(it);
		reset_line();
	}
}

void Buffer::removeLine(){
	if (!(itens.empty())){
		itens.erase(line);
		reset_line();
	}
}
