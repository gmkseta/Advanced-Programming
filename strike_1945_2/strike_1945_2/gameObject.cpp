#include "stdafx.h"
#include "gameObject.h"

void GameObject::calcRightTop()
{
	rectPos.right = rectPos.left + (float)width / SCREEN_RATE;
	rectPos.top = rectPos.bottom + (float)height / SCREEN_RATE;
}
void GameObject::calcRect(float x, float y,int ver)
{
	if (ver == 0) 
	{
		rectPos.left += x;
		rectPos.bottom += y;
	}
	else if (ver == 1)
	{
		rectPos.left = x;
		rectPos.bottom = y;
	}
	calcRightTop();
}
void GameObject::drawObject(DigitalCanvas2D _canvas, float plusX , float plusY )
{
	for (int i = 0; i < height - 1; i++)
	{
		for (int j = 0; j < width; j++)
		{
			vec3 k = vec3(arr[i*width + j].rgbRed, arr[i*width + j].rgbGreen, arr[i*width + j].rgbBlue) / 255.0f;
			if (k != RGBColors::black)// k.r != 0.0f&&k.g != 0.0f&&k.b != 0.0f)
				_canvas.drawDot(k, vec3(rectPos.left + plusX + (float)(j) / SCREEN_RATE, rectPos.bottom + plusY + (float)i / SCREEN_RATE, 0.0));
		}
	}
	//ÁÂÇ¥ ÆÇº°¿ë .
	/*for (float i = rectPos.left; i < rectPos.right; i +=0.001f) {
		for (int j = 0; j < 10; j++) {
			_canvas.drawDot(RGBColors::red, vec3(i, rectPos.bottom+(float)j/ SCREEN_RATE, 0.0f));
		}
	}*/
}
void GameObject::drawObjectLowQuality(DigitalCanvas2D _canvas, int q)
{
	for (int i = 0; i < height - 1; i += q)
	{
		for (int j = 0; j < width; j += q)
		{
			vec3 k = vec3(arr[i*width + j].rgbRed, arr[i*width + j].rgbGreen, arr[i*width + j].rgbBlue) / 255.0f;
			_canvas.drawBigDot(k, (float)q / SCREEN_RATE, rectPos.left + (float)(j) / SCREEN_RATE, rectPos.bottom + (float)i / SCREEN_RATE);
		}
	}
}
void GameObject::drawMapLowQuality(DigitalCanvas2D _canvas, int q, float position)
{
	for (int i = 0; i < height - 1; i += q)
	{
		for (int j = 0; j < width; j += q)
		{
			int h = (i + (int)position) % height;
			vec3 k = vec3(arr[h*width + j].rgbRed, arr[h*width + j].rgbGreen, arr[h*width + j].rgbBlue) / 255.0f;
			_canvas.drawBigDot(k, (float)q / SCREEN_RATE, rectPos.left + (float)(j) / SCREEN_RATE, rectPos.bottom + (float)i / SCREEN_RATE);
		}
	}
}
