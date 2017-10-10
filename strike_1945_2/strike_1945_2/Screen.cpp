
#include "stdafx.h"
#include "Screen.h"

Screen::Screen(void)
{
}

Screen::~Screen(void)
{
}

void Screen::LoadBmpImg(char * filename, unsigned int MyImage)
{
	FILE* file;
	int padding = 0;
	unsigned char *temp;
	file = fopen(filename, "rb");
	if (file != NULL) // file opened
	{ 
		size_t x = fread(&bmpImage[MyImage].fh, sizeof(_BITMAPFILEHEADER), 1, file); //reading the FILEHEADER
		fread(&bmpImage[MyImage].ih, sizeof(_BITMAPINFOHEADER), 1, file);
		padding = (_PIXEL_ALIGN - ((bmpImage[MyImage].ih.biWidth * _BI_BITFIELDS) % _PIXEL_ALIGN)) % _PIXEL_ALIGN;
		if (bmpImage[MyImage].ih.biSizeImage == 0)    // 픽셀 데이터 크기가 0이라면
		{
			bmpImage[MyImage].ih.biSizeImage = 
				(bmpImage[MyImage].ih.biWidth * _BI_BITFIELDS + padding) * bmpImage[MyImage].ih.biHeight;
			// 이미지의 가로 크기 * 픽셀 크기에 남는 공간을 곱해주면 가로 한 줄 크기가 나옴
			// 여기에 이미지의 세로 크기를 곱해주면 픽셀 데이터의 크기를 구할 수 있음
		}
		bmpImage[MyImage].pixels = (_RGBTRIPLE*)malloc(
			bmpImage[MyImage].ih.biHeight*bmpImage[MyImage].ih.biWidth * sizeof(_RGBTRIPLE)
		);
		temp = (unsigned char*)malloc(bmpImage[MyImage].ih.biHeight*bmpImage[MyImage].ih.biWidth * sizeof(_RGBTRIPLE));   
		// 픽셀 데이터의 크기만큼 동적 할당
		fseek(file, bmpImage[MyImage].fh.bfOffBits, SEEK_SET); // 파일 포인터를 픽셀 데이터의 시작 위치로 이동
		if (fread(temp, sizeof(_RGBTRIPLE), bmpImage[MyImage].ih.biHeight*bmpImage[MyImage].ih.biWidth, file) < 1) 
			// 파일에서 픽셀 데이터 크기만큼 읽기 실패하면 닫음.
		{
			fclose(file);
			puts("픽셀데이터 읽기실패");
			return;
		}
		for (int y = bmpImage[MyImage].ih.biHeight - 1; y >= 0; y--) 
		{// 픽셀 데이터는 아래 위가 뒤집혀서 저장되므로 아래쪽부터 반복, 세로 크기만큼 반복
			for (int x = 0; x < bmpImage[MyImage].ih.biWidth; x++) // 가로 크기만큼 반복
			{
				// 일렬로 된 배열에 접근하기 위해 인덱스를 계산
				// (x * 픽셀 크기)는 픽셀의 가로 위치
				// (y * (세로 크기 * 픽셀 크기))는 픽셀이 몇 번째 줄인지 계산
				// 남는 공간 * y는 줄별로 누적된 남는 공간
				int index = (x * _BI_BITFIELDS) + (y * (bmpImage[MyImage].ih.biWidth* _BI_BITFIELDS)) + (padding * y);
				// 현재 픽셀의 주소를 RGBTRIPLE 포인터로 변환하여 RGBTRIPLE 포인터에 저장
				//bmpImage[MyImage]->pixels = (_RGBTRIPLE *)&temp[index]; //image= 픽셀 데이터 크기 동적 할당
				bmpImage[MyImage].pixels = (_RGBTRIPLE *)&temp[index];
			}

		}
	}
}


