#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#define UPUP 1000





#include <stdio.h>    // fopen, fread, fseek, fprintf, fclose 함수가 선언된 헤더 파일
#include <stdlib.h>   // malloc, free 함수가 선언된 헤더 파일
#pragma pack(push, 1)                // 구조체를 1바이트 크기로 정렬



typedef struct _BITMAPFILEHEADER     // BMP 비트맵 파일 헤더 구조체
{
	unsigned short bfType;           // BMP 파일 매직 넘버
	unsigned int   bfSize;           // 파일 크기
	unsigned short bfReserved1;      // 예약
	unsigned short bfReserved2;      // 예약
	unsigned int   bfOffBits;        // 비트맵 데이터의 시작 위치
} BITMAPFILEHEADER;

typedef struct _BITMAPINFOHEADER     // BMP 비트맵 정보 헤더 구조체(DIB 헤더)
{
	unsigned int   biSize;           // 현재 구조체의 크기
	int            biWidth;          // 비트맵 이미지의 가로 크기
	int            biHeight;         // 비트맵 이미지의 세로 크기
	unsigned short biPlanes;         // 사용하는 색상판의 수
	unsigned short biBitCount;       // 픽셀 하나를 표현하는 비트 수
	unsigned int   biCompression;    // 압축 방식
	unsigned int   biSizeImage;      // 비트맵 이미지의 픽셀 데이터 크기
	int            biXPelsPerMeter;  // 그림의 가로 해상도(미터당 픽셀)
	int            biYPelsPerMeter;  // 그림의 세로 해상도(미터당 픽셀)
	unsigned int   biClrUsed;        // 색상 테이블에서 실제 사용되는 색상 수
	unsigned int   biClrImportant;   // 비트맵을 표현하기 위해 필요한 색상 인덱스 수

} BITMAPINFOHEADER;


typedef struct _RGBTRIPLE            // 24비트 비트맵 이미지의 픽셀 구조체
{
	unsigned char rgbtBlue;          // 파랑
	unsigned char rgbtGreen;         // 초록
	unsigned char rgbtRed;           // 빨강
}RGBTRIPLE;

typedef struct _Header
{
	BITMAPFILEHEADER fileHeader;    // 비트맵 파일 헤더 구조체 변수
	BITMAPINFOHEADER infoHeader;    // 비트맵 정보 헤더 구조체 변수
	int width;
	int height;
	int padding;
	int size;
	unsigned char *image;           // 픽셀 데이터 포인터
	unsigned char **twoD;

}File_info;




#pragma pack(pop)
#define PIXEL_SIZE   3    // 픽셀 한 개의 크기 3바이트(24비트)
#define PIXEL_ALIGN  4    // 픽셀 데이터의 가로 한 줄에서 남는 공간(padding)을 구하기 위한 정렬값입니다(비트맵 포맷은 픽셀 데이터의 가로 한 줄을 저장할 때 4의 배수 크기로 저장합니다).
// cpu가 처리하기에 4바이트가 편해서 4배수로 값을 지정해주고 남은 공간(나머지)은 0으로 채우는 것.

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
		printf("읽기 완료");
	}

	init_output(&change, &ming, 1024, 1024);

	inter(&ming, &change);

	//Matrix_1_to_2(&ming);

	//Matrix_2_to_1(&ming);

}



