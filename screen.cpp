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

void Screen::updateRange(Instance &i, int start, int end){
	list<string>::iterator it = i.buffer.itens.begin();
	if ((start < end) && (start > 0) && (end <= i.buffer.itens.size())){
		advance(it, start - 1);
		int cnt = start;

		clear();
		if (i.filename.empty())
			cout << "----------------- unnamed -----------------\n";
		else
			cout << "----------------- " << i.filename << " -----------------\n";

		for (; cnt <= end; it++){
			cout << cnt << "> " << *it << "\n";
			cnt++;
		}
	}
	else
		update(i);
}