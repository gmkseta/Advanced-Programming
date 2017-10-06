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
	
	//ó�� ���� ��ġ
	_canvas = my_canvas;

	//�ʱ�ȭ
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
	//�ִϸ��̼�
	//m_fAnimation += 32.0f * delta;

	//���ΰ� �ִϸ��̼��� ������ 3���� 3�� �ʰ��� �ٽ� ó������ ����
	//if (m_fAnimation > m_fAnimationMaxPoint)
	//	m_fAnimation -= m_fAnimationMaxPoint;

	//BOOL Up = ((GetAsyncKeyState(VK_UP) & 0x8000) == 0x8000);
	//BOOL Down = ((GetAsyncKeyState(VK_DOWN) & 0x8000) == 0x8000);
	//BOOL Left = ((GetAsyncKeyState(VK_LEFT) & 0x8000) == 0x8000);
	//BOOL Right = ((GetAsyncKeyState(VK_RIGHT) & 0x8000) == 0x8000);

	
	
	//LEFT ��ư�� ������ ���
	if (_canvas->isKeyPressed(GLFW_KEY_LEFT))_center.x -= SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_RIGHT))_center.x += SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_DOWN))_center.y -= SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_UP))_center.y += SPEED*delta;

	
	////�̵��� �� �ִ� ������ ��� SetPosition
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