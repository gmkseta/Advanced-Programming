#include "stdafx.h"
#include "GameBoard.h"
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
	Game->Init();

	my_canvas.show([&]
	{

		Update();
		Game->Draw();
		
	}
	);

	return 0;
}
