#pragma once
#define SCREEN_RATE 512.0f
#include "stdafx.h"
using namespace glm;

struct RECT_POINT
{
	float top;
	float left;
	float right;
	float bottom;

	RECT_POINT()
	{
		top = 0;
		left = 0;
		right = 0;
		bottom = 0;
	}

};

class GameObject
{
public:
	int width;
	int height;

	_RGBTRIPLE* arr=nullptr;
	RECT_POINT rectPos;
	DigitalCanvas2D* _canvas = nullptr;
	
	GameObject(){};
	~GameObject() {};
	void calcRightTop();//left bottom���� ���� right top���
	void calcRect(float x, float y,int ver=0 );//�Ű����������� �� �־���
	//ver �� 0�̸� �������� x y ���� �߰�
	//ver �� 1�̸� x y ������ �ٲٴ� ���
	void drawObject(DigitalCanvas2D _canvas, float plusX = 0.0f, float plusY = 0.0f);//�⺻���� ���
	void drawObjectLowQuality(DigitalCanvas2D _canvas, int q);//q �������� ����Ƽ�� �������� ���
	void drawMapLowQuality(DigitalCanvas2D _canvas, int q, float position);//����� ���� position�� �����Ҽ��ִ� ���
	void drawEffect(DigitalCanvas2D _canvas,_RGBTRIPLE *arr ,int x, RECT_POINT rectPos);//effect�� ���
	static void drawLetter(DigitalCanvas2D _canvas, Bitmap lettering, float x = 0.0f, float y = 0.0f);//�������
	static void drawNumber(DigitalCanvas2D _canvas, Bitmap lettering, float x, float y, int num, int scope);//�������
	BOOL checkArea();


};
