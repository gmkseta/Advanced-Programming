#pragma once
#define SCREEN_RATE 512
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
	void calcRightTop();
	void drawObject(DigitalCanvas2D _canvas, float plusX = 0.0f, float plusY = 0.0f);
	void drawObjectLowQuality(DigitalCanvas2D _canvas, int q);
	void drawMapLowQuality(DigitalCanvas2D _canvas, int q, float position);



};
