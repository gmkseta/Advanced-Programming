#include <iostream>
#include "Rectangle.h"
using namespace std;




Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
	:upleft(x1,y1) ,lowRight(x2,y2)
{
	//empty
}

void Rectangle::ShowRetInfo() const
{
	cout << "문그린은 어디가나 " << endl;

}