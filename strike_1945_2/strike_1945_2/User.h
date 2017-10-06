#pragma once
//-------------------------------------------------------------
// ���� & ���
//-------------------------------------------------------------
#define SPEED 20
#define MAXSHOT 30


class User: public GameObject
{
public:
	User(void);
	User(DigitalCanvas2D* my_canvas);
	~User(void);
	DigitalCanvas2D* _canvas=nullptr;
	void Init(Bitmap bmpImage);
	void UI();
	void Draw();
	void Update(float delta);
	void Destroy();

	//������ x
	float GetPosX() { return _center.x; }
	//������ ��Ʈ ��
	RECT_POINT* GetRect() { return &m_rPos; }

	// ������ ������ �˻�
	BOOL	CheckPosition(float &x, float &y);
	// ������ ��ġ�� ����
	void	SetPosition(float &x, float &y);

	//������ ���� ��ȣ
	int GetShotNumber() {
		m_iShotNumber = ++m_iShotNumber % MAXSHOT;
		return m_iShotNumber;
	}

private:
	RECT_POINT		m_rPos;
	float			m_fAnimation;
	float			m_fAnimationMaxPoint;
	int				m_iShotNumber;
	

};
