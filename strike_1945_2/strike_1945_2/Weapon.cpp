#include "stdafx.h"
#include "Weapon.h"


unsigned int Weapon::MissleTextureObject = 0;

Weapon::Weapon(void)
{
	//ȭ�� �ۿ��� �����.
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
	//ȭ�� �ۿ� ���� ��� �׸��� �׸��� �ʴ´�.
	if (rectPos.bottom > 1.0f)
		return FALSE;

	drawObject();


	return TRUE;
}
BOOL Weapon::Update(float delta)
{
	//ȭ�� �ȿ� �̻����� ���� ��� TRUE�� ��ȯ
	if (rectPos.bottom < 71.0f)
	{
		rectPos.top += 40.0 * delta;
		rectPos.bottom += 40.0 * delta;
		return TRUE;
	}

	//ȭ����� ��� FALSE ��ȯ
	return FALSE;
}
void Weapon::Destroy()
{

}