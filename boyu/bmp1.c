#include <stdio.h> 
struct color{
	unsigned char b,g,r;
};
void SaveBmp(char* filename,int height,int width,unsigned char *data){
	unsigned int size = width*height*3+54;
	unsigned short head[]={
		0x4D42,size%0x10000,size/0x10000,0,0,0x36,0,0x28,
		0,width%0x10000,width/0x10000,height%0x10000,height/0x10000,0x10,0x18,0,
		0,0,0,0,0,0,0,0,0,0,0
	};
	FILE* fp=fopen(filename,"wb");
	if(!fp)return;
	fwrite(head,1,sizeof(head),fp);
	fwrite(data,1,size,fp);
	fclose(fp);
}
void main(){
	int i;
	int j;
	struct color buffer[256][512];
	for (i=0;i<256;i++)
	{
		for (j=0;j<512;j++)
		{
			buffer[i][j].b=buffer[i][j].g=j/2;
			buffer[i][j].r=i;
		}
	}
	SaveBmp("0.bmp",256,512,(unsigned char*)buffer);
}
