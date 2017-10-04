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
	Bitmap temp;

	GameObject(const char* filename){
		arr = nullptr;
		temp.readBmpImage(filename);
		
	}
	void init_image() {
		this->arr = temp.pixels;
		this->width = temp.ih.biWidth;
		this->height = temp.ih.biHeight;

	}

	//void copyArray(File_info *s) {
		
//	}

};

class PlayerPlane 
{

};