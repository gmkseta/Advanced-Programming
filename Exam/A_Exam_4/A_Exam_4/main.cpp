#include <iostream>

using namespace std;


template <typename T>
T addition(T a, T b)
{
	return a + b;
}

template <typename T>
T substraction(T a, T b)
{
	return a - b;
}


int doSomething(int a, int b, int(*call)(int, int))
{
	return (*call)(1, 2);
}

int main()
{
	//int(*func_ptr)(int, int) = nullptr;

	//func_ptr = addition;

	cout << (doSomething(1, 2, addition)) << endl;;

	cout << (doSomething(1, 2, substraction));

	return 0;
}

