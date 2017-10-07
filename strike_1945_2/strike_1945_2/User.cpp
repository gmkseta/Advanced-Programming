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
	movX = 0.0f;
	movY = 0.0f;


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
	if (_canvas->isKeyPressed(GLFW_KEY_LEFT))movX -= SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_RIGHT))movX += SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_DOWN))movY -= SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_UP))movY += SPEED*delta;

	
	////�̵��� �� �ִ� ������ ��� SetPosition
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