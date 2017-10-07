#pragma once

class Enemy:public GameObject
{
public:
	Enemy(void);
	~Enemy(void);

	void inIt(Bitmap bmpImage, DigitalCanvas2D* my_canvas);
	void reRectPoint(float x, int pattern);
	BOOL Draw();
	BOOL Update(float delta);
	void Destroy();

	RECT_POINT* GetRect() { return &rectPos; }

	static unsigned int	EnemyTextureObject;

private:
	RECT_POINT		rectPos;
	int				m_Pattern;
	float			m_fAnimation;
	float			m_fShotTime;

	float			x, y;

};
