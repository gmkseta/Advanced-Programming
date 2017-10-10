#pragma once
#define PATTERN_MAX 3
class Enemy:public GameObject
{
public:
	static BOOL isMax;//MAX 갯수만큼 있는지 확인.
	BOOL flag;//부셔졌는지에 대한 플래그

public:
	Enemy();
	~Enemy();
	void Init(Bitmap bmpImage,Bitmap destoryImage, DigitalCanvas2D* my_canvas);
	void reRectPoint();
	BOOL Draw();
	BOOL Update(float delta);
	RECT_POINT* GetRect() { return &rectPos; }
	void setPattern(int a);
	int getPattern();
	void DestoryEffect(float delta);
	_RGBTRIPLE* Effect;

private:
	int				myPattern;
	float			myMovTime;
	float			effectTime;	
	int				effectPattern;
	int				effectWidth, effectHeight;
};
