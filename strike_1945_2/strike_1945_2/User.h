#pragma once
//-------------------------------------------------------------
// ���� & ���
//-------------------------------------------------------------
#define SPEED 2.0f
#define MAXSHOT 15


class User: public GameObject
{
public:
	//User(DigitalCanvas2D* my_canvas);
	User(void);
	~User(void);
	


	void Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas);//, DigitalCanvas2D* my_canvas);
	void Draw();
	void Update(float delta);
	void Destroy();

	//������ x
	float GetPosX() { return _center.x; }
	//������ ��Ʈ ��
	RECT_POINT* GetRect() { return &rectPos; }

	// ������ ������ �˻�
	BOOL	CheckPosition(float &x, float &y);
	// ������ ��ġ�� ����
	void	SetPosition(float &x, float &y);

	//������ ���� ��ȣ
	int GetBulletNum() {
		myBulletNum = ++myBulletNum % MAXSHOT;
		return myBulletNum;
	}

private:
	RECT_POINT		rectPos;
	float			m_fAnimation;
	float			m_fAnimationMaxPoint;
	int				myBulletNum;
	

};
