#pragma once
#define PATTERN_MAX 3
class Enemy:public GameObject
{
public:
	static BOOL isMax;//MAX ������ŭ �ִ��� Ȯ��.
	BOOL flag;//�μ��������� ���� �÷���

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
