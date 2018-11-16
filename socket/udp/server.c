
#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include<string.h>
#include <netinet/in.h>
#define MAXLINE 100
int main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr, cliaddr;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(1234);

	bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	//dg_echo(sockfd, (SA *) &cliaddr, sizeof(cliaddr));
	int			n;
	socklen_t	len;
	char		mesg[MAXLINE];

	for ( ; ; ) {
		len=sizeof(struct sockaddr);
		n = recvfrom(sockfd, mesg, MAXLINE, 0, (struct sockaddr *) &cliaddr, &len);
		sendto(sockfd, mesg, n, 0, (struct sockaddr *) &cliaddr, len);
	}
}
