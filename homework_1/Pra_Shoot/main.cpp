#include "DigitalCanvas2D.h"
#include "RGBColors.h"
#include <iostream>
#include <vector>
#include "gObject.h"
#include "Bitmap.h"

using namespace std;
using namespace glm;

DigitalCanvas2D my_canvas("This is my digital canvas!", 1024, 768); // Canvas : (-1.0, -1.0) x (1.0, 1.0)


int main(void)
{
	//Bitmap temp("image/User_Plane.bmp");
	float time = 0.0;
	GameObject c("image/User_Plane.bmp");
	c.init_image();
	//MyTank tank{ my_canvas ,init,init};

//	std::vector < MyWeapon*>bullets;
	
	
//	MyWeapon *laser = nullptr;
//	HumanCharacter character{ -1,0,my_canvas};

	my_canvas.show([&]
	{
		for (int i = 0; i < c.height-1; i++) {
			for (int j = 0; j < c.width; j++) {
				vec3 k = vec3(c.arr[i*c.width + j].rgbRed, c.arr[i*c.width + j].rgbGreen, c.arr[i*c.width + j].rgbBlue)/255.0f;

				my_canvas.drawDot(k, vec3(0.0 + (float)(j) / 400, 0.0 + (float)i / 400, 0.0));
			}
		}
			my_canvas.drawDot(RGBColors::red, vec3(0.0, 0.0, 0.0));
			
		/*
		// update

		// move tank
		if (my_canvas.isKeyPressed(GLFW_KEY_LEFT))	tank.center_.x -= 0.01;
		if (my_canvas.isKeyPressed(GLFW_KEY_RIGHT))	tank.center_.x += 0.01;
		if (my_canvas.isKeyPressed(GLFW_KEY_DOWN)) tank.center_.y -= 0.01;
		if (my_canvas.isKeyPressed(GLFW_KEY_UP)) tank.center_.y += 0.01;
		

		// shoot a cannon ball
		if (my_canvas.isKeyPressed(GLFW_KEY_SPACE))
		{
			int index = bullets.size();
			bullets.resize(bullets.size()+1);
			bullets[index] = new MyWeapon{ my_canvas };
			bullets[index]->center_ = tank.center_;
			bullets[index]->center_.x += 0.2;
			bullets[index]->center_.y += 0.1;
			bullets[index]->velocity_ = vec3(2.0, 0.0, 0.0);
		}
		for (int i = 0; i < bullets.size(); i++) {
			bullets[i]->update(1 / 60.0f);
		}

		if (my_canvas.isKeyPressed(GLFW_KEY_ENTER)) {
			if (laser != nullptr) delete laser;
			laser = new MyWeapon{ my_canvas };
			laser->center_ = vec3(character.x, character.y, 0);
			laser->center_.x += 0.2;
			laser->center_.y += 0.1;
			laser->velocity_ = vec3(2.0, 0.0, 0.0);			
		}
		if (laser != nullptr) {
			if (laser->l < 2)
				laser->update_l(1 / 60.0f);
			else
				laser->update(1 / 60.0f);
		}

		// rendering
		tank.draw();

		character.drawPeople(time);
		

		if (laser != nullptr) laser->draw_laser();

		for (int i = 0; i < bullets.size(); i++) {
			bullets[i]->draw();
		}

	//	if (bullets[bullets.size()]->center_.x > 1.0)
		//	delete[] bullets[bullets.size()];
		time += 1 / 60.0;
	*/	
	}
	);
	
	return 0;
}
