#include "stdafx.h"
#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy()
{}

Enemy::~Enemy()
{}
void Enemy::Init(Bitmap bmpImage,Bitmap destoryImage, DigitalCanvas2D* my_canvas)
{

	srand((unsigned int)time(NULL));

	_canvas = my_canvas;	
	
	arr = bmpImage.pixels;
	width = bmpImage.ih.biWidth;
	height = bmpImage.ih.biHeight;

	Effect = destoryImage.pixels;
	effectWidth = destoryImage.ih.biWidth;
	effectHeight = destoryImage.ih.biHeight;

	rectPos.left = (float)rand()/RAND_MAX;
	rectPos.bottom = 1.0f+0.1f;
	calcRightTop();

	flag = FALSE;
	

	effectTime = 0.0f;

}

void Enemy::reRectPoint()
{
	calcRect(-0.8f+(float)(1.6f*rand()/RAND_MAX), 1.0f, 1);
	myPattern = rand() % PATTERN_MAX + 1;
	myMovTime = 0.0f;	
}

BOOL Enemy::Draw()
{
	//화면 밖이면 그냥 안그림
	if (checkArea()==FALSE)return FALSE;

	if (flag == FALSE)drawObjectLowQuality(*_canvas, 3);//drawObject(*_canvas);
	else drawEffect(*_canvas, Effect, effectPattern, rectPos);
	
	return TRUE;
}

BOOL Enemy::Update(float delta)
{
	//애니메이션

	if (checkArea()==FALSE)
		return FALSE;

	float downTime = ((float)rand() / RAND_MAX)*0.3f;// +0.3f;
    //랜덤한 속도로 내려가게 하기위해
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

	if (flag == TRUE)
		DestoryEffect(delta);


	return TRUE;
}

void Enemy::setPattern(int a)
{
	myPattern = a;
}
int Enemy::getPattern() {
	return myPattern;
}

void Enemy::DestoryEffect(float delta) {

	float allTime = 10.0f;
	effectTime += 15.0f*delta;
	
	if (effectTime > allTime / 16.0f*16.0f) { 
		effectPattern = 16; 
		flag = false;
		effectTime = 0.0f;
		rectPos.bottom = 1.5f;
		calcRightTop();
	}
	else if (effectTime > allTime / 16.0f*15.0f)	effectPattern = 15;
	else if (effectTime > allTime / 16.0f*14.0f)	effectPattern = 14;
	else if (effectTime > allTime / 16.0f*13.0f)	effectPattern = 13;
	else if (effectTime > allTime / 16.0f*12.0f)	effectPattern = 12;
	else if (effectTime > allTime / 16.0f*11.0f)	effectPattern = 11;
	else if (effectTime > allTime / 16.0f*10.0f)	effectPattern = 10;
	else if (effectTime > allTime / 16.0f*9.0f)		effectPattern = 9;
	else if (effectTime > allTime / 16.0f*8.0f)		effectPattern = 8;
	else if (effectTime > allTime / 16.0f*7.0f)		effectPattern = 7;
	else if (effectTime > allTime / 16.0f*6.0f)		effectPattern = 6;
	else if (effectTime > allTime / 16.0f*5.0f)		effectPattern = 5;
	else if (effectTime > allTime / 16.0f*4.0f)		effectPattern = 4;
	else if (effectTime > allTime / 16.0f*3.0f)		effectPattern = 3;
	else if (effectTime > allTime / 16.0f*2.0f)		effectPattern = 2;
	else if (effectTime > allTime / 16.0f*1.0f)		effectPattern = 1;
	else if (effectTime > allTime / 16.0f*0.0f)		effectPattern = 0;
	





}