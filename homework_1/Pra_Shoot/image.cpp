#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#define UPUP 1000





#include <stdio.h>    // fopen, fread, fseek, fprintf, fclose �Լ��� ����� ��� ����
#include <stdlib.h>   // malloc, free �Լ��� ����� ��� ����
#pragma pack(push, 1)                // ����ü�� 1����Ʈ ũ��� ����



typedef struct _BITMAPFILEHEADER     // BMP ��Ʈ�� ���� ��� ����ü
{
	unsigned short bfType;           // BMP ���� ���� �ѹ�
	unsigned int   bfSize;           // ���� ũ��
	unsigned short bfReserved1;      // ����
	unsigned short bfReserved2;      // ����
	unsigned int   bfOffBits;        // ��Ʈ�� �������� ���� ��ġ
} BITMAPFILEHEADER;

typedef struct _BITMAPINFOHEADER     // BMP ��Ʈ�� ���� ��� ����ü(DIB ���)
{
	unsigned int   biSize;           // ���� ����ü�� ũ��
	int            biWidth;          // ��Ʈ�� �̹����� ���� ũ��
	int            biHeight;         // ��Ʈ�� �̹����� ���� ũ��
	unsigned short biPlanes;         // ����ϴ� �������� ��
	unsigned short biBitCount;       // �ȼ� �ϳ��� ǥ���ϴ� ��Ʈ ��
	unsigned int   biCompression;    // ���� ���
	unsigned int   biSizeImage;      // ��Ʈ�� �̹����� �ȼ� ������ ũ��
	int            biXPelsPerMeter;  // �׸��� ���� �ػ�(���ʹ� �ȼ�)
	int            biYPelsPerMeter;  // �׸��� ���� �ػ�(���ʹ� �ȼ�)
	unsigned int   biClrUsed;        // ���� ���̺��� ���� ���Ǵ� ���� ��
	unsigned int   biClrImportant;   // ��Ʈ���� ǥ���ϱ� ���� �ʿ��� ���� �ε��� ��

} BITMAPINFOHEADER;


typedef struct _RGBTRIPLE            // 24��Ʈ ��Ʈ�� �̹����� �ȼ� ����ü
{
	unsigned char rgbtBlue;          // �Ķ�
	unsigned char rgbtGreen;         // �ʷ�
	unsigned char rgbtRed;           // ����
}RGBTRIPLE;

typedef struct _Header
{
	BITMAPFILEHEADER fileHeader;    // ��Ʈ�� ���� ��� ����ü ����
	BITMAPINFOHEADER infoHeader;    // ��Ʈ�� ���� ��� ����ü ����
	int width;
	int height;
	int padding;
	int size;
	unsigned char *image;           // �ȼ� ������ ������
	unsigned char **twoD;

}File_info;




#pragma pack(pop)
#define PIXEL_SIZE   3    // �ȼ� �� ���� ũ�� 3����Ʈ(24��Ʈ)
#define PIXEL_ALIGN  4    // �ȼ� �������� ���� �� �ٿ��� ���� ����(padding)�� ���ϱ� ���� ���İ��Դϴ�(��Ʈ�� ������ �ȼ� �������� ���� �� ���� ������ �� 4�� ��� ũ��� �����մϴ�).
// cpu�� ó���ϱ⿡ 4����Ʈ�� ���ؼ� 4����� ���� �������ְ� ���� ����(������)�� 0���� ä��� ��.

unsigned char ReadBmp(File_info *info);

unsigned char WriteBmp(File_info *info);

void Matrix_1_to_2(File_info *info);

void Matrix_2_to_1(File_info *info);

void init_output(File_info *change, File_info *info, int height, int width);

void inter(File_info *ori, File_info *edit);

void main()
{
	File_info ming, change;

	if (ReadBmp(&ming) == 1)
	{
		printf("�б� �Ϸ�");
	}

	init_output(&change, &ming, 1024, 1024);

	inter(&ming, &change);

	//Matrix_1_to_2(&ming);

	//Matrix_2_to_1(&ming);

}



