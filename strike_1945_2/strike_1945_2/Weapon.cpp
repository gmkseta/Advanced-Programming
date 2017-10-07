#include "stdafx.h"
#include "Weapon.h"


unsigned int Weapon::MissleTextureObject = 0;

Weapon::Weapon()
{
	//ȭ�� �ۿ��� �����.	
}

Weapon::~Weapon(void)
{
	Destroy();
}
void Weapon::Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas) {
	_canvas = my_canvas;
	
	float x = 0.0f;
	float y = -1.5f;
	
	rectPos.left = x - (float)width / 1024;
	rectPos.bottom = y;
	calcRightTop();
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


}

BOOL Weapon::Draw()
{
	//ȭ�� �ۿ� ���� ��� �׸��� �׸��� �ʴ´�.
	if (rectPos.bottom < -1.0f)
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
void Weapon::Destroy()
{

}