#pragma once
\
class EnemyAttack :public GameObject
{
public:
	EnemyAttack();
	~EnemyAttack();

	void Init(Bitmap bmpImage, DigitalCanvas2D* my_canvas);
	void reRectPoint(float x, float y);
	BOOL Draw();
	BOOL Update(float delta);

	RECT_POINT* GetRect() { return &rectPos; }





};
