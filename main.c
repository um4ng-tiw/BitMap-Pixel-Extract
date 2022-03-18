/*
 * main.c
 *
 *  Created on: 17-Mar-2022
 *      Author: Umang
 */

#include<stdio.h>
#include<stdlib.h>
#include "bitmap.h"

int main(){
	// Reading the input image
	FILE* input = fopen("input.bmp", "r");
    FILE* output = fopen("output.bmp", "wb");


    unsigned char header[54];
    unsigned int colorTable[256];
    int height, width;

	if(!input){
		printf("\n FILE NOT FOUND");
		return 0;
	}

	getHeader(input, header);
	getColorTable(input, colorTable);
	getDimensions(input, &height, &width);

	int size = height*width;

	unsigned char pixels[width][height];

	getPixelsData(input, &pixels[0][0]);


    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            pixels[i][j]+=50;
        }
    }

    fwrite(header, sizeof(unsigned char), 54, output);
    fwrite(colorTable, sizeof(unsigned int), 256, output);
    fwrite(pixels, sizeof(unsigned char), size, output);

    fclose(input);
    fclose(output);

	printf("\n");
	return 0;
}
