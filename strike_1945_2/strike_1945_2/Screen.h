#pragma once
#include "stdafx.h"

class Cscreen
{
protected:
									   //�ؽ���
	void LoadBmpImg(char * filename, unsigned int MyImage);
	//filename : �׸� ���
	//MyImage : �ؽ��� ��ȣ
	

public:

	Bitmap bmpImage[10];

	Cscreen(void);
	virtual ~Cscreen(void);

	virtual HRESULT Init() = 0; //���ӿ� �ʿ��� ����
	virtual HRESULT Draw() = 0;
	//virtual int FrameMove(float delta) = 0;
	virtual HRESULT Destroy() = 0; //���ӿ� �ʿ��� �Ҹ�

								   //virtual : �ڽĿ��� ���� �ϰڴ�.
};
