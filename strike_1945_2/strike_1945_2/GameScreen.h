#pragma once
//#include "scene.h"
//#include "Hero.h"
//#include "Stage.h"
//#include "Missle.h"
//#include "Enemy.h"

#include "Screen.h"
#include "User.h"

enum IMG { _BACKGROUND, _USER, _MISSLE, _ENEMY };

#define MAXENEMY 20

class CGameScreen : public Cscreen
{
public:
	CGameScreen(DigitalCanvas2D* my_canvas);
	~CGameScreen(void);

	HRESULT Init();
	HRESULT Draw();
	int ScreenUpdate(float delta);
	HRESULT Destroy();

	BOOL Collision(RECT_POINT *r1, RECT_POINT *r2);

private:
	User		*my_user;
	//CStage		*m_pStage;
	//CMissle		m_cMissle[MAXSHOT];

	int			EnemyIdx;
	//CEnemy		m_cEnemy[MAXENEMY];

	//충돌처리
	std::vector<RECT_POINT*>			m_vMyMissleRect;
	std::vector<RECT_POINT*>			m_vEnermyRect;


};
