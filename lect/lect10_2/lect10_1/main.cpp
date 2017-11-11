#include "DigitalCanvas2D.h"
#include "RGBColors.h"
#include <iostream>
#include <vector>
#include <timeapi.h>
using namespace std;
using namespace glm;

DigitalCanvas2D my_canvas("This is my digital canvas!", 1024, 768); // Canvas : (-1.0, -1.0) x (1.0, 1.0)

class Ball
{
public:
	vec2 center_;
	//vec2 vel_;
	//vec2 acc_;
	vec2 fix_;

	float angle;
	float aVel = 0.0f;
	float aAcc = 0.0f;


	
	const float l = 0.5f;
	const float g = 9.8f;

	const float r=0.1f;
	

	Ball(float x) {
		center_ = vec2(x+0.3f, 0.0f);
		//vel_ = vec2(0.0f, 0.0f);
		//acc_ = vec2(0.0f, 0.0f);
		fix_ = center_+vec2(0.0,l);
		angle = 0.0f;		
	}

	void draw()
	{
		my_canvas.drawLine(RGBColors::black, fix_, RGBColors::black, center_);
		my_canvas.beginTransformation();
		my_canvas.translate(center_.x,center_.y);
		my_canvas.drawFilledCircle(RGBColors::red,r, 16);
		my_canvas.endTransformation();
		
	}
	void move(const float dt)
	{
		aAcc = (-1 * g/ l)*sin(angle);
		aVel += aAcc*dt*0.001f;
		angle += aVel;
		center_.y= fix_.y-l*cos(angle);
		center_.x= fix_.x-l*sin(angle);
	}
	void zeroVel(const float in_ang)
	{
		aAcc = (-1 * g / l)*sin(in_ang);
		aVel = 0;
		angle = in_ang;
		center_.y = fix_.y - l*cos(angle);
		center_.x = fix_.x - l*sin(angle);
	}
};



void collision(Ball &bal_1,Ball &bal_2)
{
	if (glm::length(bal_1.center_ - bal_2.center_) <= bal_1.l + bal_2.l)
	{
		if (bal_1.aVel - bal_2.aVel < 0)
		{
			bal_1.aVel = bal_2.aVel;
			bal_2.aVel = 0.0f;
		}
	}
	
}




//시간관련 변수
float lastTime = (float)timeGetTime();
float timeDelta = 0.0f;

void getDelta()
{
	float currentTime = (float)timeGetTime();//현재 시간을 저장
	timeDelta = (currentTime - lastTime)*0.001f;
	//현재 시간과 마지막으로 저장햇던 시간의 차이로 델타 타임을 구함
	lastTime = currentTime;
}

int main(void)
{

	vector<Ball*> ball_list;
	for (int i = 0; i < 2; i++)
	{
		ball_list.push_back(new Ball(-0.1f*2*i));
	}

	float T = 9.8f;
	float v;
	my_canvas.show([&]
	{
		
		if (my_canvas.isKeyPressed(GLFW_KEY_RIGHT))
		{
			ball_list[0]->zeroVel(-0.5f);
			for (auto itr : ball_list)
			{
				itr->draw();
			}
		}
		else if (my_canvas.isKeyPressed(GLFW_KEY_LEFT))
		{
			ball_list[0]->angle += 0.005f;
		}
		else
		{

			for (auto itr : ball_list)
			{
				collsion
				itr->move(timeDelta);
				itr->draw();
			}
			
		}

		cout << ball_list[0]->aVel<< endl;
		getDelta();
	}
	);

	return 0;
}

