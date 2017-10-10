#pragma once
//#include "scene.h"
//#include "Hero.h"
//#include "Stage.h"
//#include "Missle.h"
//#include "Enemy.h"

#include "Screen.h"
#include "User.h"
#include "Weapon.h"
#include "Map.h"
#include "Enemy.h"
#include "EnemyAttack.h"
enum IMG { _BACKGROUND, _USER, _BULLETS, _ENEMY ,_DESTORY,_E_BULLETS,_GAMEOVER,_NUMBER,_SCORE};
#define MAXENEMY 20
#define MAX_E_BULLETS 30
class GameBoard : public Screen
{
public:
	GameBoard(DigitalCanvas2D* my_canvas);
	~GameBoard(void);
	void Init();//초기화
	void Draw();//화면 내에있을시 그려줌
	int ScreenUpdate(float delta);//각각의 오브젝트들의 정보를 업데이트
	

	BOOL Collision(RECT_POINT *rectPos1, RECT_POINT *rectPos2);//부딪혔는지 확인 
	void DrawScore();//스코어 그려줌
private:
	User		*myUser;//내비행기
	Map			*myMap;//배경
	Weapon		myBullets[MAXSHOT];//내총알
	Enemy		myEnemy[MAXENEMY];//적
	EnemyAttack enemyBullets[MAX_E_BULLETS];//적 총알	
	int			enemyNum;//내 현재 적들의 수를 저장
	BOOL		gameOver;//게임오버 했는지 안했는지 확인하는 변수
	int			score;//점수
	//접촉 확인
	std::vector<RECT_POINT*>	myBulletsRect;
	std::vector<Enemy*>			myEnemyRect;
	std::vector<RECT_POINT*>	enemyBulletsRect;

	//그리는 캔버스 주소값 받아올꺼.
	DigitalCanvas2D* _canvas=nullptr;

};
