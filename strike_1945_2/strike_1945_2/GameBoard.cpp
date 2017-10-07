#include "stdafx.h"
#include "GameBoard.h"
BOOL Enemy::isMax = FALSE;

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
	LoadBmpImg("image/Enemy1.bmp", _ENEMY);
	LoadBmpImg("image/Destory_Enemy.bmp", _DESTORY);

	
	myUser->Init(bmpImage[_USER],_canvas);
	myMap->Init(bmpImage[_BACKGROUND],_canvas);

	for (int i = 0; i != MAXSHOT; i++) {
		myBullets[i].Init(bmpImage[_MISSLE],_canvas);
	}

	for (int i = 0; i != MAXENEMY; i++) {
		myEnemy[i].Init(bmpImage[_ENEMY],bmpImage[_DESTORY], _canvas);
	}

	EnemyNum = 0;
	
}

void GameBoard::Draw()
{
	//glMatrixMode(GL_MODELVIEW); //��Ʈ���� ������ ���ڴ�.
	glLoadIdentity(); //��Ʈ���� ���� �ʱ�ȭ

	myMap->Draw();

	//���� �׸���
	myUser->Draw();


	////�Ѿ� �׸���
	for (int i = 0; i != MAXSHOT; i++)
	{
		if (myBullets[i].Draw())
			m_vMyMissleRect.push_back(myBullets[i].GetRect());

	}

	Enemy::isMax = TRUE;
	////�������
	for (int i = 0; i <MAXENEMY; i++)
	{
		if (myEnemy[i].Draw()) {
			m_vEnermyRect.push_back(&myEnemy[i]);
		}
		else {
			myEnemy[i].setPattern(0);
			Enemy::isMax = FALSE;
		}
	}


	/////////////////   �浹ó�� ///////////////////////////
	for (int i = 0; i < (int)m_vMyMissleRect.size(); i++)
	{
		for (int j = 0; j < (int)m_vEnermyRect.size(); j++)
		{
			if (Collision(m_vMyMissleRect[i], &m_vEnermyRect[j]->rectPos))
			{
				m_vMyMissleRect[i]->top = m_vMyMissleRect[i]->bottom = 1.5f;
				m_vEnermyRect[j]->flag = TRUE;
				//m_vEnermyRect[j]->rectPos.top = m_vEnermyRect[j]->rectPos.bottom = 1.5f;
			} 
		}
	}

	m_vMyMissleRect.clear();
	m_vEnermyRect.clear();
	///////////////////////////////////////////////////////////


}


int GameBoard::ScreenUpdate(float delta)
{
	//////////////////// �̻��� ���� ���� //////////////////////
	static float MissleDelay = 0;


	if (_canvas->isKeyPressed(GLFW_KEY_SPACE))
	{
		if (MissleDelay <= 0)
		{
			int ShotNumber = myUser->GetBulletNum();
			myBullets[ShotNumber].reRectPoint(myUser->GetPosX() + (float) myUser->width / 1024, myUser->GetRect()->top);
			MissleDelay = 0.06f;
		}
	}

	if (MissleDelay > 0) MissleDelay -= delta;
	///////////////////////////////////////////////////////////

	////////////////////// ������� ���� ���� //////////////////////
	//static int storyIdx = 0;
	static float EnemyDelay = 0;

	if (EnemyDelay <= 0)
	{
		if (Enemy::isMax != TRUE) {
			myEnemy[EnemyNum].reRectPoint();
			EnemyNum = ++EnemyNum % MAXENEMY;
			EnemyDelay = 0.3f;
		}
		else { EnemyDelay = 3.00f; }
		
	}

	if (EnemyDelay > 0) EnemyDelay -= delta;

	////////////////////////////////////////////////////////////////


	////�� Update
	myMap->Update(delta);

	//���� Update
	myUser->Update(delta);

	////�̻��� Update
	for (int i = 0; i != MAXSHOT; i++)
		myBullets[i].Update(delta);

	////������� Update
	for (int i = 0; i <MAXENEMY; i++)
		myEnemy[i].Update(delta);

	return 0;
}

void GameBoard::Destroy()
{
}
//
BOOL GameBoard::Collision(RECT_POINT *rectPos1, RECT_POINT *rectPos2)
{
	if (rectPos1->left > rectPos2->right) return FALSE;
	if (rectPos1->top < rectPos2->bottom) return FALSE;
	if (rectPos1->right < rectPos2->left) return FALSE;
	if (rectPos1->bottom > rectPos2->top) return FALSE;

    return TRUE;
}

void GameBoard::DestoryEffect(float delta,RECT_POINT r)
{
	timeGetTime();

}