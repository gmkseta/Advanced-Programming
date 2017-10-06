#pragma once
#define QUALITY 8
class Map:GameObject
{
public:
	Map(void);
	~Map(void);
	DigitalCanvas2D* _canvas;

	void Init(Bitmap bmpImage,DigitalCanvas2D *my_canvas);
	void Draw();
	float Update(float delta);
	void Destroy();

private:
	float Position;


};
