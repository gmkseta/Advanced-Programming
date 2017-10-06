#pragma once

class Weapon:public GameObject
{
public:
	Weapon(void);
	~Weapon(void);

	void Init(float x, float y);
	BOOL Draw();
	BOOL Update(float delta);
	void Destroy();

	RECT_POINT* GetRect() { return &rectPos; }

	static unsigned int	MissleTextureObject;

private:
	RECT_POINT			rectPos;

};
