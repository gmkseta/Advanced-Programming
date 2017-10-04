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

	GameObject(const char* filename,float x,float y) {
		this->_center = vec3(x, y, 0.0);
		this->arr = nullptr;
		this->temp.readBmpImage(filename);
		init_image();
	}
	GameObject(const char* filename) {
		this->_center = vec3(0.0, 0.0, 0.0);
		this->arr = nullptr;
		this->temp.readBmpImage(filename);
		init_image();
	}

	void init_image() {
		this->arr = temp.pixels;
		this->width = temp.ih.biWidth;
		this->height = temp.ih.biHeight;
	}

	void drawObject(DigitalCanvas2D _canvas,float plusX=0.0f,float plusY=0.0f) {
		for (int i = 0; i < this->height - 1; i++) {
			for (int j = 0; j < this->width; j++) {
				vec3 k = vec3(this->arr[i*this->width + j].rgbRed, this->arr[i*this->width + j].rgbGreen, this->arr[i*this->width + j].rgbBlue) / 255.0f;
				if(k.r!= 1.0f&&k.g!= 1.0f&&k.b!= 1.0f)
					_canvas.drawDot(k, vec3(_center.x+plusX + (float)(j) / 512, _center.y +plusY+(float)i / 512, 0.0));
			}
		}
	}
	void drawObjectLowQuality(DigitalCanvas2D _canvas,int q) {
		for (int i = 0; i < this->height - 1; i+=q) {
			for (int j = 0; j < this->width; j+=q) {
				vec3 k = vec3(this->arr[i*this->width + j].rgbRed, this->arr[i*this->width + j].rgbGreen, this->arr[i*this->width + j].rgbBlue) / 255.0f;
				_canvas.drawBigDot(k,(float)q/512 ,_center.x + (float)(j) / 512, _center.y + (float)i / 512);
			}
		}
	}


};

class PlayerPlane:public GameObject
{
public:

	PlayerPlane(const char* filename):GameObject(filename)
	{}


};

class PlayerBullet :public GameObject
{
public:
	vec3 _velocity;
	PlayerBullet(const char* filename) :GameObject(filename) {}
	void update(const float& dt)
	{
		_center += _velocity*dt;
	}
	void shoot(vec3 PlaneCenter)
	{		
		this->_center = PlaneCenter;
		this->_center.x += 0.1f;
		this->_center.y += 0.1f;
		this->_velocity = vec3(0.0, 3.0, 0.0);
	}


};

