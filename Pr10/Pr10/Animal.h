#pragma once
#include<string>
class Animal
{
public:
	virtual void sound() = 0;

	static Animal *devide(std::string name);

};