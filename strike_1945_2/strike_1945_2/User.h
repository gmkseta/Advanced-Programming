#pragma once
//-------------------------------------------------------------
// 정의 & 상수
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

	//포지션 x
	float GetPosX() { return _center.x; }
	//유저의 랙트 값
	RECT_POINT* GetRect() { return &m_rPos; }

	// 유저의 범위를 검사
	BOOL	CheckPosition(float &x, float &y);
	// 유저의 위치를 셋팅
	void	SetPosition(float &x, float &y);

	//유저의 슈팅 번호
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
