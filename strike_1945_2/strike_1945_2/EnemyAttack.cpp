#include "stdafx.h"
#include "EnemyAttack.h"

EnemyAttack::EnemyAttack()
{}

EnemyAttack::~EnemyAttack()
{}
void EnemyAttack::Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas) {

	_canvas = my_canvas;

	calcRect(-(float)width / (SCREEN_RATE*2), -1.5f, 1);
	
	arr = bmpImage.pixels;
	width = bmpImage.ih.biWidth;
	height = bmpImage.ih.biHeight;

}

void EnemyAttack::reRectPoint(float x, float y)
{
	rectPos.top = y + (float)height / SCREEN_RATE;
	rectPos.left = x - (float)width / (SCREEN_RATE*2);
	rectPos.right = x + (float)width / (SCREEN_RATE*2);
	rectPos.bottom = y;
}

BOOL EnemyAttack::Draw()
{
	//화면 밖에 있을 경우 그림을 그리지 않는다.
	if (rectPos.bottom < -1.0f)
		return FALSE;
	drawObject(*_canvas);
	return TRUE;
}
BOOL EnemyAttack::Update(float delta)
{
	//화면 안에 미사일이 있을 경우 TRUE를 반환
	if (rectPos.bottom > -1.0f||rectPos.bottom<1.0f)
	{
		rectPos.top -= 1.0f * delta;
		rectPos.bottom -= 1.0f * delta;
		return TRUE;
	}

	//화면밖일 경우 FALSE 반환
	return FALSE;
}
