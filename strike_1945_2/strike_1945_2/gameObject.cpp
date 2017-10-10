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
void GameObject::drawObject(DigitalCanvas2D _canvas, float plusX, float plusY)
{
	for (int i = 0; i < height - 1; i++)
	{
		for (int j = 0; j < width; j++)
		{
			vec3 k = vec3(arr[i*width + j].rgbRed, arr[i*width + j].rgbGreen, arr[i*width + j].rgbBlue) / 255.0f;
			if (k != RGBColors::black)// k.r != 0.0f&&k.g != 0.0f&&k.b != 0.0f)
				_canvas.drawDot(k, vec3(rectPos.left + plusX + j / SCREEN_RATE, rectPos.bottom + plusY + i / SCREEN_RATE, 0.0));
		}
	}
}
	//ÁÂÇ¥ ÆÇº°¿ë .
	/*for (float i = rectPos.left; i < rectPos.right; i +=0.001f) {
		for (int j = 0; j < 10; j++) {
			_canvas.drawDot(RGBColors::red, vec3(i, rectPos.bottom+(float)j/ SCREEN_RATE, 0.0f));
		}
	}*/

void GameObject::drawObjectLowQuality(DigitalCanvas2D _canvas, int q)
{
	for (int i = 0; i < height - 1; i += q)
	{
		for (int j = 0; j < width; j += q)
		{
			vec3 k = vec3(arr[i*width + j].rgbRed, arr[i*width + j].rgbGreen, arr[i*width + j].rgbBlue) / 255.0f;
			if (k != RGBColors::black)// k.r != 0.0f&&k.g != 0.0f&&k.b != 0.0f)
				_canvas.drawBigDot(k, q / SCREEN_RATE, rectPos.left + (j) / SCREEN_RATE, rectPos.bottom + i / SCREEN_RATE);
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
			_canvas.drawBigDot(k, q / SCREEN_RATE, rectPos.left + (j) / SCREEN_RATE, rectPos.bottom + i / SCREEN_RATE);
		}
	}
}

void GameObject::drawEffect(DigitalCanvas2D _canvas, _RGBTRIPLE* arr,int x,RECT_POINT rectPos) 
{
	for (int i = 0; i < 80 - 1; i++)
	{
		for (int j = x*70; j < x*70+70; j++)
		{
			vec3 k = vec3(arr[i*1120 + j].rgbRed, arr[i* 1120 + j].rgbGreen, arr[i* 1120 + j].rgbBlue) / 255.0f;
			if (k != RGBColors::black)// k.r != 0.0f&&k.g != 0.0f&&k.b != 0.0f)
				_canvas.drawDot(k, vec3(rectPos.left  + (j-x*70) / SCREEN_RATE, rectPos.bottom  + i / SCREEN_RATE, 0.0));
		}
	}
}


void GameObject::drawLetter(DigitalCanvas2D _canvas, Bitmap lettering,float x,float y) {
	for (int i = 0; i < lettering.ih.biHeight-1; i++)
	{
		for (int j = 0; j < lettering.ih.biWidth; j++)
		{
			vec3 k = vec3(
				lettering.pixels[i*lettering.ih.biWidth + j].rgbRed,
				lettering.pixels[i*lettering.ih.biWidth + j].rgbGreen,
				lettering.pixels[i*lettering.ih.biWidth + j].rgbBlue
			) / 255.0f;
			if (k != RGBColors::black)// k.r != 0.0f&&k.g != 0.0f&&k.b != 0.0f)
				_canvas.drawDot(k, vec3(x+(-lettering.ih.biWidth/2.0f+j)/ SCREEN_RATE,y+ (-lettering.ih.biHeight / 2.0f + i) / SCREEN_RATE, 0.0f));
		}
	}

}


void GameObject::drawNumber(DigitalCanvas2D _canvas, Bitmap lettering, float x, float y,int num,int scope) {
	for (int i = 0; i < lettering.ih.biHeight - 1; i+=scope)
	{
		for (int j = 70*num; j < 70*num+70; j+=scope)
		{
			vec3 k = vec3(
				lettering.pixels[i*lettering.ih.biWidth + j].rgbRed,
				lettering.pixels[i*lettering.ih.biWidth + j].rgbGreen,
				lettering.pixels[i*lettering.ih.biWidth + j].rgbBlue
			) / 255.0f;
			if (k != RGBColors::black)// k.r != 0.0f&&k.g != 0.0f&&k.b != 0.0f)
				_canvas.drawDot(k, vec3(x+(float)((j-num*70)/scope)/ SCREEN_RATE, y+(float)i/scope / SCREEN_RATE, 0.0f));
		}
	}

}


BOOL GameObject::checkArea()
{
	if (
		rectPos.left < -1.0f - width / SCREEN_RATE ||
		rectPos.right > 1.0f + width / SCREEN_RATE || 
		rectPos.bottom < -1.0f - height / SCREEN_RATE ||
		rectPos.top > 1.0f + height / SCREEN_RATE
		)return FALSE;
	return TRUE;
}
