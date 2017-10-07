#pragma once
#include "stdafx.h"
#define IMG_NUM 10//이미지 갯수

class Cscreen
{
protected:
			
	void LoadBmpImg(char * filename, unsigned int MyImage);
	//filename  그림 경로
	//MyImage 이미지의 번호.
	

public:

	Bitmap bmpImage[IMG_NUM];

	Cscreen(void);
	virtual ~Cscreen(void);

	virtual void Init() = 0; //게임에 필요한 생성
	virtual void Draw() = 0;
	virtual void Destroy() = 0; //게임에 필요한 소멸
	virtual int ScreenUpdate(float delta) = 0;
								   //virtual : 자식에서 정의 하겠다.
};
