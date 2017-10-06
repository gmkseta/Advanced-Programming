#pragma once

class Weapon:public GameObject
{
public:
	Weapon();
	~Weapon(void);

	void Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas);
	void reRectPoint(float x, float y);
	BOOL Draw();
	BOOL Update(float delta);
	void Destroy();

	RECT_POINT* GetRect() { return &rectPos; }

	static unsigned int	MissleTextureObject;
	DigitalCanvas2D* _canvas = nullptr;

private:
	RECT_POINT			rectPos;

};
