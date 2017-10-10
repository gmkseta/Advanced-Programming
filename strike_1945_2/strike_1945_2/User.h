#pragma once
//-------------------------------------------------------------
// 정의 & 상수
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

	//왼쪽끝 포지션 반환
	float GetPosX() { return rectPos.left; }
	//유저의 랙트 값
	RECT_POINT* GetRect() { return &rectPos; }

	// 유저의 위치 검사
	BOOL	CheckPosition(float &x, float &y);
	// 유저의 위치를 셋팅
	void	SetPosition(float &x, float &y);

	//유저의 슈팅 번호
	int GetBulletNum() {
		myBulletNum = ++myBulletNum % MAXSHOT;
		return myBulletNum;
	}
private:
	int				myBulletNum;
	float			movX, movY;

};
