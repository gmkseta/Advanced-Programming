#pragma once
//
//  Bitmap.h
//

#include "stdafx.h"
#ifndef LaserMaze_Bitmap_h
#define LaserMaze_Bitmap_h

#pragma pack(2) // Add this

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

#  define _BI_RGB       0             /* No compression - straight BGR data */
#  define _BI_RLE8      1             /* 8-bit run-length compression */
#  define _BI_RLE4      2             /* 4-bit run-length compression */
#  define _BI_BITFIELDS 3             /* RGB bitmap with RGB masks */
#  define _PIXEL_ALIGN 4
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
	Bitmap() {}
	

};

#endif