unsigned char ReadBmp(File_info *info)
{


	FILE *fpBmp = fopen("lena.bmp", "rb");    // 비트맵 파일을 바이너리 모드('b')로 열기 
	if (fpBmp == NULL) {// 파일 열기에 실패하면

		puts("파일열기실패");
		return 0;         // 프로그램 종료
	}

	if (fread(&info->fileHeader, sizeof(BITMAPFILEHEADER), 1, fpBmp) < 1) // 비트맵 파일 헤더 읽기
	{
		fclose(fpBmp);

		puts("파일 헤더 읽기오류");
		return 0;
	}

	if (info->fileHeader.bfType != 'MB') // 매직 넘버가 MB가 맞는지 확인 (2바이트 크기의 BM을 리틀 엔디언으로 읽었으므로 MB가 됨)
	{
		fclose(fpBmp);

		puts("매직넘버가 mbㄱ 어남");
		return 0; // 매직 넘버가 맞지 않으면 프로그램 종료
	}

	if (fread(&info->infoHeader, sizeof(BITMAPINFOHEADER), 1, fpBmp) < 1) // 비트맵 정보 헤더 읽기
	{
		fclose(fpBmp);

		puts("비트맵 정보 헤더 읽기오류");
		return 0;
	}


	if (info->infoHeader.biBitCount != 24) // 24비트 비트맵이 아니면 프로그램 종료
	{
		fclose(fpBmp);
		puts("24비트 비트맵이 아님");
		return 0;
	}

	info->padding = (PIXEL_ALIGN - ((info->infoHeader.biWidth * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN; //픽셀 데이터의 가로 한 줄에서 남는 공간(padding)을 구하기위한 식
	info->height = info->infoHeader.biHeight;
	info->width = info->infoHeader.biWidth;
	info->size = info->infoHeader.biSizeImage;


	if (info->infoHeader.biSizeImage == 0)    // 픽셀 데이터 크기가 0이라면-------------------------------------------------------------------------------왜 0이면??
	{
		info->infoHeader.biSizeImage = (info->infoHeader.biWidth * PIXEL_SIZE + info->padding) * info->infoHeader.biHeight;
		// 이미지의 가로 크기 * 픽셀 크기에 남는 공간을 곱해주면 가로 한 줄 크기가 나옴
		// 여기에 이미지의 세로 크기를 곱해주면 픽셀 데이터의 크기를 구할 수 있음
	}


	info->image = (unsigned char*)malloc(info->size);    // 픽셀 데이터의 크기만큼 동적 할당
	fseek(fpBmp, info->fileHeader.bfOffBits, SEEK_SET); // 파일 포인터를 픽셀 데이터의 시작 위치로 이동
	if (fread(info->image, info->size, 1, fpBmp) < 1) // 파일에서 픽셀 데이터 크기만큼 읽기 실패하면 닫음.
	{

		fclose(fpBmp);

		puts("픽셀데이터 읽기실패");
		return 0;
	}
	// 2차 동적할당 for문사용해서 
	info->twoD = (unsigned char**)malloc(sizeof(unsigned char*)*info->height);
	for (int i = 0; i < info->height; i++)
	{
		info->twoD[i] = (unsigned char*)malloc(sizeof(unsigned char*)*info->width);
	}

	fclose(fpBmp);    // 비트맵 파일 닫기

	return 1;


}


unsigned char WriteBmp(File_info *info)
{

	for (int y = info->height - 1; y >= 0; y--) // 픽셀 데이터는 아래 위가 뒤집혀서 저장되므로 아래쪽부터 반복, 세로 크기만큼 반복
	{
		for (int x = 0; x < info->width; x++) // 가로 크기만큼 반복
		{
			// 일렬로 된 배열에 접근하기 위해 인덱스를 계산
			// (x * 픽셀 크기)는 픽셀의 가로 위치
			// (y * (세로 크기 * 픽셀 크기))는 픽셀이 몇 번째 줄인지 계산
			// 남는 공간 * y는 줄별로 누적된 남는 공간
			int index = (x * PIXEL_SIZE) + (y * (info->width* PIXEL_SIZE)) + (info->padding * y);

			// 현재 픽셀의 주소를 RGBTRIPLE 포인터로 변환하여 RGBTRIPLE 포인터에 저장
			RGBTRIPLE *pixel = (RGBTRIPLE *)&info->image[index]; //image= 픽셀 데이터 크기 동적 할당
			unsigned char gray = info->image[index];

		}
	}


	FILE *outfile2 = fopen("out2345.bmp", "wb"); // 출력할 파일 오픈 (파일 없으면 자동으로 파일 생성)

	fwrite(&info->fileHeader, sizeof(char), sizeof(BITMAPFILEHEADER), outfile2); // 파일헤드 
	fwrite(&info->infoHeader, sizeof(char), sizeof(BITMAPINFOHEADER), outfile2); // 영상헤드 

	fseek(outfile2, info->fileHeader.bfOffBits, SEEK_SET); //bfOffBits 가 데이터 시작하는 곳이므로 파일 포인터를 그 시작지점으로 옮겨줌

	fwrite(info->image, sizeof(unsigned char), info->infoHeader.biSizeImage, outfile2); // 영상데이터입력
																						// 파일 내용에 출력할 메모리, 데이터 하나의 크기, 쓸 데이터 갯수, 내용이 쓰여질 파일 포인터
																						//free(info->image);      // 픽셀 데이터를 저장한 동적 메모리 해제
																						/////free

	return 0;
}



void Matrix_1_to_2(File_info *info)
{

	for (int y = info->height - 1; y >= 0; y--) // 픽셀 데이터는 아래 위가 뒤집혀서 저장되므로 아래쪽부터 반복, 세로 크기만큼 반복
	{
		for (int x = 0; x < info->width; x++) // 가로 크기만큼 반복
		{
			int index = (x * PIXEL_SIZE) + (y * (info->width* PIXEL_SIZE)) + (info->padding * y);
			info->twoD[x][y] = info->image[index];
		}
	}


}

void Matrix_2_to_1(File_info *info)
{
	for (int y = info->height - 1; y >= 0; y--) // 픽셀 데이터는 아래 위가 뒤집혀서 저장되므로 아래쪽부터 반복, 세로 크기만큼 반복
	{
		for (int x = 0; x < (info->width)*PIXEL_SIZE; x++) // 가로 크기만큼 반복
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
	change->infoHeader.biPlanes = 1;   // 사용하는 색상판의 수로 항상 1이다.
	change->infoHeader.biBitCount = 24;   // 3byte=24bit
	change->infoHeader.biCompression = 0;
	change->infoHeader.biSizeImage = width*height * 3;
	change->infoHeader.biXPelsPerMeter = 2834; //모름
	change->infoHeader.biYPelsPerMeter = 2834; //모름
	change->infoHeader.biClrUsed = 0;
	change->infoHeader.biClrImportant = 0;


	change->width = width;
	change->height = height;
	change->padding = (PIXEL_ALIGN - ((width * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN;
	change->size = change->infoHeader.biSizeImage;

	change->image = (unsigned char*)malloc(change->size);    // 픽셀 데이터의 크기만큼 동적 할당

	change->twoD = (unsigned char**)malloc(sizeof(unsigned char*)*change->height);
	for (int i = 0; i < change->height; i++)
	{
		change->twoD[i] = (unsigned char*)malloc(sizeof(unsigned char*)*change->width);
	}



}




void inter(File_info *ori, File_info *edit) {

	Matrix_1_to_2(ori);




}