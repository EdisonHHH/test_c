#include <stdio.h>
#include <stdlib.h>
#define TARGET "www.baidu.com"
int main( )
{
   char   psBuffer[512];
   FILE   *pPipe;
 printf("huang\n");
   if( (pPipe = popen( "ping -c 10 www.baidu.com", "r" )) == NULL )
      exit( 1 );
printf("djfkjdf\n");
   while(fgets(psBuffer, 512, pPipe))
   {
     printf("%s", psBuffer);
	printf("test\n");
   }
   pclose(pPipe);
}
