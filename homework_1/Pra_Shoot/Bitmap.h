#pragma once
//
//  Bitmap.h
//
#ifndef LaserMaze_Bitmap_h
#define LaserMaze_Bitmap_h

#pragma pack(2) // Add this

#include <iostream>
#include <stdio.h>

typedef struct
{
	unsigned short bfType;
	unsigned int   bfSize;
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned int   bfOffBits;
} _BITMAPFILEHEADER;

#pragma pack() // and this
#  define BF_TYPE 0x4D42             /* "MB" */

typedef struct                       /**** BMP file info structure ****/
{
	unsigned int   biSize;           /* Size of info header */
	int            biWidth;          /* Width of image */
	int            biHeight;         /* Height of image */
	unsigned short biPlanes;         /* Number of color planes */
	unsigned short biBitCount;       /* Number of bits per pixel */
	unsigned int   biCompression;    /* Type of compression to use */
	unsigned int   biSizeImage;      /* Size of image data */
	int            biXPelsPerMeter;  /* X pixels per meter */
	int            biYPelsPerMeter;  /* Y pixels per meter */
	unsigned int   biClrUsed;        /* Number of colors used */
	unsigned int   biClrImportant;   /* Number of important colors */
} _BITMAPINFOHEADER;

/*
* Constants for the biCompression field...
*/

#  define BI_RGB       0             /* No compression - straight BGR data */
#  define BI_RLE8      1             /* 8-bit run-length compression */
#  define BI_RLE4      2             /* 4-bit run-length compression */
#  define BI_BITFIELDS 3             /* RGB bitmap with RGB masks */
#  define PIXEL_ALIGN 4
typedef struct                       /**** Colormap entry structure ****/
{
	unsigned char  rgbBlue;          /* Blue value */
	unsigned char  rgbGreen;         /* Green value */
	unsigned char  rgbRed;           /* Red value */
} _RGBTRIPLE;


class Bitmap {
public:
	_RGBTRIPLE* pixels;
	_BITMAPFILEHEADER fh;
	_BITMAPINFOHEADER ih;
	Bitmap(const char* filename) {
		FILE* file;
		int padding = 0;
		unsigned char *temp;
		file = fopen(filename, "rb");

		std::cout << sizeof(_BITMAPFILEHEADER) << std::endl;

		if (file != NULL) { // file opened
			size_t x = fread(&fh, sizeof(_BITMAPFILEHEADER), 1, file); //reading the FILEHEADER
			fread(&this->ih, sizeof(_BITMAPINFOHEADER), 1, file);
			padding = (PIXEL_ALIGN - ((this->ih.biWidth * BI_BITFIELDS) % PIXEL_ALIGN)) % PIXEL_ALIGN;

			if (this->ih.biSizeImage == 0)    // �ȼ� ������ ũ�Ⱑ 0�̶��-------------------------------------------------------------------------------�� 0�̸�??
			{
				this->ih.biSizeImage = (this->ih.biWidth * BI_BITFIELDS + padding) * this->ih.biHeight;
				// �̹����� ���� ũ�� * �ȼ� ũ�⿡ ���� ������ �����ָ� ���� �� �� ũ�Ⱑ ����
				// ���⿡ �̹����� ���� ũ�⸦ �����ָ� �ȼ� �������� ũ�⸦ ���� �� ����
			}

	

			temp = (unsigned char*)malloc(this->ih.biSizeImage);    // �ȼ� �������� ũ�⸸ŭ ���� �Ҵ�

			fseek(file, this->fh.bfOffBits, SEEK_SET); // ���� �����͸� �ȼ� �������� ���� ��ġ�� �̵�
			if (fread(temp, this->ih.biSizeImage,1, file) < 1) // ���Ͽ��� �ȼ� ������ ũ�⸸ŭ �б� �����ϸ� ����.
			{

				fclose(file);

				puts("�ȼ������� �б����");
				return;
			}
			// 2�� �����Ҵ� for������ؼ� 

			/*
			for (int y = info->height - 1; y >= 0; y--) // �ȼ� �����ʹ� �Ʒ� ���� �������� ����ǹǷ� �Ʒ��ʺ��� �ݺ�, ���� ũ�⸸ŭ �ݺ�
			{
				for (int x = 0; x < info->width; x++) // ���� ũ�⸸ŭ �ݺ�
				{
					// �Ϸķ� �� �迭�� �����ϱ� ���� �ε����� ���
					// (x * �ȼ� ũ��)�� �ȼ��� ���� ��ġ
					// (y * (���� ũ�� * �ȼ� ũ��))�� �ȼ��� �� ��° ������ ���
					// ���� ���� * y�� �ٺ��� ������ ���� ����
					int index = (x * PIXEL_SIZE) + (y * (info->width* PIXEL_SIZE)) + (info->padding * y);

					// ���� �ȼ��� �ּҸ� RGBTRIPLE �����ͷ� ��ȯ�Ͽ� RGBTRIPLE �����Ϳ� ����
					RGBTRIPLE *pixel = (RGBTRIPLE *)&info->image[index]; //image= �ȼ� ������ ũ�� ���� �Ҵ�
					unsigned char gray = info->image[index];

				}
			}

			*/

			fclose(file);
		}
	}
	//~Bitmap();


private:

};

#endif