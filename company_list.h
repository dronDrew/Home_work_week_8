#pragma once
#include "dependies.h"
class company_list
{
	struct company
	{
		std::string Company_name;
		std::string Owner_name;
		std::string Telephone;
		std::string Adress;
		std::string Type_of_work;
		void Print_info();//done
		company* next;
		company(std::string Company_name, std::string Owner_name, std::string Telephone, std::string Adress, std::string Type_of_work);//done
	};
	
	company* point;
public:
	company_list();//done
	void Add(std::string Company_name, std::string Owner_name, std::string Telephone, std::string Adress, std::string Type_of_work);
	bool Load_from_file();//done
	bool Save_to_file();//done
	void Search_by_company_name(std::string name_of_company);//done
	void Search_by_Owner(std::string Owner_info);
	void Search_by_Telephone(std::string tel);
	void Search_by_Adress(std::string adress);
	void Search_by_type_of_work(std::string type_of_company);	
	void Print_all_company_info();
	~company_list();//done
};

