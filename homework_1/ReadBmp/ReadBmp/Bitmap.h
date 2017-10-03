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
} BITMAPFILEHEADER;

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
} BITMAPINFOHEADER;

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
} RGBQUAD;


class Bitmap {
public:
	RGBQUAD* pixels;
	BITMAPFILEHEADER fh;
	BITMAPINFOHEADER ih;
	Bitmap(const char* filename) {
		FILE* file;
		int padding = 0;

		file = fopen(filename, "rb");

		std::cout << sizeof(BITMAPFILEHEADER) << std::endl;

		if (file != NULL) { // file opened
			BITMAPFILEHEADER h;
			size_t x = fread(&h, sizeof(BITMAPFILEHEADER), 1, file); //reading the FILEHEADER
			std::cout << x;
			fread(&this->ih, sizeof(BITMAPINFOHEADER), 1, file);
			padding = (PIXEL_ALIGN - ((this->ih.biWidth * BI_BITFIELDS) % PIXEL_ALIGN)) % PIXEL_ALIGN;

			if (this->ih.biSizeImage==0)    // �ȼ� ������ ũ�Ⱑ 0�̶��-------------------------------------------------------------------------------�� 0�̸�??
			{
				this->ih.biSizeImage = (this->ih.biWidth * BI_BITFIELDS + padding) * this->ih.biHeight;
				// �̹����� ���� ũ�� * �ȼ� ũ�⿡ ���� ������ �����ָ� ���� �� �� ũ�Ⱑ ����
				// ���⿡ �̹����� ���� ũ�⸦ �����ָ� �ȼ� �������� ũ�⸦ ���� �� ����
			}


			this->pixels = (RGBQUAD*)malloc(sizeof(RGBQUAD)*this->ih.biHeight*this->ih.biWidth);    // �ȼ� �������� ũ�⸸ŭ ���� �Ҵ�

			fseek(file, this->fh.bfOffBits, SEEK_SET); // ���� �����͸� �ȼ� �������� ���� ��ġ�� �̵�
			if (fread(this->pixels, sizeof(RGBQUAD), this->ih.biHeight*this->ih.biWidth, file) < 1) // ���Ͽ��� �ȼ� ������ ũ�⸸ŭ �б� �����ϸ� ����.
			{

				fclose(file);

				puts("�ȼ������� �б����");
				return ;
			}
			// 2�� �����Ҵ� for������ؼ� 
		

			fclose(file);
		}
	}
	//~Bitmap();


private:

};

#endif