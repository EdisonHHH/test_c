#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
 
#define STUN_SERVER_IP "132.177.123.13"
#define STUN_SERVER_PORT 3478
 
int socketfd;
 
struct stun_header{
	unsigned short type;
	unsigned short length;
	unsigned int transId1;
	unsigned int transId2;
	unsigned int transId3;
	unsigned int transId4;
};
 
struct mapped_address{
	unsigned padding : 8;
	unsigned family : 8;
	unsigned short port;
	unsigned int address;
};
 
int 
init_socket(){
	socketfd = socket(AF_INET , SOCK_DGRAM , 0);
}
 
int 
stun_rand(){
	srand(time(NULL));
	return rand();
}
 
struct stun_header* 
build_stun_header(unsigned short type){
 
	struct stun_header *header ;
 
	header = (struct stun_header*)malloc(sizeof(struct stun_header));
	header->type = htons(type);
	header->length = 0;
	header->transId1 = stun_rand();
	header->transId2 = stun_rand();
	header->transId3 = stun_rand();
	header->transId4 = stun_rand();
 
	return header;
}
 
int 
udp_send(void *data , int len
		, const char *ip , int port){
 struct hostent * host_entry;
 host_entry=gethostbyname("stun.ekiga.net");
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	//addr.sin_addr.s_addr = inet_addr(ip);
	//memcpy(&addr.sin_addr.s_addr, host_entry->h_addr_list[0], 4);
	if(host_entry!=NULL)
	{
		addr.sin_addr=*((struct in_addr *)host_entry->h_addr_list[0]);
		printf("%x\n",addr.sin_addr.s_addr);
	}
	addr.sin_port = htons(port);
 
	return sendto(socketfd , data , len , 0
			, (struct sockaddr*)&addr , sizeof(struct sockaddr));
 
}
 
int 
main(int argc , char *argv[]){
 
	init_socket();
	struct stun_header recv_header;
	struct sockaddr_in addr;
	socklen_t length;
	unsigned char buf[1024];
	int i;
	struct stun_header* header
		= build_stun_header(0x0001);
 
	udp_send(header , sizeof(struct stun_header)
			, STUN_SERVER_IP , STUN_SERVER_PORT);
			
	length = sizeof(struct sockaddr);

	int len=recvfrom(socketfd , buf , 1024 , 0
			, (struct sockaddr*)&addr , &length);
	//printf("%d %d\n",recv_header.type,recv_header.length);
	for(i=0;i<len;i++)
		printf("%02x ",buf[i]);
	printf("\n");
 
	return 0;
}