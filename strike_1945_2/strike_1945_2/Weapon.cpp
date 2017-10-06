#include "stdafx.h"
#include "Weapon.h"


unsigned int Weapon::MissleTextureObject = 0;

Weapon::Weapon(void)
{
	//화면 밖에서 대기중.
	Init(0, 72);
}

Weapon::~Weapon(void)
{
	Destroy();
}


void Weapon::Init(float x, float y)
{
	rectPos.top = y + (float)height / 512;
	rectPos.left = x - (float)width / 1024;
	rectPos.right = x + (float)width / 1024;
	rectPos.bottom = y;

}

BOOL Weapon::Draw()
{
	//화면 밖에 있을 경우 그림을 그리지 않는다.
	if (rectPos.bottom > 1.0f)
		return FALSE;

	drawObject();


	return TRUE;
}
BOOL Weapon::Update(float delta)
{
	//화면 안에 미사일이 있을 경우 TRUE를 반환
	if (rectPos.bottom < 71.0f)
	{
		rectPos.top += 40.0 * delta;
		rectPos.bottom += 40.0 * delta;
		return TRUE;
	}

	//화면밖일 경우 FALSE 반환
	return FALSE;
}
void Weapon::Destroy()
{

}