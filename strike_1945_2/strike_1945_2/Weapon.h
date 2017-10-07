#pragma once

#define USER_WIDTH 
#define USER_HEIGHT
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
	


};
