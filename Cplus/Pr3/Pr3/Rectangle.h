#pragma once
#include <iostream>

class Rectangle
{
private:
	int width;
	int height;
public:
	Rectangle(int wid, int hei)
		:width(wid), height(hei)
	{}
	void ShowAreaInfo();
};