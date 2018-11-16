#include <stdio.h>
#include "jpeglib.h"
#include <setjmp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#include <string.h>
#include <stdlib.h>


#define DBG_PRINTF printf



		








/*
static int FBShowLine(int iXStart, int iXEnd, int iY, unsigned char *pucRGBArray)
{
	int i = iXStart * 3;
	int iX;
	unsigned int dwColor;

	if (iY >= g_tFBVar.yres)
		return -1;

	if (iXStart >= g_tFBVar.xres)
		return -1;

	if (iXEnd >= g_tFBVar.xres)
	{
		iXEnd = g_tFBVar.xres;		
	}
	
	for (iX = iXStart; iX < iXEnd; iX++)
	{
		//0xRRGGBB 
		dwColor = (pucRGBArray[i]<<16) + (pucRGBArray[i+1]<<8) + (pucRGBArray[i+2]<<0);
		i += 3;
		FBShowPixel(iX, iY, dwColor);
	}
	return 0;
}
*/

/*
Allocate and initialize a JPEG decompression object    // 分配和初始化一个decompression结构体
Specify the source of the compressed data (eg, a file) // 指定源文件
Call jpeg_read_header() to obtain image info		   // 用jpeg_read_header获得jpg信息
Set parameters for decompression					   // 设置解压参数,比如放大、缩小
jpeg_start_decompress(...); 						   // 启动解压：jpeg_start_decompress
while (scan lines remain to be read)
	jpeg_read_scanlines(...);						   // 循环调用jpeg_read_scanlines
jpeg_finish_decompress(...);						   // jpeg_finish_decompress
Release the JPEG decompression object				   // 释放decompression结构体
*/

/* Uage: jpg2rgb <jpg_file>
 */
struct color{
	unsigned char b,g,r;
};
static int putBuf(int iXStart, int iXEnd, int iY, unsigned char *pucRGBArray,struct color **buf)
{
	return 0;
}
int main(int argc, char **argv)
{
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;
	FILE * infile;
	int row_stride;
	unsigned char *buffer;
	struct color **buf;
	int i,j;
	if (argc != 2)
	{
		printf("Usage: \n");
		printf("%s <jpg_file>\n", argv[0]);
		return -1;
	}

	

	// 分配和初始化一个decompression结构体
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);

	// 指定源文件
	if ((infile = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "can't open %s\n", argv[1]);
		return -1;
	}
	jpeg_stdio_src(&cinfo, infile);

	// 用jpeg_read_header获得jpg信息
	jpeg_read_header(&cinfo, TRUE);
	/* 源信息 */
	printf("image_width = %d\n", cinfo.image_width);
	printf("image_height = %d\n", cinfo.image_height);
	printf("num_components = %d\n", cinfo.num_components);

	// 设置解压参数,比如放大、缩小
	printf("enter scale M/N:\n");
	scanf("%d/%d", &cinfo.scale_num, &cinfo.scale_denom);
	printf("scale to : %d/%d\n", cinfo.scale_num, cinfo.scale_denom);

	// 启动解压：jpeg_start_decompress	
	jpeg_start_decompress(&cinfo);

	/* 输出的图象的信息 */
	printf("output_width = %d\n", cinfo.output_width);
	printf("output_height = %d\n", cinfo.output_height);
	printf("output_components = %d\n", cinfo.output_components);

	// 一行的数据长度
	row_stride = cinfo.output_width * cinfo.output_components;
	buffer = malloc(row_stride);
	buf=(struct color**)malloc(sizeof(struct color *));
	for(i=0;i<cifo.output_height;i++)
	{
		buf[i]=(struct color*)malloc(sizeof(struct color));
	}
	// 循环调用jpeg_read_scanlines来一行一行地获得解压的数据
	while (cinfo.output_scanline < cinfo.output_height) 
	{
		(void) jpeg_read_scanlines(&cinfo, &buffer, 1);

		// 写到LCD去
		putBuf(0, cinfo.output_width, cinfo.output_scanline, buffer);
	}
	
	free(buffer);
	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);

	return 0;
}

