#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;


class Person
{
public:
	int age;
	char* name;

	Person(int myage, char *myname) :age(myage)
	{
		strcpy(name, myname);
	}
};
class hi:public Person
{
public:
	hi(int myage, char *myname) :Person(myage, myname)
	{

	}
};


int main(void)
{
	
	Rectangle rec(1, 2, 3, 4);
	

	return 0;

}