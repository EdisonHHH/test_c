#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include<string.h>
#include <netinet/in.h>
#define MAXLINE 100
int main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		printf("usage: tcpcli <IPaddress>");

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(1234);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	//str_cli(stdin, sockfd);		/* do it all */
	char	sendline[MAXLINE], recvline[MAXLINE];

	while (fgets(sendline, MAXLINE, stdin) != NULL) {

		write(sockfd, sendline, MAXLINE);
		

		if (read(sockfd, recvline, MAXLINE) == 0)
			printf("str_cli: server terminated prematurely");

		fputs(recvline, stdout);
	}
	return 0;
}
