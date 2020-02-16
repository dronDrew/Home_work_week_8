#include"dependies.h"
#include"company_list.h"
#include "My_unique_ptr.h"
#include "My_sharead_ptr.h"
#include "dictionary_of__fric.h"
using namespace std;
int main() {
	/*company_list a;
	a.Load_from_file();
	a.Add("Ferrari", "Enzo Ferari", "+6355233", "Modena", "car factory");
	a.Add("Versaci", "unnone", "+66354233", "Treviso", "clouse factory");
	a.Save_to_file();
	a.Search_by_Adress("Modena");
	std::cout << "_________________________________________\n";
	a.Search_by_company_name("Ford");
	std::cout << "_________________________________________\n";
	a.Search_by_Owner("John Wolf");
	std::cout << "_________________________________________\n";
	a.Search_by_Telephone("+456533442737");
	std::cout << "_________________________________________\n";
	a.Search_by_type_of_work("clouse factory");
	std::cout << "_________________________________________\n";
	a.Search_by_type_of_work("space factory");
	std::cout << "_________________________________________\n";
	a.Print_all_company_info();*/
	/*My_unique_ptr<int> a(new int(245));
	cout << *a << endl;
	*a = 90;
	cout << *a << endl;
	int *pointer = new int(9999);
	a = pointer;
	cout << *a << endl;*/
	/*My_sharead_ptr<int> a(new int(999));
	My_sharead_ptr<int> k(new int(9));
	My_sharead_ptr<int> z(new int(99));
	int* b = new int(12);
	cout << *a << endl;
	a = b;
	cout << *a << endl;
	a = k=z;
	cout << *a << endl;*/
	dictionary_of__fric test;
	test.Load_from_file();
	test.Print_all_statistic();
	test.Top_print();
	test.Save_statistic_to_file();
	return 0;
}