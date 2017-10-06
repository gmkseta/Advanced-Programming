#include "stdafx.h"
#include "User.h"

User::User(DigitalCanvas2D* my_canvas) 
{
	_canvas = my_canvas;
}

User::~User(void)
{
	//Destroy();
}

void User::Init(Bitmap bmpImage)
{
	
	//처음 시작 위치
	
	//초기화
	m_fAnimation = 0;
	m_iShotNumber = 0;
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
	if (_canvas->isKeyPressed(GLFW_KEY_LEFT))	this->_center.x -= SPEED*delta;

	if (_canvas->isKeyPressed(GLFW_KEY_RIGHT))	this->_center.x += 0.01f;

	if (_canvas->isKeyPressed(GLFW_KEY_DOWN))this->_center.y -= 0.01f;

	if (_canvas->isKeyPressed(GLFW_KEY_UP))this->_center.y += 0.01f;

	//if (Left && !Right)
	//	m_fPosX -= SPEED * delta;
	//else//RIGHT
	//	if (Right && !Left)
	//		m_fPosX += SPEED * delta;

	////UP
	//if (Up && !Down)
	//	m_fPosY += SPEED * delta;
	//else//DOWN
	//	if (Down && !Up)
	//		m_fPosY -= SPEED * delta;

	////이동할 수 있는 지역일 경우 SetPosition
	//if (CheckPosition(m_fPosX, m_fPosY))
	//	SetPosition(m_fPosX, m_fPosY);

}

BOOL User::CheckPosition(float &x, float &y)
{
	if (x + 6.5f >= 51.2f || x <= 0.0f) x = m_rPos.left;
	if (y + 4.4f >= 65.0f || y <= 0.4f) y = m_rPos.bottom;

	return TRUE;
}

void User::SetPosition(float &x, float &y)
{
	m_rPos.top = y + 4.4f;
	m_rPos.left = x + 0.0f;
	m_rPos.right = x + 6.5f;
	m_rPos.bottom = y + 0.0f;
}


void User::Destroy()
{

}