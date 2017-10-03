#include "Bitmap.h"
#include <iostream>
void main()
{
	char* hi = "lena.bmp";

	Bitmap temp(hi);
	for (int i = 0; i < temp.ih.biHeight; i++) {
		for (int j = 0; j < temp.ih.biWidth; j++) {
			std::cout << temp.pixels[j + i*temp.ih.biWidth].rgbBlue;
		}
		//std::cout << "\n" << std::endl;
	}
}

