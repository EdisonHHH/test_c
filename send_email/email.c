#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
 
#define SOCKET_ERROR -1

#define PRINT(x) printf("%s\n",(x))
 
int sockfd;
int ret;
char *send_data;
char *recv_data;
char From[128];
char To[128];
char Date[128];
char Subject[512];
char Context[6000]={0};
char buffer[1024];

int connectHost(const char *smtpaddr)
{
	struct hostent *hptr;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd < 0)
    {
        printf("Create socket error!\n");
        return -1;
    }
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);
    
	
	if((hptr = gethostbyname(smtpaddr)) == NULL)
	{
		printf(" gethostbyname error for host:%s\n", smtpaddr);
		return 0;
	}
	servaddr.sin_addr=*(struct in_addr *)hptr->h_addr;
  

    if (connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) < 0)    
    {
        printf("Connect failed... \n");
        return -1;
    }
   
     
    memset(buffer, 0, sizeof(buffer));
     
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {    
        printf("receive failed... \n");
        return -1;
    }
    else 
    {        
         printf("%s\n", buffer);
    }
    return sockfd;    
}
 

int getResponse()
{    
    memset(buffer,0,sizeof(buffer));
    ret = recv(sockfd,buffer,1024,0);
    if(ret == SOCKET_ERROR)
    {
        printf("receive nothing\n");
        return -1;
    }
    buffer[ret]='\0';
     
    if(*buffer == '5')
    {
        printf("the order is not support smtp host\n ");
        return -1;
    }

    printf("recieved buffer:%s\n",buffer);

    return 0;
}
 
int login(char *username,char *password)
{
    printf("login.....sockfd: %d\n",sockfd);
    char ch[100];
    if(username == "" || password == "")
        return -1;
     
    send_data = "HELO 163.com\r\n";
    printf("%s\n",send_data);
    ret = send(sockfd, send_data, strlen(send_data), 0);
    if(ret == SOCKET_ERROR)
    {
        close(sockfd);
        return -1;
    }         
    if(getResponse() < 0)
        return -1;
     
    send_data = "AUTH LOGIN\r\n";
    printf("%s\n",send_data);
    ret = send(sockfd, send_data, strlen(send_data), 0);
    if(ret == SOCKET_ERROR)
    {
        close(sockfd);
        return -1;
    }
    if(getResponse() < 0)
        return -1;
    sprintf(ch, "%s\r\n", username);
    printf("%s\n",ch);
    ret = send(sockfd, (char *)ch, strlen(ch),0);
    if(ret == SOCKET_ERROR)
    {
        close(sockfd);
        return -1;
    }
     
    if(getResponse() < 0)
         return -1;
     
    sprintf(ch,"%s\r\n",password);
    printf("%s\n",ch);
    ret = send(sockfd,(char *)ch,strlen(ch),0);
    if(ret == SOCKET_ERROR)
    {

        close(sockfd);
        return -1;
    }
     
    if(getResponse() < 0)
        return -1;
     
    return 0;
 
}
 
int sendmail(char* from, char * to, char * context)
{
    if(from =="" ||to == ""||context == "")
    {
        printf("arguments error!\n");
        return -1;
    }
    
    sprintf(From, "MAIL FROM: <%s>\r\n", from);
    printf("%s\n",From);
     
    if((ret = send(sockfd, From, strlen(From), 0)) == SOCKET_ERROR)
    {
        close(sockfd);
        return -1;
    }
     
    if(getResponse() < 0)
        return -1;
     
    sprintf(To, "RCPT TO: <%s>\r\n", to);
    if((ret = send(sockfd, To, strlen(To),0)) == SOCKET_ERROR)
    {
        close(sockfd);
        return -1;
    }
    if(getResponse() < 0)
        return -1;
     
    send_data = "DATA\r\n";
    if((ret = send(sockfd,send_data,strlen(send_data),0)) == SOCKET_ERROR)
    {
        close(sockfd);
        return -1;
    }
    if(getResponse() < 0)
        return -1;
        

    //strcpy(Context,"From:\"huang\"<499061232.happy@163.com>\r\nTo: \"test\"<499061232@qq.com>\r\nSubject: hello test\r\n\r\n hello world\r\n.\r\n");
   sprintf(Context,"From:\"huang\"<%s>\r\nTo: \"test\"<%s>\r\nSubject: hello test\r\n\r\n %s\r\n.\r\n",from,to,context);
    if((ret= send(sockfd, Context, strlen(Context), 0)) == SOCKET_ERROR)
    {
        close(sockfd);
        return -1;
    }
     
    printf("ret size:%d\n", ret);
    
    memset(buffer, '\0', sizeof(buffer));
    
    if(getResponse() < 0)
         return -1;    
 
    printf("QUIT!!!!!!!!!!!!!!!!\n");
    if((ret = send(sockfd,"QUIT\r\n",strlen("QUIT\r\n"), 0)) == SOCKET_ERROR)
    {
        close(sockfd);
        return -1;
    }
    if(getResponse() < 0)
        return -1;
 
    printf("Send Mail Successful!\n");
    return 0;
}
 

int main()
{    
    char from[128] = "499061232.happy@163.com";
    char to[128] = "499061232@qq.com";

    char context[6000] = "Just a test.........\n";
    char server[56]="smtp.163.com";

    char *name ="NDk5MDYxMjMyLmhhcHB5QDE2My5jb20=";//base64
    char *passwd = "aDMzOTU0NjQ3Mw==";//base64
 
    if(connectHost(server)<0)
    {
        printf("Can Not LOGIN !\n");
        return -1;
    }
 
    if(login(name, passwd) < 0)
    {
        fprintf(stderr,"Can Not LOGIN !\n");
        return -1;
    }
    sendmail(from, to , context);
    return 0;
 }