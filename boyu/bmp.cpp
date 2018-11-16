#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long BOOL;
typedef long LONG;
typedef unsigned char BYTE;
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef struct {
	WORD bfType;//2
	DWORD bfSize;//4
	WORD bfReserved1;//2
	WORD bfReserved2;//2
	DWORD bfOffBits;//4
}__attribute__((packed))FileHead;
typedef struct{
	DWORD biSize;//4
	LONG biWidth;//4
	LONG biHeight;//4
	WORD biPlanes;//2
	WORD biBitCount;//2
	DWORD biCompress;//4
	DWORD biSizeImage;//4
	LONG biXPelsPerMeter;//4
	LONG biYPelsPerMeter;//4
	DWORD biClrUsed;//4
	DWORD biClrImportant;//4
}__attribute__((packed))Infohead;

typedef struct 
{
	BYTE b;
	BYTE g;
	BYTE r;
}RGB_data;//RGB TYPE
int bmp_generator(const char * filename,int width,int height,unsigned char *data)
{
	FileHead bmp_head;
	Infohead bmp_info;

	int line_bytes=((width+1)*3)&~3;
	int size=line_bytes*height;
	int bytes_line_0=line_bytes-width*3;

	unsigned char buf[4]={0};

	bmp_head.bfType=0x4d42;
	bmp_head.bfSize=size+sizeof(FileHead)+sizeof(Infohead);//24+head+info no quad    
	bmp_head.bfReserved1=bmp_head.bfReserved2=0;
	bmp_head.bfOffBits=bmp_head.bfSize-size;

	bmp_info.biSize=40;
	bmp_info.biWidth=width;
	bmp_info.biHeight=height;
	bmp_info.biPlanes=1;
	bmp_info.biBitCount = 24;
	bmp_info.biCompress=0;
	bmp_info.biSizeImage=size;
	bmp_info.biXPelsPerMeter=0;
	bmp_info.biYPelsPerMeter=0;
	bmp_info.biClrUsed=0;
	bmp_info.biClrImportant=0;

	FILE *fp;
	if(!(fp=fopen(filename,"wb"))) 
		return 0;

	fwrite(&bmp_head,1,sizeof(FileHead),fp);
	fwrite(&bmp_info,1,sizeof(Infohead),fp);
	for(int i=0;i<height;i++)
	{
		fwrite(data,1,width*3,fp);
		if(bytes_line_0);
			fwrite(buf,1,bytes_line_0,fp);
	}
	fclose(fp);
	return 1;
}
#define H 512
#define W 512
int main(int argc,char **argv)
{
	int i,j;
	RGB_data buffer[H][W];
		
	for (i=0;i<H;i++)
	{
		for (j=0;j<W;j++)
		{
			buffer[i][j].g=256-i/2;
			buffer[i][j].r=i/2;
			buffer[i][j].b=j/2;
		}
	}
	bmp_generator("/home/user/1234.bmp",W,H,(BYTE*)buffer);
	return 1;
}

