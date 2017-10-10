#pragma once
#include "stdafx.h"
#define IMG_NUM 10//�̹��� ����

class Screen
{
protected:
	void LoadBmpImg(char * filename, unsigned int MyImage);
	//filename  �׸� ��� MyImage �̹����� ��ȣ.(GameBoard ���� enum���� ����Ǿ�����)

public:
	Bitmap bmpImage[IMG_NUM];
	//�̹����� ������ �迭 
	Screen(void);
	virtual ~Screen(void);
	virtual void Init() = 0;//���ӿ� �ʿ��� �ʱ�ȭ
	virtual void Draw() = 0;//ȭ�鿡 �׷���
	virtual int ScreenUpdate(float delta) = 0;//���� ��ǥ ������Ʈ
								   //virtual : �ڽĿ��� ���� �ϰڴ�.
};
