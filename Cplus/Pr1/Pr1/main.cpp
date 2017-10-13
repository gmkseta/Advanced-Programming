#include <iostream>

using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2);
int main(void)
{
	/*int val1, val2;
	cin >> val1 >> val2;

	cout << val1 + "+" + val2<<endl;
*/
/*
	const int num = 12;

	const int *hi = &num;

	const int *(&hiref) = hi;

	cout << num << " " << *hi << " " << *hiref << endl;*/




}

Point& PntAdder(const Point &p1, const Point &p2);