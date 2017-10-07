#include "stdafx.h"
#include "GameBoard.h"
using namespace std;
using namespace glm;

//�ð����� ����
float lastTime = (float)timeGetTime();
float timeDelta = 0.0f;
//������ ����
int timeCount = 0;
DWORD _ctime;
float FPS = 0.0f;

//������ǥ��
int FrameCnt = 0;
float timeElapsed = 0.0f;

DigitalCanvas2D my_canvas("This is my digital canvas!", 1024, 1000); // Canvas : (-1.0, -1.0) x (1.0, 1.0)
GameBoard* Game = new GameBoard(&my_canvas);
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

	//����ð��� ó���޾ƿ� �ð��� ���Ͽ�.
	//60�����Ӻ��� ũ�� �����ϰ� Ÿ���� �ٽ� �޾ƿ�
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
	//canvas Weapon ���� init �ణ �ٸ��� ����
	//printf("%2lf ", timeDelta);

}
int main(void)
{
	Game->Init();

	my_canvas.show([&]
	{

		Update();
		Game->Draw();
		
	}
	);

	return 0;
}
