#include "Animal.h"
#include "Dog.h"
#include "Cow.h"
#include "Duck.h"
Animal *Animal::devide(std::string name)
{
	if (name == "Dog")
		return new Dog;
	else if (name == "Duck")
		return new Duck;
	else if (name == "Cow")
		return new Cow;
	else
		return nullptr;

}