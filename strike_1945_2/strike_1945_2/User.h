#pragma once
//-------------------------------------------------------------
// 정의 & 상수
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

	//포지션 x
	float GetPosX() { return _center.x; }
	//유저의 랙트 값
	RECT_POINT* GetRect() { return &rectPos; }

	// 유저의 범위를 검사
	BOOL	CheckPosition(float &x, float &y);
	// 유저의 위치를 셋팅
	void	SetPosition(float &x, float &y);

	//유저의 슈팅 번호
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
