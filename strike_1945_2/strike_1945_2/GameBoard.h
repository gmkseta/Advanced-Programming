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
	void Init();//�ʱ�ȭ
	void Draw();//ȭ�� ���������� �׷���
	int ScreenUpdate(float delta);//������ ������Ʈ���� ������ ������Ʈ
	

	BOOL Collision(RECT_POINT *rectPos1, RECT_POINT *rectPos2);//�ε������� Ȯ�� 
	void DrawScore();//���ھ� �׷���
private:
	User		*myUser;//�������
	Map			*myMap;//���
	Weapon		myBullets[MAXSHOT];//���Ѿ�
	Enemy		myEnemy[MAXENEMY];//��
	EnemyAttack enemyBullets[MAX_E_BULLETS];//�� �Ѿ�	
	int			enemyNum;//�� ���� ������ ���� ����
	BOOL		gameOver;//���ӿ��� �ߴ��� ���ߴ��� Ȯ���ϴ� ����
	int			score;//����
	//���� Ȯ��
	std::vector<RECT_POINT*>	myBulletsRect;
	std::vector<Enemy*>			myEnemyRect;
	std::vector<RECT_POINT*>	enemyBulletsRect;

	//�׸��� ĵ���� �ּҰ� �޾ƿò�.
	DigitalCanvas2D* _canvas=nullptr;

};
