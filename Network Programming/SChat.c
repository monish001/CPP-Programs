//Server Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#define BACKLOG 10

void Error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char** argv){
	int port, listenfd, connfd;
    socklen_t clilen;
	struct sockaddr_in servaddr, cli_addr;
	
	if(argc != 2 || port=atoi(argv[1]) < 1024)//test 1.	2.abbc	3.9041abc	4.+abc	5.-abc	6.1024	7.9041
		Error("ERROR WITH ARGS- Usage: ./a.out <portNumber 1024+ >");

//STEP1 socket function		
	if((listenfd=socket(AF_INET, SOCK_STREAM, 0)) < 0)
		Error("ERROR WITH socket function");
	
//STEP2 address structure
	bzero((char *) &serv_addr, sizeof(serv_addr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(port);
	servaddr.sin_addr=htonl(INADDR_ANY);
	
//STEP3 bind function
	if(bind(sockfd, (struct sockaddr_in*)&servaddr, sizeof(servaddr)) < 0)
		Error("ERROR WITH bind function");
	
//STEP4 listen function
	listen(listenfd, BACKLOG);
	
	while(1){
		clilen = sizeof(cli_addr);
		connfd = accept(listenfd, (struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0) error("ERROR on accept OR Connection terminated by client");
		if(fork() != 0){//in parent process
			close(newsockfd);
		}else{//in child process
			close(sockfd);
			bzero(buffer,256);
			while(	 (n=read(newsockfd,buffer,255)) > 0  ){
				if (n < 0) error("ERROR reading from socket");
				n = write(newsockfd,buffer,n);
				if (n < 0) error("ERROR writing to socket");
				bzero(buffer,256);
			}
			close(newsockfd);
		}
	}
	return 0;
}