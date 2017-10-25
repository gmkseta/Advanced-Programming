#include "Animal.h"
#include <iostream>
#include <vector>
#include "Cow.h"
using namespace std;




int main(void)
{

	vector<Animal*> an_list;

	an_list.push_back(Animal::devide("Cow"));
	an_list.push_back(Animal::devide("Dog"));
	an_list.push_back(Animal::devide("Duck"));


	for (auto itr : an_list)
		itr->sound();


	



	return 0;
}