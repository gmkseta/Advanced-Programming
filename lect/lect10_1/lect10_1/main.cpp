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
	vec2 fix_;

	float angle = 0.0f;
	float aVel = 0.0f;
	float aAcc = 0.0f;
	
	
	const float r=0.1f;
	Ball(float x) {
		center_ = vec2(x, 0.0f);
		fix_ = center_ + vec2(0.0f, 0.5f);
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
	}

	void collision()
	{
	}
};


float lastTime = (float)timeGetTime();
float timeDelta = 0.0f;
void Update()
{
	float currentTime = (float)timeGetTime();//현재 시간을 저장
	timeDelta = (currentTime - lastTime)*0.001f;
	//현재 시간과 마지막으로 저장햇던 시간의 차이로 델타 타임을 구함
	lastTime = currentTime;
}

int main(void)
{
	//Ball my_ball;

	float time = 0.0;
	const float dt = 0.0003f;

	const float coef_res = 0.5f;

	vector<Ball*> ball_list;

	for (int i = 0; i < 3; i++)
	{
		ball_list.push_back(new Ball(-0.1f*2*i));
	}



	my_canvas.show([&]
	{
		
		for (auto itr : ball_list)
		{
			itr->collision();
			itr->move(dt);
			itr->draw();

		}


		time += 1 / 60.0;
	}
	);

	return 0;
}
