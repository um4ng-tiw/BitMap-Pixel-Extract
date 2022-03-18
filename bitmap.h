/*
 * bitmap.h
 *
 *  Created on: 18-Mar-2022
 *      Author: Umang
 */

#ifndef BITMAP_H_
#define BITMAP_H_

void getPixelsData(FILE *input, unsigned char *pixels);
void getDimensions(FILE *input, int* Imgheight, int* Imgwidth);
void getHeader(FILE *input, unsigned char *header) ;
void getColorTable(FILE *input, unsigned int *colorTable);

#endif /* BITMAP_H_ */
