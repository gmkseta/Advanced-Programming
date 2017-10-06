#pragma once
#include "stdafx.h"

class Cscreen
{
protected:
			
	void LoadBmpImg(char * filename, unsigned int MyImage);
	//filename  �׸� ���
	//MyImage �̹����� ��ȣ.
	

public:

	Bitmap bmpImage[10];

	Cscreen(void);
	virtual ~Cscreen(void);

	virtual void Init() = 0; //���ӿ� �ʿ��� ����
	virtual void Draw() = 0;
	virtual void Destroy() = 0; //���ӿ� �ʿ��� �Ҹ�
	virtual int ScreenUpdate(float delta) = 0;
								   //virtual : �ڽĿ��� ���� �ϰڴ�.
};
