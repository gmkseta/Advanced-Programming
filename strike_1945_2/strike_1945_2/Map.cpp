#include "StdAfx.h"
#include "Map.h"

Map::Map(void)
{
}

Map::~Map(void)
{
	Destroy();
}

void Map::Init(Bitmap bmpImage, DigitalCanvas2D *my_canvas)
{
	_canvas = my_canvas;
	
	arr = bmpImage.pixels;
	width = bmpImage.ih.biWidth;
	height = bmpImage.ih.biHeight;
	rectPos.left = -1.0f;
	rectPos.bottom = -1.0f;
	calcRightTop();

	Position = 0;


}
void Map::Draw()
{
	drawMapLowQuality(*_canvas, QUALITY, Position);
}
float Map::Update(float delta)
{

	if (Position >= (float)height)	Position = 0.0f;
	else					Position += (float)QUALITY;//* delta;

	return Position;
}
void Map::Destroy()
{

}

