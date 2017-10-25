#include <iostream>
#include <fstream>
#include "Animal.h"
#include <vector>

using namespace std;

int main()
{
	vector<Animal*>ani_list;
	
	ifstream inf("animal.txt");
	string inStr;

	while (!inf.eof())
	{
		inf >> inStr;
		if (Animal::devide(inStr) != nullptr)
			ani_list.push_back(Animal::devide(inStr));
	}

	for (auto itr : ani_list)
		itr->sound();
	for (auto itr : ani_list)
		delete[] itr;



	return 0;
}



























/*#include <iostream>
#include <vector>
#include "Animal.h"
#include <fstream>

using namespace std;


int main(void)
{
	vector<Animal*> ani_list;

	ifstream inf("animal.txt");

	string inStr;

	while (!inf.eof())
	{
		inf >> inStr;
		if(Animal::devide(inStr)!=nullptr)
			ani_list.push_back(Animal::devide(inStr));
	}
	inf.close();

	for (auto itr : ani_list)
		itr->sound();
	for (auto itr : ani_list)
		delete[] itr;

	return 0;

	
}*/