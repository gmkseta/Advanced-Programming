#include "stdafx.h"
#include "GameBoard.h"
using namespace std;
using namespace glm;

//시간관련 변수
float lastTime = (float)timeGetTime();
float timeDelta = 0.0f;
DigitalCanvas2D my_canvas("SEONGJUNG's STRIKE 1945", 1024, 1000); 
GameBoard* Game = new GameBoard(&my_canvas);
float delta = 0.1f;
void Update()
{
	float currentTime = (float)timeGetTime();//현재 시간을 저장
	timeDelta = (currentTime - lastTime)*0.001f;
	//현재 시간과 마지막으로 저장햇던 시간의 차이로 델타 타임을 구함
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
