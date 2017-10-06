#pragma once
#include "stdafx.h"

class Cscreen
{
protected:
									   //텍스쳐
	void LoadBmpImg(char * filename, unsigned int MyImage);
	//filename : 그림 경로
	//MyImage : 텍스쳐 번호
	

public:

	Bitmap bmpImage[10];

	Cscreen(void);
	virtual ~Cscreen(void);

	virtual HRESULT Init() = 0; //게임에 필요한 생성
	virtual HRESULT Draw() = 0;
	//virtual int FrameMove(float delta) = 0;
	virtual HRESULT Destroy() = 0; //게임에 필요한 소멸

								   //virtual : 자식에서 정의 하겠다.
};
