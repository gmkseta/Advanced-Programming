#include <iostream>
#include <string>

class PlayOverWatch
{
public:
	void printName()
	{
		std::cout << "OverWatch" << std::endl;
	}
};
class PlayCivilization
{
public:
	void printName()
	{
		std::cout << "Civilization" << std::endl;
	}
};
template <class T>
class Student
{
public:

	void (Student::*func_ptr)() = nullptr;
	T f_game;
public:

	Student<T>(std::string doing)
	{
		if (doing == "study")
			this->func_ptr = &Student::study;
		else if (doing == "play")
			this->func_ptr = &Student::play;
		else if (doing == "sleep")
			this->func_ptr = &Student::sleep;
	}
	
	void doSomething()
	{
		if (func_ptr != nullptr)
			(this->*func_ptr)();
	}
	void study()
	{
		std::cout << "Studying" << std::endl;
	}
	void play()
	{
		std::cout << "playing" << std::endl;	
		//T::printName();
		f_game.printName();
	}
	void sleep()
	{
		std::cout << "Sleeping" << std::endl;
	}
};

int main(void)
{
	Student<PlayOverWatch> playing_student1("play");
	Student<PlayCivilization> playing_student2("play");
	playing_student1.doSomething();
	playing_student2.doSomething();
	return 0;
}