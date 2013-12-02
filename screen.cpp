#include "screen.h"
#include "text.h"

void Screen::clear(){
	system("cls");
}

void Screen::help(){
	clear();
	cout << "<ENTER> - Passa para a proxima linha\n<ESC> Alterna para o modo de comando\nW [<name>]";
	cout << " - Salvar arquivo\nE [name] - Carregar arquivo\nI [n] - Insere texto antes da linha n\nA [n]";
	cout << " - Insere texto depois da linha n\nM [n] - Torna n a linha atual\nD [n[m]] - Remove linhas de n até m\nL [n[m]]";
	cout << " - Lista linhas de m até n\nH - ajuda\nQ - Sair ";
	_getch();
}

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
