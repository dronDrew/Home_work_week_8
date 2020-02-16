#include "company_list.h"
company_list::company::company(std::string Company_name, std::string Owner_name, std::string Telephone, std::string Adress, std::string Type_of_work) {
	this->Company_name = Company_name;
	this->Owner_name = Owner_name;
	this->Telephone = Telephone;
	this->Adress = Adress;
	this->Type_of_work = Type_of_work;
	this->next = nullptr;
}
company_list::company_list(){
	this->point = nullptr;
}
company_list::~company_list() {
	while (this->point!=nullptr)
	{
		if (this->point->next == nullptr) {
			company* temp = this->point;
			delete temp;
			temp = nullptr;
			this->point = temp;
		}
		else
		{
			company* temp = this->point;
			while (temp->next->next != nullptr)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
		}
	}
}
bool company_list::Load_from_file() {
	std::ifstream file;
	std::string path_to_file;
	std::cout << "Enter path to file\n";
	std::cin >> path_to_file;
	file.open(path_to_file);
	if (!file.is_open())
	{
		std::cout << "Wrong path to file or file not exist\n";
		return false;
	}
	else {
		std::string Comp_name, Owner, Tel, adress, type;
		while (true)
		{
			std::getline(file, Comp_name);
			if (file.eof())
			{
				break;
			}
			std::getline(file, Owner);
			std::getline(file, Tel);
			std::getline(file, adress);
			std::getline(file, type);
			this->Add(Comp_name, Owner, Tel, adress, type);
		}
	}
	file.close();
	return true;
}
bool company_list::Save_to_file() {
	std::ofstream file;
	std::string path_to_file;
	std::cout << "Enter path to file\n";
	std::cin >> path_to_file;
	file.open(path_to_file);
	if (!file.is_open())
	{
		std::cout << "Wrong path to file or file not exist\n";
		return false;
	}
	else {
		company* temp=this->point;
		while (temp!=nullptr)
		{
			file << temp->Company_name << "\n";
			file << temp->Owner_name << "\n";
			file << temp->Telephone << "\n";
			file << temp->Adress << "\n";
			file << temp->Type_of_work << "\n";
			temp = temp->next;
		}
	}
	file.close();
	return true;
}
void company_list::company::Print_info() {
	std::cout << "Company name : " << this->Company_name << "\n";
	std::cout << "Owner name : " << this->Owner_name << "\n";
	std::cout << "Telephone number : " << this->Telephone << "\n";
	std::cout << "Adress : " << this->Adress << "\n";
	std::cout << "Type of work : " << this->Type_of_work << "\n";
}
void company_list::Search_by_company_name(std::string name_of_company) {
	if (this->point==nullptr)
	{
		std::cout << "Your list is empty\n";
		return;
	}
	else
	{
		int times{ 0 };
		company* temp = this->point;
		while (temp!=nullptr)
		{
			if (temp->Company_name == name_of_company) {
				temp->Print_info();
				times++;
			}
			temp = temp->next;
		}
		if (times==0)
		{
			std::cout << "No such company in list\n";
		}
	}
}
void company_list::Search_by_Owner(std::string Owner_info) {
	if (this->point == nullptr)
	{
		std::cout << "Your list is empty\n";
		return;
	}
	else
	{
		int times{ 0 };
		company* temp = this->point;
		while (temp != nullptr)
		{
			if (temp->Owner_name == Owner_info) {
				temp->Print_info();
				times++;
			}
			temp = temp->next;
		}
		if (times == 0)
		{
			std::cout << "No such company in list\n";
		}
	}
}
void company_list::Search_by_Telephone(std::string tel) {
	if (this->point == nullptr)
	{
		std::cout << "Your list is empty\n";
		return;
	}
	else
	{
		int times{ 0 };
		company* temp = this->point;
		while (temp != nullptr)
		{
			if (temp->Telephone == tel) {
				temp->Print_info();
				times++;
			}
			temp = temp->next;
		}
		if (times == 0)
		{
			std::cout << "No such company in list\n";
		}
	}
}
void company_list::Search_by_Adress(std::string adress) {
	if (this->point == nullptr)
	{
		std::cout << "Your list is empty\n";
		return;
	}
	else
	{
		int times{ 0 };
		company* temp = this->point;
		while (temp != nullptr)
		{
			if (temp->Adress == adress) {
				temp->Print_info();
				times++;
			}
			temp = temp->next;
		}
		if (times == 0)
		{
			std::cout << "No such company in list\n";
		}
	}
}
void company_list::Search_by_type_of_work(std::string type_of_company) {
	if (this->point == nullptr)
	{
		std::cout << "Your list is empty\n";
		return;
	}
	else
	{
		int times{ 0 };
		company* temp = this->point;
		while (temp != nullptr)
		{
			if (temp->Type_of_work == type_of_company) {
				temp->Print_info();
				times++;
			}
			temp = temp->next;
		}
		if (times == 0)
		{
			std::cout << "No such company in list\n";
		}
	}
}
void company_list::Print_all_company_info() {
	if (this->point==nullptr)
	{
		std::cout << "Your list is empty\n";
		return;
	}
	else {
		company* temp = this->point;
		while (temp!=nullptr)
		{
			temp->Print_info();
			temp = temp->next;
		}
	}
}
void company_list::Add(std::string Company_name, std::string Owner_name, std::string Telephone, std::string Adress, std::string Type_of_work) {
	try
	{
	if (this->point==nullptr)
	{
		this->point = new company(Company_name, Owner_name, Telephone, Adress, Type_of_work);
	}
	else {
		company* temp = this->point;
		while (temp->next!=nullptr)
		{
			temp = temp->next;
		}
		temp->next =new company(Company_name, Owner_name, Telephone, Adress, Type_of_work);
	}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}