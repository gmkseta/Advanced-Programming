
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
		if (bmpImage[MyImage].ih.biSizeImage == 0)    // �ȼ� ������ ũ�Ⱑ 0�̶��
		{
			bmpImage[MyImage].ih.biSizeImage = 
				(bmpImage[MyImage].ih.biWidth * _BI_BITFIELDS + padding) * bmpImage[MyImage].ih.biHeight;
			// �̹����� ���� ũ�� * �ȼ� ũ�⿡ ���� ������ �����ָ� ���� �� �� ũ�Ⱑ ����
			// ���⿡ �̹����� ���� ũ�⸦ �����ָ� �ȼ� �������� ũ�⸦ ���� �� ����
		}
		bmpImage[MyImage].pixels = (_RGBTRIPLE*)malloc(
			bmpImage[MyImage].ih.biHeight*bmpImage[MyImage].ih.biWidth * sizeof(_RGBTRIPLE)
		);
		temp = (unsigned char*)malloc(bmpImage[MyImage].ih.biHeight*bmpImage[MyImage].ih.biWidth * sizeof(_RGBTRIPLE));   
		// �ȼ� �������� ũ�⸸ŭ ���� �Ҵ�
		fseek(file, bmpImage[MyImage].fh.bfOffBits, SEEK_SET); // ���� �����͸� �ȼ� �������� ���� ��ġ�� �̵�
		if (fread(temp, sizeof(_RGBTRIPLE), bmpImage[MyImage].ih.biHeight*bmpImage[MyImage].ih.biWidth, file) < 1) 
			// ���Ͽ��� �ȼ� ������ ũ�⸸ŭ �б� �����ϸ� ����.
		{
			fclose(file);
			puts("�ȼ������� �б����");
			return;
		}
		for (int y = bmpImage[MyImage].ih.biHeight - 1; y >= 0; y--) 
		{// �ȼ� �����ʹ� �Ʒ� ���� �������� ����ǹǷ� �Ʒ��ʺ��� �ݺ�, ���� ũ�⸸ŭ �ݺ�
			for (int x = 0; x < bmpImage[MyImage].ih.biWidth; x++) // ���� ũ�⸸ŭ �ݺ�
			{
				// �Ϸķ� �� �迭�� �����ϱ� ���� �ε����� ���
				// (x * �ȼ� ũ��)�� �ȼ��� ���� ��ġ
				// (y * (���� ũ�� * �ȼ� ũ��))�� �ȼ��� �� ��° ������ ���
				// ���� ���� * y�� �ٺ��� ������ ���� ����
				int index = (x * _BI_BITFIELDS) + (y * (bmpImage[MyImage].ih.biWidth* _BI_BITFIELDS)) + (padding * y);
				// ���� �ȼ��� �ּҸ� RGBTRIPLE �����ͷ� ��ȯ�Ͽ� RGBTRIPLE �����Ϳ� ����
				//bmpImage[MyImage]->pixels = (_RGBTRIPLE *)&temp[index]; //image= �ȼ� ������ ũ�� ���� �Ҵ�
				bmpImage[MyImage].pixels = (_RGBTRIPLE *)&temp[index];
			}

		}
	}
}


