#include <iostream>



class Test
{
public:
	int a_;
	Test(const Test& _test)
		:a_(_test.a_) 
	{
		//constructor
		std::cout << "Copy constructor" << std::endl;
	}
	Test(const int& _a):a_(_a) 
	{ std::cout << "int constructor" << std::endl; }

	void print()
	{
		std::cout << a_ << std::endl;
	}
	void hi(int& hi)
	{
		hi++;
	}
	
};

void printTest(Test test)
{
	test.print();
}
void printTestRef(Test& test)
{
	test.print();
}

int main(void)
{
	Test my_test(123);
	int a = 0;

	printTest(my_test);
	printTestRef(my_test);

	my_test.hi(a);
	std::cout << a << std::endl;


}