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
void Enemy::inIt(Bitmap bmpImage, DigitalCanvas2D* my_canvas)
{
	_canvas = my_canvas;
	
	_center.x = rectPos.left;
	_center.y = rectPos.bottom;
	
	arr = bmpImage.pixels;
	width = bmpImage.ih.biWidth;
	height = bmpImage.ih.biHeight;

}

void Enemy::reRectPoint(float x, int pattern)
{
	rectPos.top = 70.0f + 4.2f;
	rectPos.left = x - 2.5f;
	rectPos.right = x + 2.5f;
	rectPos.bottom = 70.0f;

//	m_Pattern = pattern;

	x = 0, y = 0;
	m_fAnimation = 0;
	m_fShotTime = 4.0f;
}

BOOL Enemy::Draw()
{
	//영역밖을 벗어난 오브젝트는 랜더링하지 않는다.
	if (rectPos.bottom > 75.0f || rectPos.right < -5.0f || rectPos.left > 65.0f || rectPos.top < -5.0f)
		return FALSE;

	
	return TRUE;
}

BOOL Enemy::Update(float delta)
{
	//애니메이션

	if (rectPos.bottom > 75.0f || rectPos.right < -5.0f || rectPos.left > 65.0f || rectPos.top < -5.0f)
		return FALSE;


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

	}

	return TRUE;
}

void Enemy::Destroy()
{

}