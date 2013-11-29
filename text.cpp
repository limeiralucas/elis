#include "text.h"

void Text::trim(std::string &s){
	std::string::size_type pos = s.find(' ');
	if (s.find_first_not_of(' ') != std::string::npos){
		while (pos != std::string::npos)
		{
			s.erase(pos, 1);
			pos = s.find_first_of(' ');
		}
	}
	else s.erase(s.begin(), s.end());
}

void Text::trimht(std::string &s){

	std::string::size_type pos = s.find_last_not_of(' ');
	if (pos != std::string::npos){
		s.erase(pos + 1);
		pos = s.find_first_not_of(' ');
		if (pos != std::string::npos)
			s.erase(0, pos);
	}
	else s.erase(s.begin(), s.end());
}