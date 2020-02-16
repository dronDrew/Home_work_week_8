#pragma once
#include "dependies.h"
class dictionary_of__fric
{
	std::map <std::string, int> map;
	public:
		dictionary_of__fric();//done
		void Load_from_file();//done
		void Save_statistic_to_file();
		void Print_all_statistic();//done
		void Top_print();//done
};

