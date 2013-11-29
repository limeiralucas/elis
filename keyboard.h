#include <string>

class Keyboard{
public:
	string line_buffer;

	Keyboard(){ }

	void detect(Instance &i){

		char key = _getch();
		if (_kbhit()){
			key = _getch();
		}
		else
		{
			switch (key){
			case 0x1B:
				Screen::menu(i);
				cout << line_buffer;
				break;
			case 0x0D:
				i.buffer.push_back(line_buffer);
				line_buffer.clear();
				i.update();
				Screen::update(i);
				break;
			case 0x08:
				if (!(line_buffer.empty())){
					line_buffer.erase(line_buffer.end() - 1);
					cout << "\b \b";
				}
				else
				{
					line_buffer = i.buffer.back();
					i.buffer.pop_back();
					i.update();
					Screen::update(i);
					cout << line_buffer;
				}
				break;
			default:
				line_buffer += key;
				cout << key;
				break;
			}
		}
	}
};