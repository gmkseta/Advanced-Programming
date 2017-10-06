#include "stdafx.h"
#include "GameScreen.h"

CGameScreen::CGameScreen(DigitalCanvas2D* my_canvas)
{
	my_user = new User(my_canvas);//m_pHero = new CHero;
	//m_pStage = new CStage;
}

CGameScreen::~CGameScreen(void)
{
	//SAFE_DELETE(m_pHero);
	//SAFE_DELETE(m_pStage);
}

HRESULT CGameScreen::Init()
{

	
	LoadBmpImg("image/_stage.bmp", _BACKGROUND);
	LoadBmpImg("image/User_Plane.bmp", _USER);
	LoadBmpImg("image/missle.bmp", _MISSLE);
	LoadBmpImg("image/MiniEnemy2.bmp", _ENEMY);

	
	my_user->Init(bmpImage[_USER]);
	//m_pStage->Init(TexContainer[STAGE1]);
	//CMissle::MissleTextureObject = TexContainer[MISSLE];
	//CEnemy::EnemyTextureObject = TexContainer[ENEMY];

	return S_OK;
}

HRESULT CGameScreen::Draw()
{
	glMatrixMode(GL_MODELVIEW); //��Ʈ���� ������ ���ڴ�.
	glLoadIdentity(); //��Ʈ���� ���� �ʱ�ȭ

					  //�� ������
	//m_pStage->Render();

	//���� ������
	my_user->Draw();


	////�̻��� ������
	//for (int i = 0; i != MAXSHOT; i++)
	//{
	//	if (m_cMissle[i].Draw())
	//		m_vMyMissleRect.push_back(m_cMissle[i].GetRect());

	//}

	////�������
	//for (int i = 0; i <MAXENEMY; i++)
	//{
	//	if (m_cEnemy[i].Draw())
	//		m_vEnermyRect.push_back(m_cEnemy[i].GetRect());
	//}


	/////////////////   �浹ó�� ///////////////////////////
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


	return S_OK;
}


int CGameScreen::ScreenUpdate(float delta)
{
	//////////////////// �̻��� ���� ���� //////////////////////
	//static float MissleDelay = 0;

	//BOOL Missle = ((GetAsyncKeyState('X') & 0x8000) == 0x8000);

	//if (Missle)
	//{
	//	if (MissleDelay <= 0)
	//	{
	//		int ShotNumber = m_pHero->GetShotNumber();
	//		m_cMissle[ShotNumber].Init(m_pHero->GetPosX() + 3.25f, m_pHero->GetRect()->top);
	//		MissleDelay = 0.10f;
	//	}
	//}

	//if (MissleDelay > 0) MissleDelay -= delta;
	///////////////////////////////////////////////////////////

	////////////////////// ������� ���� ���� //////////////////////
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


	////�� Update
	//m_pStage->Update(delta);

	//���� Update
	my_user->Update(delta);

	////�̻��� Update
	//for (int i = 0; i != MAXSHOT; i++)
	//	m_cMissle[i].Update(delta);

	////������� Update
	//for (int i = 0; i <MAXENEMY; i++)
	//	m_cEnemy[i].Update(delta);

	return 0;
}

HRESULT CGameScreen::Destroy()
{

	return S_OK;
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