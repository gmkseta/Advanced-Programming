#pragma once
#include "DigitalCanvas2D.h"
#include "RGBColors.h"
#include <iostream>
#include <vector>
#include "Bitmap.h"
class GameObject
{
public:
	float x;//x ¿Í y ÁÂÇ¥
	float y;
	_RGBTRIPLE* arr;
	int width;
	int height;

	GameObject(){
		x = 0; y = 0; width = 0; height = 0;
		arr = nullptr;
	}
	void init_image(Bitmap* s) {
		this->arr = s->pixels;
		this->width = s->ih.biWidth;
		this->height = s->ih.biHeight;

	}

	//void copyArray(File_info *s) {
		
//	}

};

class PlayerPlane 
{

};