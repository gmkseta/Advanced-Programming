#include "DigitalCanvas2D.h"
#include "RGBColors.h"
#include <iostream>
#include <vector>
#include <timeapi.h>
using namespace std;
using namespace glm;
const float g = -9.8f;

DigitalCanvas2D my_canvas("This is my digital canvas!", 1024, 768); // Canvas : (-1.0, -1.0) x (1.0, 1.0)

class Ball
{
public:
	vec2 center_;
	vec2 fix_;

	float angle = 0.0f;
	float aVel = 0.0f;
	float aAcc = 0.0f;
	
	
	const float r = 0.1f;
	const float l = 0.5f;

	Ball(float x) {
		center_ = vec2(x, 0.0f);
		fix_ = center_ + vec2(0.0f, l);
		

	}
	void draw()
	{
		my_canvas.drawLine(RGBColors::black, center_, RGBColors::black, fix_);
		my_canvas.beginTransformation();
		my_canvas.translate(center_.x,center_.y);
		my_canvas.drawFilledCircle(RGBColors::red,r, 16);
		my_canvas.endTransformation();
	}
	void move(const float dt)
	{

		aAcc = g*sin(angle);
		aVel += aAcc;
		angle += aVel*dt*0.001f;
		center_ =vec2(fix_.x-l*sin(angle), fix_.y - l*cos(angle));
	}
	void hold()
	{
		aAcc = 0.0f;
		aVel = 0.0f;
		center_ = vec2(fix_.x - l*sin(angle), fix_.y - l*cos(angle));
	}
	
};

void collision(Ball* bal_1, Ball* bal_2)
{
	if (glm::length(bal_1->center_ - bal_2->center_) < bal_1->r + bal_2->r)
	{
	
		if(bal_1->aVel-bal_2->aVel<0 && bal_1->center_.x - bal_2->center_.x <0 )
		{
			bal_2->aVel = bal_1->aVel;
			bal_1->aVel = 0.0f;			
		}
		else if (bal_1->aVel - bal_2->aVel > 0 && bal_1->center_.x - bal_2->center_.x > 0)
		{
			bal_2->aVel = bal_1->aVel;
			bal_1->aVel = 0.0f;
		}
	}
	
}

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

	for (int i = 0; i < 4; i++)
	{
		ball_list.push_back(new Ball(-0.3f+0.1f*2*i));
	}

	my_canvas.show([&]
	{
		for (auto itr : ball_list)
		{
			itr->move(timeDelta);
			itr->draw();
			for (auto itr2 : ball_list)
			{
				if (itr != itr2)
					collision(itr, itr2);
			}
		}
		if (my_canvas.isKeyPressed(GLFW_KEY_RIGHT))
		{
			ball_list[ball_list.size() - 1]->angle = -0.5f;
			ball_list[ball_list.size() - 1]->hold();
			if (my_canvas.isKeyPressed(GLFW_KEY_2))
			{
				ball_list[ball_list.size() - 2]->angle = -0.5f;
				ball_list[ball_list.size() - 2]->hold();
			}
		}
		
		
		getDelta();
		
	}
	);

	return 0;
}
