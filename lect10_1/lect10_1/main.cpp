#include "DigitalCanvas2D.h"
#include "RGBColors.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace glm;

DigitalCanvas2D my_canvas("This is my digital canvas!", 1024, 768); // Canvas : (-1.0, -1.0) x (1.0, 1.0)

class Ball
{
public:
	float center_x, center_y;
	float vel_x, vel_y;
	float acc_x, acc_y;
	const float r=0.1f;
	const float coef_res = 0.5f;
	Ball(float x) {
		center_x = x; center_y = -0.05f; vel_x = 1.0f; vel_y = 3.0f;
		acc_x = 0.0f; acc_y = -9.8f;

	}
	void draw()
	{
		my_canvas.beginTransformation();
		my_canvas.translate(center_x,center_y);
		my_canvas.drawFilledCircle(RGBColors::red,r, 16);
		my_canvas.endTransformation();
	}
	void move(const float dt)
	{
		center_x += vel_x*dt;
		center_y += vel_y*dt;
		vel_x += acc_x*dt;
		vel_y += acc_y*dt;
	}

	void collision()
	{
		if (center_y - r <= -0.4f&&vel_y<=0.0f)
		{
		//collision response
			vel_y = -vel_y*coef_res;
		}
		if (center_x-2.0f*r>= 1.0f &&vel_x >= 0.0f)
		{
			vel_x = -vel_x*coef_res;
		}
	}
};

int main(void)
{
	//Ball my_ball;

	float time = 0.0;
	const float dt = 0.0003f;
	float r = 0.10;
	const float coef_res = 0.5f;

	vector<Ball*> ball_list;

	for (int i = 0; i < 3; i++)
	{
		ball_list.push_back(new Ball(-0.3f*i));
	}



	my_canvas.show([&]
	{
		// update

		//collision detection between ball and ground
		//if (my_ball.center_y - r <= -0.4f&&my_ball.vel_y<=0.0f)
		//{
			//collision response
		//	my_ball.vel_y = -my_ball.vel_y*coef_res;
		//}
		// move tank
		//if (my_canvas.isKeyPressed(GLFW_KEY_SPACE)) {}
		//1st order Euler integration
		//my_ball.move(dt);
		//my_ball.draw();
		for (auto itr : ball_list)
		{
			itr->collision();
			itr->move(dt);
			itr->draw();

		}

		my_canvas.beginTransformation();
		my_canvas.translate(0.0f, -0.9);
		my_canvas.drawFilledBox(RGBColors::green, 10, 1.0);
		my_canvas.endTransformation();

		time += 1 / 60.0;
	}
	);

	return 0;
}
