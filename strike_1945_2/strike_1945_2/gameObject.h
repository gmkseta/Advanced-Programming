#pragma once
#include "stdafx.h"

using namespace glm;
class GameObject
{
public:
	int width;
	int height;
	vec3 _center;
	_RGBTRIPLE* arr=nullptr;
	DigitalCanvas2D* _canvas = nullptr;

	GameObject(){};
	~GameObject() {};

	void drawObject(DigitalCanvas2D _canvas, float plusX = 0.0f, float plusY = 0.0f) {
		for (int i = 0; i < this->height - 1; i++) {
			for (int j = 0; j < this->width; j++) {
				vec3 k = vec3(this->arr[i*this->width + j].rgbRed, this->arr[i*this->width + j].rgbGreen, this->arr[i*this->width + j].rgbBlue) / 255.0f;
				if (k!=RGBColors::black)// k.r != 0.0f&&k.g != 0.0f&&k.b != 0.0f)
					_canvas.drawDot(k, vec3(_center.x + plusX + (float)(j) / 512, _center.y + plusY + (float)i / 512, 0.0));
			}
		}
	}
	void drawObjectLowQuality(DigitalCanvas2D _canvas, int q) {
		for (int i = 0; i < this->height - 1; i += q) {
			for (int j = 0; j < this->width; j += q) {
				vec3 k = vec3(this->arr[i*this->width + j].rgbRed, this->arr[i*this->width + j].rgbGreen, this->arr[i*this->width + j].rgbBlue) / 255.0f;
				_canvas.drawBigDot(k, (float)q / 512, _center.x + (float)(j) / 512, _center.y + (float)i / 512);
			}
		}
	}
	void drawMapLowQuality(DigitalCanvas2D _canvas, int q,float position) {
		for (int i = 0; i < this->height - 1; i += q) {
			for (int j = 0; j < this->width; j += q) {
				int h = (i + (int)position) % height;
				vec3 k = vec3(this->arr[h*this->width + j].rgbRed, this->arr[h*this->width + j].rgbGreen, this->arr[h*this->width + j].rgbBlue) / 255.0f;
				_canvas.drawBigDot(k, (float)q / 512, _center.x + (float)(j) / 512, _center.y + (float)i / 512);
			}
		}
	}

};
