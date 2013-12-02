#include "elis.h"

int main(int argc, char** argv){
	Instance i;
	if(argv[1])
		i.filename = argv[1];

	//carregamento de arquivo
	if(!(File::load_to_buffer(i)))
		i.buffer.line = i.buffer.itens.end();
	Screen::update(i); //imprime o arquivo

	//loop principal
	while (!(i.exit))
		Keyboard::detect(i);

	return 0;
}
