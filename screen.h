class Screen{
public:
	#ifdef _WIN32
	static void clear(){ system("cls"); }
	#else
	static void clear(){ /*clear da courses.h*/ }
	#endif

	static void update(Instance &i){
		int cnt = 1;
		clear();
		cout << "-------------------- " << i.filename << "--------------------\n";
		for (list<string>::iterator it = i.buffer.begin(); it != i.buffer.end(); it++){
			cout << cnt << " " << *it << "\n";
			cnt++;
		}
		cout << i.line << "> ";
	}

	static void menu(Instance &i){
		string cmd[2];
		cout << "\n: ";
		getline(cin, cmd[0]);
		if (cmd[0].find(' ') != string::npos){
			cmd[1] = cmd[0].substr(cmd[0].find(' ') + 1);
			cmd[0] = cmd[0].substr(0, cmd[0].find(' '));
		}

		switch (cmd[0].c_str()[0])
		{
		case 'W':
		case 'w':
			if (!(cmd[1].empty()))
				i.filename = cmd[1];
			File::save(i);
			break;
		case 'E':
		case 'e':
			if (!(cmd[1].empty())){
				i.filename = cmd[1];
				File::load_to_buffer(i);
			}
			break;
		case 'Q':
		case 'q':
			i.exit = true;
			break;
		}
		update(i);
	}
};