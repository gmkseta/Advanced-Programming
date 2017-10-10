#include "stdafx.h"
#include "User.h"

User::User() 
{}

User::~User()
{}

void User::Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas)
{
	
	//처음 시작 위치
	_canvas = my_canvas;

	//초기화
	myBulletNum = 0;

	arr = bmpImage.pixels;
	width = bmpImage.ih.biWidth;
	height = bmpImage.ih.biHeight;
	movX = 0.0f;
	movY = -0.9999f;


}

void User::Draw()
{
	drawObject(*_canvas);
}

void User::Update(float delta)
{
	
	
	//LEFT 버튼이 눌렸을 경우
	if (_canvas->isKeyPressed(GLFW_KEY_LEFT))movX -= SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_RIGHT))movX += SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_DOWN))movY -= SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_UP))movY += SPEED*delta;

	
	////이동할 수 있는 지역일 경우 SetPosition
	if (CheckPosition(movX, movY)) 
		SetPosition(movX, movY);

}

BOOL User::CheckPosition(float &x, float &y)
{
	if (x + (float)width/ SCREEN_RATE >= 1.0f || x <= -1.0f) x = rectPos.left;
	if (y + (float)height/ SCREEN_RATE >= 1.0f || y <= -1.0f) y = rectPos.bottom;

	return TRUE;
}

void User::SetPosition(float &x, float &y)
{
	rectPos.left = x + 0.0f;
	rectPos.bottom = y + 0.0f;
	calcRightTop();

}

