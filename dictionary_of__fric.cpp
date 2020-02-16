#include "dictionary_of__fric.h"
dictionary_of__fric::dictionary_of__fric() {}
void dictionary_of__fric::Load_from_file() {
	std::cout << "Enter path to file\n";
	std::string temp;
	std::cin >> temp;
	std::ifstream file;
	file.open(temp);
	if (!file.is_open())
	{
		std::cout << "Can`t fing file,ot it not exist\n";
		return;
	}
	else {
		std::string word;
		while (true)
		{
			file >> word;
			if (file.eof())
			{
				break;
			}
			auto iter =this->map[word] = 0;
		}
		file.close();
		file.open(temp);
		while (true)
		{
			file >> word;
			if (file.eof())
			{
				break;
			}
			auto iter =this->map.find(word);
			iter->second++;
			this->map[iter->first] = iter->second;
		}
		file.close();
	}
}
void dictionary_of__fric::Save_statistic_to_file() {
	std::ofstream file;
	std::string temp;
	std::cout << "Enter path to file were you wont save statictic\n";
	std::cin >> temp;
	file.open(temp);
	if (!file.is_open()) {
		std::cout << "can`t file to save statistic or it not exist\n";
		return;
	}
	else
	{
		auto iter = this->map.begin();
		for(;iter!=this->map.end(); iter++)
		{
			file << iter->first << " " << iter->second << "\n";
		}
	}
	file.close();
}
void dictionary_of__fric::Print_all_statistic() {
	auto iter = this->map.cbegin();
	for(;iter!=this->map.cend(); iter++)
	{
		std::cout <<"Word : "<< iter->first <<" find : "<< iter->second<<" times\n";
	}

}
void dictionary_of__fric::Top_print() {
	auto iter = this->map.begin();
	int max_value{iter->second};
	std::string Key_of_max;
	for  (;  iter!=this->map.end(); iter++)
	{
		if (iter->second > max_value) {
			max_value = iter->second;
			Key_of_max = iter->first;
		}
	}
	std::cout << "Word : " << Key_of_max << " most porular we find it : " << max_value << " times\n";
}