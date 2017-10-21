#include<iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Animal.h"

using namespace std;

int main(void)
{
	
	vector<Animal*> animal_arr;
	ifstream inf("animal.txt");
	string inStr;

	while (!inf.eof())
	{
		inf >> inStr;
		animal_arr.push_back(Animal::divide(inStr));

	}
	inf.close();
	


	for (auto itr : animal_arr)
		itr->speak();

	return 0;

}