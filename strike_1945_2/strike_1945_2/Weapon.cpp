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
	//ȭ�� �ۿ� ���� ��� �׸��� �׸��� �ʴ´�.
	if (checkArea()==FALSE)
		return FALSE;

	drawObject(*_canvas);
	
	return TRUE;

}
BOOL Weapon::Update(float delta)
{
	//ȭ�� �ȿ� �̻����� ���� ��� TRUE�� ��ȯ
	if (rectPos.bottom > -1.0f)
	{
		rectPos.top += 2.0f * delta;
		rectPos.bottom += 2.0f * delta;
		return TRUE;
	}

	//ȭ����� ��� FALSE ��ȯ
	return FALSE;
}