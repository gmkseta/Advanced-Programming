#pragma once
#include "DigitalCanvas2D.h"
#include "RGBColors.h"
#include <iostream>



class HumanCharacter
{
public:
	float x;
	float y;
	DigitalCanvas2D& canvas_;

	void drawRightArm(const float& time)
	{
		// yellow arm
		canvas_.beginTransformation();
		canvas_.rotate(sin(time*5.0) * 30.0);			// animation!
		canvas_.scale(1.0, 2.0);
		canvas_.translate(0.0, -0.1);
		canvas_.drawFilledBox(RGBColors::bred, 0.05, 0.18);
		canvas_.endTransformation();
	}
	void drawLeftArm(const float& time)
	{
		// yellow arm
		canvas_.beginTransformation();
		canvas_.rotate(sin(time*5.0) * -30.0);			// animation!
		canvas_.scale(1.0, 2.0);
		canvas_.translate(0.0, -0.1);
		canvas_.drawFilledBox(RGBColors::bred, 0.05, 0.18);
		canvas_.endTransformation();
	}
	void drawLeftLeg(const float& time)
	{
		canvas_.beginTransformation();
		canvas_.translate(0.0, -0.6);
		canvas_.translate(0.0, 0.2);
		canvas_.rotate(sin(time*5.0 + glm::pi<float>()) * -30.0);			// animation!
		canvas_.translate(0.0, -0.2);
		canvas_.drawFilledBox(RGBColors::bred, 0.1, 0.4);
		canvas_.endTransformation();
	}
	void drawRightLeg(const float& time)
	{
		canvas_.beginTransformation();
		canvas_.translate(0.0, -0.6);
		canvas_.translate(0.0, 0.2);
		canvas_.rotate(sin(time*5.0 + glm::pi<float>()) * 30.0);			// animation!
		canvas_.translate(0.0, -0.2);
		canvas_.drawFilledBox(RGBColors::bred, 0.1, 0.4);
		canvas_.endTransformation();
	}
	void drawBody()
	{
		canvas_.beginTransformation();
		canvas_.scale(1.0, 2.0);
		canvas_.translate(0.0, -0.1);
		canvas_.drawFilledBox(RGBColors::red, 0.13, 0.2);
		canvas_.endTransformation();
	}
	void drawFace()
	{
		canvas_.beginTransformation();
		canvas_.translate(0.0, 0.12);
		canvas_.drawFilledCircle(RGBColors::red, 0.08, 20);
		canvas_.endTransformation();
	}
	void drawPeople(const float& time)
	{
		canvas_.beginTransformation();
		canvas_.translate(x, y);
		// red face
		drawFace();
		drawLeftArm(time);
		drawLeftLeg(time);
		// blue body
		drawBody();
		//Rigth Arm and Leg
		drawRightArm(time); // HINT: you may use class like this
		drawRightLeg(time);
		canvas_.endTransformation();

	}
};