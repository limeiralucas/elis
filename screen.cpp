#include "screen.h"
#include "text.h"

void Screen::update(Instance &i){
	int cnt = 1;
	
	clear();
	if (i.filename.empty())
		cout << "----------------- unnamed -----------------\n";
	else
		cout << "----------------- " << i.filename << " -----------------\n";

	for (list<string>::iterator it = i.buffer.itens.begin(); it != i.buffer.itens.end(); it++){
		cout << cnt << "> " << *it << "\n";
		cnt++;
	}
}