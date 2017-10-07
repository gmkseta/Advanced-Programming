#include "stdafx.h"
#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy(void)
{
}

Enemy::~Enemy(void)
{
	Destroy();
}
void Enemy::Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas)
{

	srand((unsigned int)time(NULL));

	_canvas = my_canvas;	
	arr = bmpImage.pixels;
	width = bmpImage.ih.biWidth;
	height = bmpImage.ih.biHeight;


	rectPos.left = (float)rand()/RAND_MAX;
	rectPos.bottom = 1.0f+0.1f;
	calcRightTop();

	


}

void Enemy::reRectPoint()
{
	calcRect(-1.0f+(float)2*rand()/RAND_MAX, 1.0f, 1);
	myPattern = rand() % PATTERN_MAX + 1;


	myMovTime = 0;
	m_fAnimation = 0;
	m_fShotTime = 4.0f;
}

BOOL Enemy::Draw()
{
	//영역밖을 벗어난 오브젝트는 랜더링하지 않는다.
	if (rectPos.bottom < -1.0f-(float)height/512 || rectPos.right > 1.0f || rectPos.left < -1.0f || rectPos.top > 1.0f+ (float)height/512)
		return FALSE;

	drawObject(*_canvas);
	
	return TRUE;
}

BOOL Enemy::Update(float delta)
{
	//애니메이션

	if (rectPos.bottom < -1.0f - (float)height / 512 || rectPos.right > 1.0f || rectPos.left < -1.0f || rectPos.top > 1.0f + (float)height / 512)
		return FALSE;

	float downTime = ((float)rand() / RAND_MAX)*0.3f;// +0.3f;
	printf("%2.3lf", downTime);
	switch (myPattern)
	{
	case 1:
		calcRect(0.0f, -downTime*delta);
		break;
	case 2:
		if (rectPos.left- (float)0.5*delta > -1.0f)
			calcRect(-0.5f*delta, -downTime*delta);//왼쪽아래로감
 		else { myPattern = 3; }
		break;
	case 3:
		if (rectPos.right+(float)0.5*delta <  1.0f)
			calcRect(+0.5f*delta, -downTime*delta);//오른쪽아래로감
		else { myPattern = 2; }
		
		break;
	}
	myMovTime += 10.0f*delta;
	if (myMovTime > 5.0f)
	{
		myPattern=rand() % PATTERN_MAX + 1;
		myMovTime = 0.0f;
		
	}

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
void Enemy::setPattern(int a)
{
	myPattern = a;
}
int Enemy::getPattern() {
	return myPattern;
}