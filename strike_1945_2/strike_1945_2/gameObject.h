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
	void calcRightTop();//left bottom값에 따라서 right top계산
	void calcRect(float x, float y,int ver=0 );//매개변수에따라 값 넣어줌
	//ver 이 0이면 기존에서 x y 값을 추가
	//ver 이 1이면 x y 값으로 바꾸는 방식
	void drawObject(DigitalCanvas2D _canvas, float plusX = 0.0f, float plusY = 0.0f);//기본적인 출력
	void drawObjectLowQuality(DigitalCanvas2D _canvas, int q);//q 값에따라서 퀄리티가 낮아지는 출력
	void drawMapLowQuality(DigitalCanvas2D _canvas, int q, float position);//배경을 위해 position을 설정할수있는 출력
	void drawEffect(DigitalCanvas2D _canvas,_RGBTRIPLE *arr ,int x, RECT_POINT rectPos);//effect를 출력
	static void drawLetter(DigitalCanvas2D _canvas, Bitmap lettering, float x = 0.0f, float y = 0.0f);//문자출력
	static void drawNumber(DigitalCanvas2D _canvas, Bitmap lettering, float x, float y, int num, int scope);//숫자출력
	BOOL checkArea();


};
