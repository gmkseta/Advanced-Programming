#include "stdafx.h"
#include "Weapon.h"




Weapon::Weapon(){}
Weapon::~Weapon(){}
void Weapon::Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas) 
{
	_canvas = my_canvas;
	
	float x = 0.0f;
	float y = -1.5f;
	
	arr = bmpImage.pixels;
	width = bmpImage.ih.biWidth;
	height = bmpImage.ih.biHeight;

	calcRect(-(float)width / (SCREEN_RATE*2), -1.5f,1);
}

void Weapon::reRectPoint(float x, float y)
{
	rectPos.top = y + (float)height / SCREEN_RATE;
	rectPos.left = x - (float)width / (SCREEN_RATE*2);
	rectPos.right = x + (float)width / (SCREEN_RATE*2);
	rectPos.bottom = y;
}

BOOL Weapon::Draw()
{
	//화면 밖에 있을 경우 그림을 그리지 않는다.
	if (checkArea()==FALSE)
		return FALSE;

	drawObject(*_canvas);
	
	return TRUE;

}
BOOL Weapon::Update(float delta)
{
	//화면 안에 미사일이 있을 경우 TRUE를 반환
	if (rectPos.bottom > -1.0f)
	{
		rectPos.top += 2.0f * delta;
		rectPos.bottom += 2.0f * delta;
		return TRUE;
	}

	//화면밖일 경우 FALSE 반환
	return FALSE;
}