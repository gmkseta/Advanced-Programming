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

			if (this->ih.biSizeImage == 0)    // 픽셀 데이터 크기가 0이라면-------------------------------------------------------------------------------왜 0이면??
			{
				this->ih.biSizeImage = (this->ih.biWidth * BI_BITFIELDS + padding) * this->ih.biHeight;
				// 이미지의 가로 크기 * 픽셀 크기에 남는 공간을 곱해주면 가로 한 줄 크기가 나옴
				// 여기에 이미지의 세로 크기를 곱해주면 픽셀 데이터의 크기를 구할 수 있음
			}

	
			this->pixels = (_RGBTRIPLE*)malloc(this->ih.biHeight*this->ih.biWidth * sizeof(_RGBTRIPLE));
			temp = (unsigned char*)malloc(this->ih.biHeight*this->ih.biWidth*sizeof(_RGBTRIPLE));    // 픽셀 데이터의 크기만큼 동적 할당

			fseek(file, this->fh.bfOffBits, SEEK_SET); // 파일 포인터를 픽셀 데이터의 시작 위치로 이동
			if (fread(temp, sizeof(_RGBTRIPLE), this->ih.biHeight*this->ih.biWidth, file) < 1) // 파일에서 픽셀 데이터 크기만큼 읽기 실패하면 닫음.
			{

				fclose(file);

				puts("픽셀데이터 읽기실패");
				return;
			}
			
			for (int y = this->ih.biHeight - 1; y >= 0; y--) // 픽셀 데이터는 아래 위가 뒤집혀서 저장되므로 아래쪽부터 반복, 세로 크기만큼 반복
			{
				for (int x = 0; x < this->ih.biWidth; x++) // 가로 크기만큼 반복
				{
					// 일렬로 된 배열에 접근하기 위해 인덱스를 계산
					// (x * 픽셀 크기)는 픽셀의 가로 위치
					// (y * (세로 크기 * 픽셀 크기))는 픽셀이 몇 번째 줄인지 계산
					// 남는 공간 * y는 줄별로 누적된 남는 공간
					int index = (x * BI_BITFIELDS) + (y * (this->ih.biWidth* BI_BITFIELDS)) + (padding * y);

					// 현재 픽셀의 주소를 RGBTRIPLE 포인터로 변환하여 RGBTRIPLE 포인터에 저장
					//this->pixels = (_RGBTRIPLE *)&temp[index]; //image= 픽셀 데이터 크기 동적 할당
					this->pixels = (_RGBTRIPLE *)&temp[index];
				}
			}

			

			fclose(file);
		}
	}
	//~Bitmap();


private:

};

#endif