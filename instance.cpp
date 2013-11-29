#include "instance.h"

Instance::Instance(){
	this->exit = false;
	this->saved = true;
	this->line = 1;
}

Instance::Instance(string _filename){
	this->filename = _filename;
	this->exit = false;
	this->saved = true;
	this->line = 1;
}

void Instance::update(){
	this->line = this->buffer.size() + 1;
	this->saved = false;
}