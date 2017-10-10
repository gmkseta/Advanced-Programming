#pragma once
//-------------------------------------------------------------
// ���� & ���
//-------------------------------------------------------------
#define SPEED 1.0f
#define MAXSHOT 15


class User: public GameObject
{
public:
	//User(DigitalCanvas2D* my_canvas);
	User();
	~User();

	void Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas);//, DigitalCanvas2D* my_canvas);
	void Draw();
	void Update(float delta);

	//���ʳ� ������ ��ȯ
	float GetPosX() { return rectPos.left; }
	//������ ��Ʈ ��
	RECT_POINT* GetRect() { return &rectPos; }

	// ������ ��ġ �˻�
	BOOL	CheckPosition(float &x, float &y);
	// ������ ��ġ�� ����
	void	SetPosition(float &x, float &y);

	//������ ���� ��ȣ
	int GetBulletNum() {
		myBulletNum = ++myBulletNum % MAXSHOT;
		return myBulletNum;
	}
private:
	int				myBulletNum;
	float			movX, movY;

};
