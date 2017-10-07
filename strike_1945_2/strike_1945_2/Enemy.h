#pragma once
#define PATTERN_MAX 3
class Enemy:public GameObject
{
public:

	static BOOL isMax;

	BOOL flag;//부셔졌는지에 대한 플래그

public:

	Enemy(void);
	~Enemy(void);
	void Init(Bitmap bmpImage,Bitmap destoryImage, DigitalCanvas2D* my_canvas);
	void reRectPoint();
	BOOL Draw();
	BOOL Update(float delta);
	void Destroy();
	RECT_POINT* GetRect() { return &rectPos; }
	void setPattern(int a);
	int getPattern();
	void DestoryEffect(float delta);

	_RGBTRIPLE* Effect;



private:

	int				myPattern;

	float			myMovTime;

	float			effectTime;

	float			m_fShotTime;
	
	int				effectPattern;
	int				effectWidth, effectHeight;
};
