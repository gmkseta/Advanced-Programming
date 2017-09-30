#pragma once
#include "DigitalCanvas2D.h"
#include "RGBColors.h"
#include <iostream>
#include <vector>
class MyTank
{
public:

	DigitalCanvas2D _canvas;
	vec3 center_;
	vec3 direction_;

	void draw()
	{
		_canvas.beginTransformation();
		_canvas.translate(center_.x, center_.y);
		_canvas.drawFilledBox(RGBColors::green, 0.25, 0.1);
		_canvas.translate(-0.02, 0.1);
		_canvas.drawFilledBox(RGBColors::blue, 0.15, 0.09);
		_canvas.translate(0.15, 0.0);
		_canvas.drawFilledBox(RGBColors::red, 0.15, 0.03);
		_canvas.endTransformation();
	}
};

class MyWeapon
{
public:
	DigitalCanvas2D _canvas;
	vec3 center_;
	vec3 velocity_;
	float l = 0.0;
	int flag = 0;
	void draw()
	{
		_canvas.beginTransformation();
		_canvas.translate(center_.x, center_.y);
		_canvas.drawFilledCircle(RGBColors::yellow, 0.02, 8);
		_canvas.endTransformation();
	}

	void update(const float& dt)
	{
		center_ += velocity_*dt;
	}
	void update_l(const float& dt)
	{
		l += dt*1.5;

	}
	void draw_laser()
	{
		_canvas.beginTransformation();
		_canvas.translate(center_.x + l / 2 - 0.1, center_.y + 0.02);
		_canvas.drawFilledBox(RGBColors::yellow, l, 0.02);
		_canvas.endTransformation();
	}


};
