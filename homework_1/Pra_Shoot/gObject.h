#pragma once
#include "DigitalCanvas2D.h"
#include "RGBColors.h"
#include <iostream>
#include "Bitmap.h"

using namespace glm;
class GameObject
{
public:
	int width;
	int height;
	vec3 _center;
	_RGBTRIPLE* arr;
	Bitmap temp;

	GameObject(const char* filename){
		this->_center = vec3(0.0, 0.0, 0.0);
		this->arr = nullptr;
		this->temp.readBmpImage(filename);		
	}

	void init_image() {
		this->arr = temp.pixels;
		this->width = temp.ih.biWidth;
		this->height = temp.ih.biHeight;
	}
	
	void drawObject(DigitalCanvas2D _canvas) {
		for (int i = 0; i < this->height - 1; i++) {
			for (int j = 0; j < this->width; j++) {
				vec3 k = vec3(this->arr[i*this->width + j].rgbRed, this->arr[i*this->width + j].rgbGreen, this->arr[i*this->width + j].rgbBlue) / 255.0f;

				_canvas.drawDot(k, vec3(0.0 + (float)(j) / 400, 0.0 + (float)i / 400, 0.0));
			}
		}
	}
	

};

class PlayerPlane
{
};