#include "DigitalCanvas2D.h"
#include "RGBColors.h"
#include <iostream>

using namespace std;
using namespace glm;

DigitalCanvas2D my_canvas("This is my digital canvas!", 1024, 768); // Canvas : (-1.0, -1.0) x (1.0, 1.0)

class Ball
{
public: 
	float center_x, center_y;
	float radius;
	float velocity_x, velocity_y;
	
	void draw() {
		my_canvas.beginTransformation();
		my_canvas.translate(center_x, center_y);
		my_canvas.drawFilledCircle(RGBColors::red, 0.10, 16);
		my_canvas.endTransformation();
	}

	void setVelocity(const float& _vx, const float& _vy)
	{
		velocity_x = _vx;
		velocity_y = _vy;
	}

	void updateEuler(const float& ac_x, const float& ac_y,const float& dt)
	{
		center_x +=velocity_x*dt;
		center_y +=velocity_y*dt;
		velocity_x += ac_x*dt;
		velocity_y += ac_y*dt;
	}






};


int main(void)
{
	float time = 0.0;
	const float dt = 0.0001;
	const float g = 9.8;
	const float ga_x = 0.0;
	const float ga_y = -g;
	const float coef_res = 0.5;

	Ball my_ball{ -1.0f,0.0f ,0.1f,0.0f};
	my_ball.setVelocity(1.0f, 3.0f);
	my_canvas.show([&]
	{
		if (my_ball.center_y - my_ball.radius <= -0.4 && my_ball.velocity_y<0.0f)
		{   //center_y - my_ball 
			//collision response
			my_ball.velocity_y = -my_ball.velocity_y*coef_res;
		}

		// update
		//1st order Euler Intergration
		my_ball.updateEuler(ga_x, ga_y, dt);

		// move tank
		if (my_canvas.isKeyPressed(GLFW_KEY_SPACE)) {}


		my_ball.draw();


		my_canvas.beginTransformation();
		my_canvas.translate(0.0f, -0.9);
		my_canvas.drawFilledBox(RGBColors::green, 10, 1.0);//여기서 높이가 ㅇㅇ
		//그림이 딱 센터인가봄 1.0으로 그려지나봄 그래서 
		//
		my_canvas.endTransformation();


		
		
		time += 1 / 60.0;
	}
	);

	return 0;
}