unsigned char ReadBmp(File_info *info)
{


	FILE *fpBmp = fopen("lena.bmp", "rb");    // ��Ʈ�� ������ ���̳ʸ� ���('b')�� ���� 
	if (fpBmp == NULL) {// ���� ���⿡ �����ϸ�

		puts("���Ͽ������");
		return 0;         // ���α׷� ����
	}

	if (fread(&info->fileHeader, sizeof(BITMAPFILEHEADER), 1, fpBmp) < 1) // ��Ʈ�� ���� ��� �б�
	{
		fclose(fpBmp);

		puts("���� ��� �б����");
		return 0;
	}

	if (info->fileHeader.bfType != 'MB') // ���� �ѹ��� MB�� �´��� Ȯ�� (2����Ʈ ũ���� BM�� ��Ʋ ��������� �о����Ƿ� MB�� ��)
	{
		fclose(fpBmp);

		puts("�����ѹ��� mb�� �");
		return 0; // ���� �ѹ��� ���� ������ ���α׷� ����
	}

	if (fread(&info->infoHeader, sizeof(BITMAPINFOHEADER), 1, fpBmp) < 1) // ��Ʈ�� ���� ��� �б�
	{
		fclose(fpBmp);

		puts("��Ʈ�� ���� ��� �б����");
		return 0;
	}


	if (info->infoHeader.biBitCount != 24) // 24��Ʈ ��Ʈ���� �ƴϸ� ���α׷� ����
	{
		fclose(fpBmp);
		puts("24��Ʈ ��Ʈ���� �ƴ�");
		return 0;
	}

	info->padding = (PIXEL_ALIGN - ((info->infoHeader.biWidth * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN; //�ȼ� �������� ���� �� �ٿ��� ���� ����(padding)�� ���ϱ����� ��
	info->height = info->infoHeader.biHeight;
	info->width = info->infoHeader.biWidth;
	info->size = info->infoHeader.biSizeImage;


	if (info->infoHeader.biSizeImage == 0)    // �ȼ� ������ ũ�Ⱑ 0�̶��-------------------------------------------------------------------------------�� 0�̸�??
	{
		info->infoHeader.biSizeImage = (info->infoHeader.biWidth * PIXEL_SIZE + info->padding) * info->infoHeader.biHeight;
		// �̹����� ���� ũ�� * �ȼ� ũ�⿡ ���� ������ �����ָ� ���� �� �� ũ�Ⱑ ����
		// ���⿡ �̹����� ���� ũ�⸦ �����ָ� �ȼ� �������� ũ�⸦ ���� �� ����
	}


	info->image = (unsigned char*)malloc(info->size);    // �ȼ� �������� ũ�⸸ŭ ���� �Ҵ�
	fseek(fpBmp, info->fileHeader.bfOffBits, SEEK_SET); // ���� �����͸� �ȼ� �������� ���� ��ġ�� �̵�
	if (fread(info->image, info->size, 1, fpBmp) < 1) // ���Ͽ��� �ȼ� ������ ũ�⸸ŭ �б� �����ϸ� ����.
	{

		fclose(fpBmp);

		puts("�ȼ������� �б����");
		return 0;
	}
	// 2�� �����Ҵ� for������ؼ� 
	info->twoD = (unsigned char**)malloc(sizeof(unsigned char*)*info->height);
	for (int i = 0; i < info->height; i++)
	{
		info->twoD[i] = (unsigned char*)malloc(sizeof(unsigned char*)*info->width);
	}

	fclose(fpBmp);    // ��Ʈ�� ���� �ݱ�

	return 1;


}


unsigned char WriteBmp(File_info *info)
{

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


	FILE *outfile2 = fopen("out2345.bmp", "wb"); // ����� ���� ���� (���� ������ �ڵ����� ���� ����)

	fwrite(&info->fileHeader, sizeof(char), sizeof(BITMAPFILEHEADER), outfile2); // ������� 
	fwrite(&info->infoHeader, sizeof(char), sizeof(BITMAPINFOHEADER), outfile2); // ������� 

	fseek(outfile2, info->fileHeader.bfOffBits, SEEK_SET); //bfOffBits �� ������ �����ϴ� ���̹Ƿ� ���� �����͸� �� ������������ �Ű���

	fwrite(info->image, sizeof(unsigned char), info->infoHeader.biSizeImage, outfile2); // ���������Է�
																						// ���� ���뿡 ����� �޸�, ������ �ϳ��� ũ��, �� ������ ����, ������ ������ ���� ������
																						//free(info->image);      // �ȼ� �����͸� ������ ���� �޸� ����
																						/////free

	return 0;
}



void Matrix_1_to_2(File_info *info)
{

	for (int y = info->height - 1; y >= 0; y--) // �ȼ� �����ʹ� �Ʒ� ���� �������� ����ǹǷ� �Ʒ��ʺ��� �ݺ�, ���� ũ�⸸ŭ �ݺ�
	{
		for (int x = 0; x < info->width; x++) // ���� ũ�⸸ŭ �ݺ�
		{
			int index = (x * PIXEL_SIZE) + (y * (info->width* PIXEL_SIZE)) + (info->padding * y);
			info->twoD[x][y] = info->image[index];
		}
	}


}

void Matrix_2_to_1(File_info *info)
{
	for (int y = info->height - 1; y >= 0; y--) // �ȼ� �����ʹ� �Ʒ� ���� �������� ����ǹǷ� �Ʒ��ʺ��� �ݺ�, ���� ũ�⸸ŭ �ݺ�
	{
		for (int x = 0; x < (info->width)*PIXEL_SIZE; x++) // ���� ũ�⸸ŭ �ݺ�
		{

			int index = (x * PIXEL_SIZE) + (y * (info->width* PIXEL_SIZE)) + (info->padding * y);

			info->image[index] = info->twoD[y][x];

		}
	}
}

void init_output(File_info *change, File_info *info, int height, int width) // 1024*1024
{

	change->fileHeader.bfType = info->fileHeader.bfType;
	change->fileHeader.bfSize = height*width * 3 + 138;
	change->fileHeader.bfReserved1 = info->fileHeader.bfReserved1;
	change->fileHeader.bfReserved2 = info->fileHeader.bfReserved2;
	change->fileHeader.bfOffBits = info->fileHeader.bfOffBits;

	change->infoHeader.biSize = info->infoHeader.biSize;
	change->infoHeader.biWidth = width;
	change->infoHeader.biHeight = height;
	change->infoHeader.biPlanes = 1;   // ����ϴ� �������� ���� �׻� 1�̴�.
	change->infoHeader.biBitCount = 24;   // 3byte=24bit
	change->infoHeader.biCompression = 0;
	change->infoHeader.biSizeImage = width*height * 3;
	change->infoHeader.biXPelsPerMeter = 2834; //��
	change->infoHeader.biYPelsPerMeter = 2834; //��
	change->infoHeader.biClrUsed = 0;
	change->infoHeader.biClrImportant = 0;


	change->width = width;
	change->height = height;
	change->padding = (PIXEL_ALIGN - ((width * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN;
	change->size = change->infoHeader.biSizeImage;

	change->image = (unsigned char*)malloc(change->size);    // �ȼ� �������� ũ�⸸ŭ ���� �Ҵ�

	change->twoD = (unsigned char**)malloc(sizeof(unsigned char*)*change->height);
	for (int i = 0; i < change->height; i++)
	{
		change->twoD[i] = (unsigned char*)malloc(sizeof(unsigned char*)*change->width);
	}



}




void inter(File_info *ori, File_info *edit) {

	Matrix_1_to_2(ori);




}