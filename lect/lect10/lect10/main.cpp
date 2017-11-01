#include "DigitalCanvas2D.h"
#include "RGBColors.h"
#include <iostream>

using namespace std;
using namespace glm;

DigitalCanvas2D my_canvas("This is my digital canvas!", 1024, 768); // Canvas : (-1.0, -1.0) x (1.0, 1.0)

int main(void)
{
	float time = 0.0;

	my_canvas.show([&]
	{
		// update

		// move tank
		if (my_canvas.isKeyPressed(GLFW_KEY_SPACE)) {}

		my_canvas.beginTransformation();
		my_canvas.translate(0.0f, 0.0f);
		my_canvas.drawFilledCircle(RGBColors::red, 0.10, 16);
		my_canvas.endTransformation();

		my_canvas.beginTransformation();
		my_canvas.translate(0.0f, -0.9);
		my_canvas.drawFilledBox(RGBColors::green, 10, 1.0);
		my_canvas.endTransformation();

		time += 1 / 60.0;
	}
	);

	return 0;
}
