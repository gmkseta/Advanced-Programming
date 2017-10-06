#include "stdafx.h"
#include "GameScreen.h"
#include <Windows.h>
#include <mmsystem.h>
using namespace std;
using namespace glm;

//시간관련 변수
float lastTime = (float)timeGetTime();
float timeDelta = 0.0f;

//프레임 제어
int timeCount = 0;
DWORD _ctime;
float FPS = 0.0f;

//프레임표시
int FrameCnt = 0;
float timeElapsed = 0.0f;

DigitalCanvas2D my_canvas("This is my digital canvas!", 1024, 1000); // Canvas : (-1.0, -1.0) x (1.0, 1.0)
CGameScreen* Game = new CGameScreen(&my_canvas);
float delta = 0.1f;


void Update()
{
	float currentTime = (float)timeGetTime();
	timeDelta = (currentTime - lastTime)*0.001f;

	if (timeCount == 0)
	{
		_ctime = timeGetTime();
		timeCount++;
	}

	//현재시간과 처음받아온 시간을 비교하여.
	//60프레임보다 크면 랜더하고 타임을 다시 받아옴
	if (_ctime + (1000 / 60) <= timeGetTime())
	{
		FrameCnt++;
		timeCount = 0;
		
	}
	Game->ScreenUpdate(timeDelta);

	timeElapsed += timeDelta;
	if (timeElapsed >= 1.0f)
	{
		FPS = (float)FrameCnt / timeElapsed;
		timeElapsed = 0.0f;
		FrameCnt = 0;
	}
	lastTime = currentTime;
	//canvas Weapon 에서 init 약간 다른거 같음
	//printf("%2lf ", timeDelta);

}
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

		Update();
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
