#include "stdafx.h"
#include "Enemy.h"

unsigned int Enemy::EnemyTextureObject = 0;

Enemy::Enemy(void)
{
}

Enemy::~Enemy(void)
{
	Destroy();
}
void Enemy::Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas)
{
	_canvas = my_canvas;	
	arr = bmpImage.pixels;
	width = bmpImage.ih.biWidth;
	height = bmpImage.ih.biHeight;
	x = 0.0f;
	y = 0.5f-(float)height/512;
	rectPos.left = x;
	rectPos.bottom = y;
	calcRightTop();

}

void Enemy::reRectPoint(float x, int pattern)
{
	//rectPos.top = 70.0f + 4.2f;
	rectPos.left = x ;
	calcRightTop();

//	m_Pattern = pattern;

	x = 0, y = 0;
	m_fAnimation = 0;
	m_fShotTime = 4.0f;
}

BOOL Enemy::Draw()
{
	//영역밖을 벗어난 오브젝트는 랜더링하지 않는다.
	if (rectPos.bottom < -1.0f || rectPos.right > 1.0f || rectPos.left < -1.0f || rectPos.top > 1.0f)
		return FALSE;

	drawObject(*_canvas);
	
	return TRUE;
}

BOOL Enemy::Update(float delta)
{
	//애니메이션

	if (rectPos.bottom < -1.0f || rectPos.right > 1.0f || rectPos.left < -1.0f || rectPos.top > 1.0f)
		return FALSE;



	rectPos.top -= 20.0 * delta;
	rectPos.bottom -= 20.0 * delta;

/*
	switch (m_Pattern)
	{
	case 1:
	case 2:

		m_fAnimation += 8.0f * delta;
		if (m_fAnimation > 17.0f)
			m_fAnimation -= 17.0f;

		rectPos.top -= 20.0 * delta;
		rectPos.bottom -= 20.0 * delta;

		break;

	}*/

	return TRUE;
}

void Enemy::Destroy()
{

}