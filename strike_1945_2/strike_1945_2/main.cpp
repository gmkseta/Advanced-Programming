#include "stdafx.h"
#include "GameBoard.h"
using namespace std;
using namespace glm;

//�ð����� ����
float lastTime = (float)timeGetTime();
float timeDelta = 0.0f;
DigitalCanvas2D my_canvas("SEONGJUNG's STRIKE 1945", 1024, 1000); 
GameBoard* Game = new GameBoard(&my_canvas);
float delta = 0.1f;
void Update()
{
	float currentTime = (float)timeGetTime();//���� �ð��� ����
	timeDelta = (currentTime - lastTime)*0.001f;
	//���� �ð��� ���������� �����޴� �ð��� ���̷� ��Ÿ Ÿ���� ����
	Game->ScreenUpdate(timeDelta);	
	lastTime = currentTime;
}
int main(void)
{
	Game->Init();
	my_canvas.show([&]
	{
		Update();
		Game->Draw();
	});

	return 0;
}
