#include "Animal.h"
#include "Dog.h"
#include "Duck.h"
#include "Cow.h"
#include <string>
#include <iostream>



Animal *Animal::devide(std::string doing)
{
	if (doing == "Cow")
		return new Cow;
	else if (doing == "Dog")
		return new Dog;
	else if (doing == "Duck")
		return new Duck;
	else
		return nullptr;


}



























//
//
//
//
//Animal *Animal::devide(std::string name)
//{
//	if (name == "Cow")
//		return new Cow;
//	else if (name == "Dog")
//		return new Dog;
//	else if (name == "Duck")
//		return new Duck;
//	else
//		return nullptr;
//}
