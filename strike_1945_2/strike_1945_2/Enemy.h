#pragma once
#define PATTERN_MAX 3
class Enemy:public GameObject
{
public:
	Enemy(void);
	~Enemy(void);

	static BOOL isMax;

	void Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas);
	void reRectPoint();
	BOOL Draw();
	BOOL Update(float delta);
	void Destroy();
	RECT_POINT* GetRect() { return &rectPos; }
	void setPattern(int a);
	int getPattern();

private:
	int				myPattern;

	float			myMovTime;

	float			m_fAnimation;
	float			m_fShotTime;
	
};
