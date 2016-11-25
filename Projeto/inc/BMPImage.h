#ifndef BMPIMAGE_H
#define BMPIMAGE_H

typedef struct BMPImagem
{
    int   width;
    int   height;
    char *data;
}BMPImage;

void getBitmapImageData( char *pFileName, BMPImage *pImage );

#endif // BMPIMAGE_H
