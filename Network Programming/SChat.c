//Server Program Psuedo-code

#include <stdio.h>
#include <stdlib.h>

void Error(char* str){
	printf("%s", str);
	exit(0);
}


int main(int argc, char** argv){
	int port, listenfd, connfd;
	struct sockaddr_in servaddr;
	
	if(argc != 2 || port=atoi(argv[1]) < 1024)//test 1.	2.abbc	3.9041abc	4.+abc	5.-abc	6.1024	7.9041
		Error("ERROR WITH ARGS- Usage: ./a.out <portNumber 1024+ >");
	
	if((listenfd=socket(AF_INET, SOCK_STREAM, 0)) < 1)
		Error("ERROR WITH socket function");
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(port);
	servaddr.sin_addr=htonl(INADDR_ANY);
	
	if(bind(sockfd, (struct sockaddr_in*)&servaddr, sizeof(servaddr)) < 1)
		Error("ERROR WITH bind function");
	
	return 0;
}