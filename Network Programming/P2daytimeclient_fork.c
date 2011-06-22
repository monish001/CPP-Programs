#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
//#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int sockfd,n=0;
	char recvline[1000+1];
	struct sockaddr_in servaddr;

//client provides the servers IP address and port number
	if(argc != 3) {
		printf("Error with arguments!!! Usage:%s <IPv4 address of server> <portno>\n", argv[0]);
		exit(0);
	}

	if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0) {
		printf("Socket Error!!!");
		exit(0);
	}else
	printf("CLIENT:Client sockfd = %d\n",sockfd);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2])); 
	servaddr.sin_addr.s_addr = inet_addr(argv[1]); 

	int conn_status = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if(conn_status<0) {
		printf("CLIENT:connection function returns %d\n",conn_status);
		printf("Connect Error!!!");
		exit(0);
	}
	else {
		while( (n=read(sockfd,recvline,1000))>0) { 
			recvline[n] = 0; /* null terminate */
			if(fputs(recvline,stdout) == EOF) {
				printf("fputs error!!!");
				exit(0);
			}
		}
	}
	if(n<0) {
		printf("read error!!!");
		exit(0); 
	}
	exit(0);
}
