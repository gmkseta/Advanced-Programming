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
	Ball my_ball2{ 1.0f,0.0f,0.1f,0.0f };
	my_ball2.setVelocity(-1.0f, 3.0f);
	my_ball.setVelocity(1.0f, 3.0f);


	my_canvas.show([&]
	{

		//collision check
		if (my_ball.center_y - my_ball.radius <= -0.4 && my_ball.velocity_y<0.0f)
		{   //center_y - r 은 원의 맨아래 좌표고
			//바닥 그려진 곳의 맨위 좌표랑 비교하는건데
			//바닥 좌표는 중심 -0.9 에서 저거 높이가 1.0이니까  0.5만큼 위라서 -0.4임
			//collision response
			my_ball.velocity_y = -my_ball.velocity_y*coef_res;
		}

		if (my_ball2.center_y - my_ball2.radius <= -0.4 && my_ball2.velocity_y<0.0f)
			my_ball2.velocity_y = -my_ball2.velocity_y*coef_res;
		
		//collision check ball1 and ball2
		const vec2 b1_pos(my_ball.center_x, my_ball.center_y);
		const vec2 b2_pos(my_ball2.center_x, my_ball2.center_y);
		const float dist = glm::length(b1_pos-b2_pos);
		const vec2 b1_vel(my_ball.velocity_x, my_ball.velocity_y);
		const vec2 b2_vel(my_ball2.velocity_x, my_ball2.velocity_y);



		const vec2 vel_rel1 = b1_vel - b2_vel;
		const vec2 dir_12 = glm::normalize(b2_pos - b1_pos);
		const float rel1 = glm::dot(vel_rel1, dir_12);

		//const float dx = my_ball.center_x - my_ball2.center_x;
		//const float dy = my_ball.center_y - my_ball2.center_y;
		//const float dist = sqrt(dx*dx + dy*dy);

		if (dist <= my_ball.radius + my_ball2.radius)//&&rel1<=0.0)
		{
			const vec2 vel_rel1_after_col = -vel_rel1*coef_res;
			const vec2 vel1_after_col = vel_rel1_after_col + b1_vel;
			my_ball.velocity_x = vel1_after_col.x;
			my_ball.velocity_y = vel1_after_col.y;

		}

		const vec2 vel_rel2 = b2_vel - b1_vel;
		const vec2 dir_21 = glm::normalize(b1_pos - b2_pos);
		const float rel2 = glm::dot(vel_rel2, dir_21);

		//const float dx = my_ball.center_x - my_ball2.center_x;
		//const float dy = my_ball.center_y - my_ball2.center_y;
		//const float dist = sqrt(dx*dx + dy*dy);

		if (dist <= my_ball.radius + my_ball2.radius)//&&rel2<=0.0)
		{
			const vec2 vel_rel2_after_col = -vel_rel2*coef_res;
			const vec2 vel2_after_col = vel_rel2_after_col + b2_vel;
			my_ball2.velocity_x = vel2_after_col.x;
			my_ball2.velocity_y = vel2_after_col.y;

		}

		
		// update
		//1st order Euler Intergration
		my_ball.updateEuler(ga_x, ga_y, dt);
		my_ball2.updateEuler(ga_x, ga_y, dt);
		// move tank
		if (my_canvas.isKeyPressed(GLFW_KEY_SPACE)) {}



		my_ball2.draw();
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
