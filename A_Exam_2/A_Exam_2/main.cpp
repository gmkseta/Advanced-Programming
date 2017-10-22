#include <iostream>

using namespace std;



class PlayOverWatch
{
public:
	void print()
	{
		cout << "pv" << endl;
	}
};
class PlayCiv
{
public:
	void print()
	{
		cout << "c" << endl;
	}
};

template <class T>
class Student
{
public:
	void (Student::*func_ptr)() = nullptr;
	T f_game;
public:
	Student(string doing)
	{
		if (doing == "study")
			this->func_ptr = &Student::study;
		else if (doing == "play")
			this->func_ptr = &Student::play;
		else if (doing == "sleep")
			this->func_ptr = &Student::sleep;
	}
	void study()
	{
		cout << "studing" << endl;
	}
	void play()
	{
		cout << "ping" << endl;
		f_game.print();
	}
	void sleep()
	{
		cout << "sleepg" << endl;
	}
	
	void doSomething()
	{
		if (func_ptr != nullptr)
			(this->*func_ptr)();
	}
};






int main(void)
{
	Student<PlayCiv> a("play");
	a.doSomething();
	return 0;

}






/*#include <iostream>



using namespace std;

class PlayOverWatch
{
public:
	void printName()
	{
		cout << "Over" << endl;
	}
};
class PlayCivlization
{
public:
	void printName()
	{
		cout << "ci" << endl;
	}
};

template <class T>


class Student
{

public:
	void(Student::*func_ptr)()=nullptr;
	T f_game;

public:

	Student(string doing)
	{
		if (doing == "study")
			this->func_ptr = &Student::study;
		else if (doing == "play")
			this->func_ptr = &Student::play;
		else if (doing == "sleep")
			this->func_ptr = &Student::sleep;
		else
			this->func_ptr = nullptr;
	}

	void study()
	{
		cout << "st" << endl;
	}
	void play()
	{
		cout << "pl" << endl;
		f_game.printName();
	}
	void sleep()
	{
		cout << "sl" << endl;
	}

	void doSomething()
	{
		if(func_ptr!=nullptr)
			(this->*func_ptr)();
	}
};


int main(void)
{

	Student<PlayOverWatch> a("play");
	a.doSomething();
	

	return 0;
}*/