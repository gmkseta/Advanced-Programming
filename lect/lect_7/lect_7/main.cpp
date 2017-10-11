#include <iostream>

using namespace std;

int addition(int a, int b)
{
	return a + b;
}


int substraction(int a, int b)
{
	return a - b;
}

int doSomething(int a, int b , int (*functocall)(int,int))
{
	return (*functocall)(1, 2);
}
int main()
{
	int(*func_ptr)(int, int) = nullptr;//함수 포인터.

	func_ptr = addition;
	cout << addition(1, 2)<<endl;
	cout<<(*func_ptr)(1, 2)<<endl;
	func_ptr = substraction;
	cout << substraction(1, 2) << endl;
	cout << (*func_ptr)(1, 2) << endl;

	cout << doSomething(1, 2, addition) << endl;

	int (*func_ptr_arr[])(int, int) = {addition,substraction};
	
	for (int i = 0; i < 2; i++)
		cout << (*func_ptr_arr[i])(4, 5) << endl;

	return 0;
}