#include "stdafx.h"
#include "GameScreen.h"
using namespace std;
using namespace glm;

DigitalCanvas2D my_canvas("This is my digital canvas!", 1024, 1000); // Canvas : (-1.0, -1.0) x (1.0, 1.0)
CGameScreen* Game = new CGameScreen(&my_canvas);
float delta = 0.1f;
int main(void)
{

	//Bitmap temp("image/User_Plane.bmp");
	//float time = 0.0;
//	PlayerPlane c("image/User_Plane.bmp");
//	GameObject background("image/background.bmp", -1.05f, -1.0f);
	//c.init_image();
	//MyTank tank{ my_canvas ,init,init};

	//	std::vector < MyWeapon*>bullets;
	//PlayerBullet* basicBullet = nullptr;


	//	MyWeapon *laser = nullptr;
	//	HumanCharacter character{ -1,0,my_canvas};
	Game->Init();

	my_canvas.show([&]
	{

		Game->ScreenUpdate(delta);
		Game->Draw();
		
		/*
		if (my_canvas.isKeyPressed(GLFW_KEY_LEFT))	c._center.x -= 0.01f;

		if (my_canvas.isKeyPressed(GLFW_KEY_RIGHT))	c._center.x += 0.01f;

		if (my_canvas.isKeyPressed(GLFW_KEY_DOWN)) c._center.y -= 0.01f;

		if (my_canvas.isKeyPressed(GLFW_KEY_UP)) c._center.y += 0.01f;

		if (my_canvas.isKeyPressed(GLFW_KEY_SPACE))
		{
			if (basicBullet != nullptr)delete basicBullet;
			basicBullet = new PlayerBullet("image/bullet.bmp");

			basicBullet->shoot(c._center);
		}

		background.drawObjectLowQuality(my_canvas, 12);
		if (basicBullet != nullptr) {
			basicBullet->drawObject(my_canvas);

			basicBullet->drawObject(my_canvas, -0.07f);
			basicBullet->update(1 / 60.f);
		}

		c.drawObject(my_canvas);*/
		/*
		// update



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
		//time += 1 / 60.0;
	}
	);

	return 0;
}
