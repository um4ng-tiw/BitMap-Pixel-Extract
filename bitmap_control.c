/*
 * bitmap_control.c
 *
 *  Created on: 18-Mar-2022
 *      Author: Umang
 */
#include<stdio.h>
#include<stdlib.h>
#include "bitmap.h"

void getPixelsData(FILE *input, unsigned char *pixels) {

	// 18th byte is the width
	fseek(input, 18, SEEK_SET);
	int width, height, offset_value;

	// Reading the width
	fread(&width, 4, 1, input);
	// Next 4 bytes are height
	// Reading the height
	fread(&height, 4, 1, input);

	fseek(input, 10, SEEK_SET);
	fread(&offset_value, 4, 1, input);

	printf("Offset:%d\n", offset_value);

	printf("Height:%d ", width);
	printf("Width:%d\n", height);

	// 28th byte is the bits per pixel
	// Bit depth
	fseek(input, 28, SEEK_SET);
	unsigned short bit_per_pixel;
	fread(&bit_per_pixel, 2, 1, input);

	int size = (bit_per_pixel / 8) * height * width;

	printf("Depth: %d\n", bit_per_pixel);

	fseek(input, offset_value, SEEK_SET);
	fread(pixels, sizeof(unsigned char), size, input);
}

void getDimensions(FILE *input, int* Imgheight, int* Imgwidth) {

	if (!input) {
		printf("\n FILE NOT FOUND");
		return;
	}

	// 18th byte is the width
	fseek(input, 18, SEEK_SET);
	int width, height;

	// Reading the width
	fread(&width, 4, 1, input);
	// Next 4 bytes are height
	// Reading the height
	fread(&height, 4, 1, input);

	*Imgheight = height;
	*Imgwidth = width;

}

// Pass the array of size 54 to store the header into it
void getHeader(FILE *input, unsigned char *header) {
	fseek(input, 0, SEEK_SET);
//		unsigned char header[54];
	if (!input) {
		printf("\n FILE NOT FOUND");
		return;
	}

	fread(header, sizeof(unsigned char), 54, input);
}

//Pass the array of size 256 * 4 bytes to store the colorTable
void getColorTable(FILE *input, unsigned int *colorTable) {
//	unsigned int colorTable[256];

	fseek(input, 54, SEEK_SET);
	fread(colorTable, sizeof(unsigned int), 256, input);
}
