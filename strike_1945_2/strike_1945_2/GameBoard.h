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
enum IMG { _BACKGROUND, _USER, _MISSLE, _ENEMY };

#define MAXENEMY 20

class GameBoard : public Cscreen
{
public:
	GameBoard(DigitalCanvas2D* my_canvas);
	~GameBoard(void);

	HRESULT Init();
	HRESULT Draw();
	int ScreenUpdate(float delta);
	HRESULT Destroy();

	BOOL Collision(RECT_POINT *r1, RECT_POINT *r2);

private:
	User		*myUser;
	Map			*myMap;
	Weapon		myBullets[MAXSHOT];

	int			EnemyIdx;
	//CEnemy		m_cEnemy[MAXENEMY];

	//충돌처리
	std::vector<RECT_POINT*>			m_vMyMissleRect;
	std::vector<RECT_POINT*>			m_vEnermyRect;

	DigitalCanvas2D* _canvas=nullptr;

};
