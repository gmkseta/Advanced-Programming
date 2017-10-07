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
enum IMG { _BACKGROUND, _USER, _MISSLE, _ENEMY ,_DESTORY};

#define MAXENEMY 20

class GameBoard : public Cscreen
{
public:
	GameBoard(DigitalCanvas2D* my_canvas);
	~GameBoard(void);

	void Init();
	void Draw();
	int ScreenUpdate(float delta);
	void Destroy();

	BOOL Collision(RECT_POINT *r1, RECT_POINT *r2);
	void DestoryEffect(float delta);
private:
	User		*myUser;//내비행기
	Map			*myMap;//배경
	Weapon		myBullets[MAXSHOT];//내총알
	Enemy		myEnemy[MAXENEMY];//적

	int			EnemyNum;//현재 적들의 수

	//접촉 확인
	std::vector<RECT_POINT*>			m_vMyMissleRect;
	std::vector<RECT_POINT*>			m_vEnermyRect;

	//그리는 캔버스 주소값 받아올꺼.
	DigitalCanvas2D* _canvas=nullptr;

};
