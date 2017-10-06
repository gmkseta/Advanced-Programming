#include "stdafx.h"
#include "Weapon.h"


unsigned int Weapon::MissleTextureObject = 0;

Weapon::Weapon()
{
	//화면 밖에서 대기중.	
}

Weapon::~Weapon(void)
{
	Destroy();
}
void Weapon::Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas) {
	_canvas = my_canvas;
	
	float x = 0.0f;
	float y = -1.5f;
	
	rectPos.top = y + (float)height / 512;
	rectPos.left = x - (float)width / 1024;
	rectPos.right = x + (float)width / 1024;
	rectPos.bottom = y;
	_center.x = rectPos.left;
	_center.y = rectPos.bottom;
	arr = bmpImage.pixels;
	width = bmpImage.ih.biWidth;
	height = bmpImage.ih.biHeight;
}

void Weapon::reRectPoint(float x, float y)
{
	
	rectPos.top = y + (float)height / 512;
	rectPos.left = x - (float)width / 1024;
	rectPos.right = x + (float)width / 1024;
	rectPos.bottom = y;

	_center.x = rectPos.left;
	_center.y = rectPos.bottom;

}

BOOL Weapon::Draw()
{
	//화면 밖에 있을 경우 그림을 그리지 않는다.
	if (rectPos.bottom < -1.0f)
		return FALSE;

	drawObject(*_canvas);


	return TRUE;
}
BOOL Weapon::Update(float delta)
{
	//화면 안에 미사일이 있을 경우 TRUE를 반환
	if (rectPos.bottom > -1.0f)
	{
		rectPos.top += 3.0f * delta;
		rectPos.bottom += 3.0f * delta;
		_center.y = rectPos.bottom;
		return TRUE;
	}

	//화면밖일 경우 FALSE 반환
	return FALSE;
}
void Weapon::Destroy()
{

}