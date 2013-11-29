#include "instance.h"

Instance::Instance(){
	this->exit = false;
	this->saved = true;
	this->line = 1;
	this->x = 0;
}

Instance::Instance(string _filename){
	this->filename = _filename;
	this->exit = false;
	this->saved = true;
	this->line = 1;
	this->x = 0;
}

void Instance::update(){
	this->line = this->buffer.size() + 1;
	this->x = this->line_buffer.size();
	this->saved = false;
}

void Instance::changeLine(int n){
	if ((n > 0) && (n <= this->buffer.size())){
		this->line = n;
		buffer_it = this->buffer.begin();
		advance(buffer_it, n - 1);
		this->line_buffer = *buffer_it;
	}
}