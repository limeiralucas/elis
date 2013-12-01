#include "elis.h"

int main(int argc, char** argv){
	Instance i;
	i.filename = "teste.txt";

	//carregamento de arquivo
	File::load_to_buffer(i);
	Screen::update(i); //imprime o arquivo

	//loop principal
	while (!(i.exit))
		Keyboard::detect(i);

	return 0;
}