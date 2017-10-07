#include "stdafx.h"
#include "EnemyAttack.h"




EnemyAttack::EnemyAttack()
{}

EnemyAttack::~EnemyAttack(void)
{
	Destroy();
}
void EnemyAttack::Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas) {
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

void EnemyAttack::reRectPoint(float x, float y)
{

	rectPos.top = y + (float)height / 512;
	rectPos.left = x - (float)width / 1024;
	rectPos.right = x + (float)width / 1024;
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
	if (rectPos.bottom > -1.0f)
	{
		rectPos.top += 2.0f * delta;
		rectPos.bottom += 2.0f * delta;
		return TRUE;
	}

	//화면밖일 경우 FALSE 반환
	return FALSE;
}
void EnemyAttack::Destroy()
{

}