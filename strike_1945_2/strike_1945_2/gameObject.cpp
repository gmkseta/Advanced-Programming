#include "stdafx.h"
#include "gameObject.h"

void GameObject::calcRightTop()
{
	this->rectPos.right = this->rectPos.left + width / SCREEN_RATE;
	this->rectPos.top = rectPos.bottom + height / SCREEN_RATE;
}
void GameObject::drawObject(DigitalCanvas2D _canvas, float plusX , float plusY )
{
	for (int i = 0; i < this->height - 1; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			vec3 k = vec3(this->arr[i*this->width + j].rgbRed, this->arr[i*this->width + j].rgbGreen, this->arr[i*this->width + j].rgbBlue) / 255.0f;
			if (k != RGBColors::black)// k.r != 0.0f&&k.g != 0.0f&&k.b != 0.0f)
				_canvas.drawDot(k, vec3(rectPos.left + plusX + (float)(j) / 512, rectPos.bottom + plusY + (float)i / 512, 0.0));
		}
	}
}
void GameObject::drawObjectLowQuality(DigitalCanvas2D _canvas, int q)
{
	for (int i = 0; i < this->height - 1; i += q)
	{
		for (int j = 0; j < this->width; j += q)
		{
			vec3 k = vec3(this->arr[i*this->width + j].rgbRed, this->arr[i*this->width + j].rgbGreen, this->arr[i*this->width + j].rgbBlue) / 255.0f;
			_canvas.drawBigDot(k, (float)q / 512, rectPos.left + (float)(j) / 512, rectPos.bottom + (float)i / 512);
		}
	}
}
void GameObject::drawMapLowQuality(DigitalCanvas2D _canvas, int q, float position)
{
	for (int i = 0; i < this->height - 1; i += q)
	{
		for (int j = 0; j < this->width; j += q)
		{
			int h = (i + (int)position) % height;
			vec3 k = vec3(this->arr[h*this->width + j].rgbRed, this->arr[h*this->width + j].rgbGreen, this->arr[h*this->width + j].rgbBlue) / 255.0f;
			_canvas.drawBigDot(k, (float)q / 512, rectPos.left + (float)(j) / 512, rectPos.bottom + (float)i / 512);
		}
	}
}
