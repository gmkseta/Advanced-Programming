#include "stdafx.h"
#include "GameBoard.h"

GameBoard::GameBoard(DigitalCanvas2D* my_canvas)
{
	myUser = new User();
	myMap = new Map();
	_canvas = my_canvas;

}

GameBoard::~GameBoard(void)
{
	delete(myUser);
	delete(myMap);
}

void GameBoard::Init()
{

	
	LoadBmpImg("image/BigMap.bmp", _BACKGROUND);
	LoadBmpImg("image/User_Plane.bmp", _USER);
	LoadBmpImg("image/bullet.bmp", _MISSLE);
	LoadBmpImg("image/MiniEnemy2.bmp", _ENEMY);

	
	myUser->Init(bmpImage[_USER],_canvas);
	myMap->Init(bmpImage[_BACKGROUND],_canvas);

	for (int i = 0; i != MAXSHOT; i++) {
		myBullets[i].Init(bmpImage[_MISSLE],_canvas);
	}

	//CEnemy::EnemyTextureObject = TexContainer[ENEMY];

}

void GameBoard::Draw()
{
	glMatrixMode(GL_MODELVIEW); //매트릭스 연산을 쓰겠다.
	glLoadIdentity(); //매트릭스 연산 초기화

	//맵 랜더링
	myMap->Draw();

	//유저 랜더링
	myUser->Draw();


	////미사일 랜더링
	for (int i = 0; i != MAXSHOT; i++)
	{
		if (myBullets[i].Draw())
			m_vMyMissleRect.push_back(myBullets[i].GetRect());

	}

	////적비행기
	//for (int i = 0; i <MAXENEMY; i++)
	//{
	//	if (m_cEnemy[i].Draw())
	//		m_vEnermyRect.push_back(m_cEnemy[i].GetRect());
	//}


	/////////////////   충돌처리 ///////////////////////////
	//for (int i = 0; i < (int)m_vMyMissleRect.size(); i++)
	//{
	//	for (int j = 0; j < (int)m_vEnermyRect.size(); j++)
	//	{
	//		if (Collision(m_vMyMissleRect[i], m_vEnermyRect[j]))
	//		{
	//			m_vMyMissleRect[i]->top = m_vMyMissleRect[i]->bottom = 100.0f;
	//			m_vEnermyRect[j]->top = m_vEnermyRect[j]->bottom = 100.0f;
	//		}
	//	}
	//}

	//m_vMyMissleRect.clear();
	//m_vEnermyRect.clear();
	///////////////////////////////////////////////////////////


}


int GameBoard::ScreenUpdate(float delta)
{
	//////////////////// 미사일 관련 동작 //////////////////////
	static float MissleDelay = 0;


	if (_canvas->isKeyPressed(GLFW_KEY_SPACE))
	{
		if (MissleDelay <= 0)
		{
			int ShotNumber = myUser->GetBulletNum();
			myBullets[ShotNumber].reRectPoint(myUser->GetPosX() + myUser->width/1024, myUser->GetRect()->top);
			MissleDelay = 0.10f;
		}
	}

	if (MissleDelay > 0) MissleDelay -= delta;
	///////////////////////////////////////////////////////////

	////////////////////// 적비행기 관련 동작 //////////////////////
	//static int storyIdx = 0;
	//static float EnemyDelay = 0;

	//if (EnemyDelay <= 0)
	//{
	//	if (m_vStory[storyIdx] && m_vStory.size() != 0)
	//	{
	//		m_cEnemy[EnemyIdx].Init(m_vStory[storyIdx]->x, m_vStory[storyIdx]->patten);
	//		EnemyIdx = ++EnemyIdx % MAXENEMY;
	//		EnemyDelay = 0.50f;
	//	}
	//	else
	//	{
	//		EnemyDelay = 3.00f;
	//	}

	//	storyIdx = ++storyIdx % (int)m_vStory.size();
	//}

	//if (EnemyDelay > 0) EnemyDelay -= delta;

	////////////////////////////////////////////////////////////////


	////맵 Update
	myMap->Update(delta);

	//유저 Update
	myUser->Update(delta);

	////미사일 Update
	for (int i = 0; i != MAXSHOT; i++)
		myBullets[i].Update(delta);

	////적비행기 Update
	//for (int i = 0; i <MAXENEMY; i++)
	//	m_cEnemy[i].Update(delta);

	return 0;
}

void GameBoard::Destroy()
{
}
//
//BOOL CGameScreen::Collision(FRECT *r1, FRECT*r2)
//{
//	if (r1->left > r2->right) return FALSE;
//	if (r1->top < r2->bottom) return FALSE;
//	if (r1->right < r2->left) return FALSE;
//	if (r1->bottom > r2->top) return FALSE;
//
//	return TRUE;
//}