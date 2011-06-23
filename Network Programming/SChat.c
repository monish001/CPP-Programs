//Server Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#define BACKLOG 1023
void Error(const char *msg){
    perror(msg);
    exit(1);
}
int createServerSocket(int port){
	int listenfd;
	struct sockaddr_in servaddr;
//STEP1 socket function		
	if((listenfd=socket(AF_INET, SOCK_STREAM, 0)) < 0)
		Error("ERROR WITH socket function");
	
//STEP2 address structure
	bzero((char *) &servaddr, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(port);
	servaddr.sin_addr.s_addr=INADDR_ANY;
	
//STEP3 bind function
	if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
		Error("ERROR WITH bind function");
	
//STEP4 listen function
	listen(listenfd, BACKLOG);
	
	return listenfd;
}
int main(int argc, char** argv){
	int port, listenfd, nfds, temp_fd;
	fd_set temp_fds, rfds;
	struct sockaddr_in cli_addr;

	if(argc != 2 || (port=atoi(argv[1])) < 1024)//test 1.	2.abbc	3.9041abc	4.+abc	5.-abc	6.1024	7.9041
		Error("ERROR WITH ARGS- Usage: ./a.out <portNumber 1024+ >");

	listenfd = createServerSocket(port);

	nfds = getdtablesize();
	FD_ZERO(&temp_fds);
	FD_SET(listenfd, &temp_fds);

	while(1){
		memcpy(&rfds, &temp_fds, sizeof(rfds));
		if(select(nfds, &rfds, (fd_set *)0, (fd_set *)0, (struct timeval *)0) < 0)	Error("select");
		if(FD_ISSET(listenfd, &rfds))
		{
			int connfd, alen = sizeof(cli_addr);
			connfd = accept(listenfd, (struct sockaddr *)&cli_addr, &alen);
			if(connfd < 0)				error("accept ");
			FD_SET(connfd, &temp_fds);
			nfds = (connfd>nfds)?connfd:nfds;
		}
		for(temp_fd=0; temp_fd <= nfds; ++temp_fd)
		if(temp_fd != listenfd && FD_ISSET(temp_fd, &rfds))
		if(serve(temp_fd) == 0)
		{
			(void) close(temp_fd);
			FD_CLR(temp_fd, &temp_fds);
		}
	}
	close(listenfd);
	return 0;
}
