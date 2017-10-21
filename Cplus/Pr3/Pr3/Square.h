#pragma once

#include <iostream>
#include "Rectangle.h"

class Square :public Rectangle
{
public :
	Square(int side)
		:Rectangle(side, side)
	{}
};
