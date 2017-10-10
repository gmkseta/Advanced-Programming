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
	LoadBmpImg("image/bullet.bmp", _BULLETS);
	LoadBmpImg("image/Enemy1.bmp", _ENEMY);
	LoadBmpImg("image/Destory_Enemy.bmp", _DESTORY);
	LoadBmpImg("image/EnemyBullet.bmp", _E_BULLETS);
	LoadBmpImg("image/gameOver.bmp", _GAMEOVER);
	LoadBmpImg("image/Number.bmp", _NUMBER);
	LoadBmpImg("image/Score.bmp", _SCORE);
	
	myUser->Init(bmpImage[_USER],_canvas);
	myMap->Init(bmpImage[_BACKGROUND],_canvas);

	for (int i = 0; i != MAXSHOT; i++)
		myBullets[i].Init(bmpImage[_BULLETS],_canvas);

	for (int i = 0; i != MAXENEMY; i++)
		myEnemy[i].Init(bmpImage[_ENEMY],bmpImage[_DESTORY], _canvas);

	for (int i = 0; i != MAX_E_BULLETS; i++)
		enemyBullets[i].Init(bmpImage[_E_BULLETS], _canvas);


	enemyNum = 0;

	gameOver = FALSE;

	score = 0;

	
}

void GameBoard::Draw()
{
	glLoadIdentity(); //��Ʈ���� ���� �ʱ�ȭ

	myMap->Draw();

	//���� �׸���
	myUser->Draw();


	//---------------���Ѿ� , ���Ѿ� draw �ϰ� rect vector�� �ֱ�-------------------
	for (int i = 0; i != MAXSHOT; i++)
	{
		if (myBullets[i].Draw()) myBulletsRect.push_back(myBullets[i].GetRect());

	}
	for (int i = 0; i != MAX_E_BULLETS; i++)
	{
		if (enemyBullets[i].Draw())enemyBulletsRect.push_back(enemyBullets[i].GetRect());
	}

	Enemy::isMax = TRUE;

	//-----------------------------------�������----------------------------------
	for (int i = 0; i <MAXENEMY; i++)
	{
		if (myEnemy[i].Draw()) 
			myEnemyRect.push_back(&myEnemy[i]);
		else 
		{
			myEnemy[i].setPattern(0);
			Enemy::isMax = FALSE;
		}
	}

	//SCORE ���

	DrawScore();


	//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�gameOver�äѤѤѤѤѤѤѤѤѤѤ�
	if (_canvas->isKeyPressed(GLFW_KEY_Y))
		gameOver = FALSE;
	if (gameOver == TRUE && _canvas->isKeyPressed(GLFW_KEY_N))
		exit(0);
	if (gameOver == TRUE) 
	{
		GameObject::drawLetter(*_canvas, bmpImage[_GAMEOVER]);
	}

	//------------------------- ���Ѿ˰� ������ ���� ------------------------------
	for (int i = 0; i < (int)myBulletsRect.size(); i++)
	{
		for (int j = 0; j < (int)myEnemyRect.size(); j++)
		{
			if (Collision(myBulletsRect[i], &myEnemyRect[j]->rectPos))
			{
				myBulletsRect[i]->top = myBulletsRect[i]->bottom = 1.5f;
				myEnemyRect[j]->flag = TRUE;
				myEnemyRect[j]->setPattern(0);
				score += 10;
				
			} 
		}
	}
	//----------------------�� �Ѿ˰� ������ ����--------------------------------
	for (int i = 0; i < (int)enemyBulletsRect.size(); i++)
	{
		if (Collision(enemyBulletsRect[i], &myUser->rectPos))
		{
			enemyBulletsRect[i]->top = enemyBulletsRect[i]->bottom= 
			enemyBulletsRect[i]->left= enemyBulletsRect[i]->right = -1.5f;
			gameOver = TRUE;
		}
	}

	myBulletsRect.clear();
	myEnemyRect.clear();
	enemyBulletsRect.clear();

	
	
	return ;

}


int GameBoard::ScreenUpdate(float delta)
{
	//���ӿ����� ������Ʈ ó�� ���ϰ� �ٸ�����
	if (gameOver == TRUE)
	{
		return 0;
	}
	//-------------------------�����̽��� ������ �߻�-----------------------
	static float BulletsDelay = 0;

	if (_canvas->isKeyPressed(GLFW_KEY_SPACE))
	{
		if (BulletsDelay <= 0)
		{
			int ShotNumber = myUser->GetBulletNum();
			myBullets[ShotNumber].reRectPoint(myUser->GetPosX() + (float) myUser->width / (SCREEN_RATE*2), myUser->GetRect()->top);
			BulletsDelay = 0.06f;
		}
	}
	if (BulletsDelay > 0) BulletsDelay -= delta;
	


	//---------------------------������� ��ġ����---------------------------
	static float EnemyDelay = 0;

	if (EnemyDelay <= 0)
	{
		if (myEnemy[enemyNum].checkArea()==FALSE) {
			myEnemy[enemyNum].reRectPoint();
			enemyNum = ++enemyNum % MAXENEMY;
			EnemyDelay = 0.3f;
		}
		else {
			enemyNum = ++enemyNum % MAXENEMY;
		}
	}
	if (EnemyDelay > 0) EnemyDelay -= delta + 3 * delta*(float)score/(10000.0f+(float)score);//(float)score/10000.0f;



	//------------------------------�� �Ѿ�--------------------------------
	static float EnemyBulletsDelay = 0;
	static int EnemyShotNum = 0;
	int eNum = rand()%MAXENEMY;
	
	if (EnemyBulletsDelay <= 0)
	{
		if(myEnemy[eNum].getPattern()!=0) 
		{
			enemyBullets[EnemyShotNum].reRectPoint(myEnemy[eNum].rectPos.left, myEnemy[eNum].rectPos.bottom);
			EnemyBulletsDelay = 0.5f;
			EnemyShotNum = ++EnemyShotNum%MAX_E_BULLETS;
		}
	}
	if (EnemyBulletsDelay > 0) EnemyBulletsDelay -= delta + 3 * delta*(float)score / (10000.0f + (float)score);
	
	//Map Update
	myMap->Update(delta);
	//User Update
	myUser->Update(delta);
	//User Bullets Update
	for (int i = 0; i != MAXSHOT; i++)
		myBullets[i].Update(delta);

	//Enemy Update
	for (int i = 0; i <MAXENEMY; i++)
		myEnemy[i].Update(delta);

	////Enemy Bullets update
	for (int i = 0; i < MAX_E_BULLETS; i++)
		enemyBullets[i].Update(delta);

	return 0;
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



void GameBoard::DrawScore()
{
	int temp = score;

	GameObject::drawLetter(*_canvas, bmpImage[_SCORE], -0.9f, 0.95f);

	float x = -0.7f;

	while (temp >= 0)
	{	
		if (temp == 0)
		{
			//GameObject::drawNumber(*_canvas, bmpImage[_NUMBER], x, 0.93f, 0, 5);
			return;
		}
		else
			GameObject::drawNumber(*_canvas, bmpImage[_NUMBER],x , 0.93f,temp%10,5);
			
		temp /= 10;
		x -= 0.018f;
	}
}