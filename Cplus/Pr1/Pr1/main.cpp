#include <iostream>

using namespace std;

//
//3
//typedef struct __Point
//{
//	int xpos;
//	int ypos;
//}Point;
//
//Point& PntAdder(const Point &p1, const Point &p2);

int main(void)
{
	/*1
	int val1, val2;
	cin >> val1 >> val2;

	cout << val1 + "+" + val2<<endl;
*/


/*2
	const int num = 12;

	const int *hi = &num;

	const int *(&hiref) = hi;

	cout << num << " " << *hi << " " << *hiref << endl;*/

/*3
	Point *p1 = new Point;
	Point *p2 = new Point;
	p1->xpos = 1;
	p1->ypos = 2;
	p2->xpos = 3;
	p2->ypos = 4;

	

	Point &pref = PntAdder(*p1, *p2);

	cout << pref.xpos << "," << pref.ypos << endl;

	delete p1;
	delete p2;
*/





}
//3
//Point& PntAdder(const Point &p1, const Point &p2)
//{
//	Point *pptr = new Point;
//	pptr->xpos = p1.xpos + p2.xpos;
//	pptr->ypos = p1.ypos + p2.ypos;
//
//	return *pptr;
//
//
//}