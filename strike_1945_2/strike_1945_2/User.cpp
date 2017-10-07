#include "stdafx.h"
#include "User.h"

User::User(void) 
{}

User::~User(void)
{
	//Destroy();
}

void User::Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas)
{
	
	//처음 시작 위치
	_canvas = my_canvas;

	//초기화
	m_fAnimation = 0;
	myBulletNum = 0;
	m_fAnimationMaxPoint = 3;

	arr = bmpImage.pixels;
	width = bmpImage.ih.biWidth;
	height = bmpImage.ih.biHeight;
	movX = 0.0f;
	movY = 0.0f;


}

void User::Draw()
{
	drawObject(*_canvas);
}

void User::Update(float delta)
{
	//애니메이션
	//m_fAnimation += 32.0f * delta;

	//주인공 애니메이션의 종류는 3가지 3을 초과시 다시 처음부터 진행
	//if (m_fAnimation > m_fAnimationMaxPoint)
	//	m_fAnimation -= m_fAnimationMaxPoint;

	//BOOL Up = ((GetAsyncKeyState(VK_UP) & 0x8000) == 0x8000);
	//BOOL Down = ((GetAsyncKeyState(VK_DOWN) & 0x8000) == 0x8000);
	//BOOL Left = ((GetAsyncKeyState(VK_LEFT) & 0x8000) == 0x8000);
	//BOOL Right = ((GetAsyncKeyState(VK_RIGHT) & 0x8000) == 0x8000);

	
	
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
	if (x + (float)width/512 >= 1.0f || x <= -1.0f) x = rectPos.left;
	if (y + (float)height/512 >= 1.0f || y <= -1.0f) y = rectPos.bottom;

	return TRUE;
}

void User::SetPosition(float &x, float &y)
{
	rectPos.left = x + 0.0f;
	rectPos.bottom = y + 0.0f;
	calcRightTop();

}


void User::Destroy()
{

}