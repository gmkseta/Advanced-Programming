#pragma once
#include "stdafx.h"
#define IMG_NUM 10//이미지 갯수

class Screen
{
protected:
	void LoadBmpImg(char * filename, unsigned int MyImage);
	//filename  그림 경로 MyImage 이미지의 번호.(GameBoard 에서 enum으로 선언되어있음)

public:
	Bitmap bmpImage[IMG_NUM];
	//이미지를 저장할 배열 
	Screen(void);
	virtual ~Screen(void);
	virtual void Init() = 0;//게임에 필요한 초기화
	virtual void Draw() = 0;//화면에 그려줌
	virtual int ScreenUpdate(float delta) = 0;//게임 좌표 업데이트
								   //virtual : 자식에서 정의 하겠다.
};
