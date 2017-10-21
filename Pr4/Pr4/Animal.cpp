#include "Animal.h"
#include "Cow.h"
#include "Dog.h"

Animal* Animal::divide(string name) {
	if (name == "Cow")
		return new Cow;
	else if (name == "Dog")
		return new Dog;

	return nullptr;
}
