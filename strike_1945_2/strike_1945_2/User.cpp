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
	vec3 _center = vec3(0.0f, 0.0f, 0.0f);

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
	if (_canvas->isKeyPressed(GLFW_KEY_LEFT))_center.x -= SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_RIGHT))_center.x += SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_DOWN))_center.y -= SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_UP))_center.y += SPEED*delta;

	
	////이동할 수 있는 지역일 경우 SetPosition
	if (CheckPosition(_center.x, _center.y)) 
		SetPosition(_center.x, _center.y);

}

BOOL User::CheckPosition(float &x, float &y)
{
	if (x + (float)width/512 >= 1.0f || x <= -1.0f) x = rectPos.left;
	if (y + (float)height/512 >= 1.0f || y <= -1.0f) y = rectPos.bottom;

	return TRUE;
}

void User::SetPosition(float &x, float &y)
{
	rectPos.top = y + (float)height/512;
	rectPos.left = x + 0.0f;
	rectPos.right = x + (float)width / 512;
	rectPos.bottom = y + 0.0f;
}


void User::Destroy()
{

}