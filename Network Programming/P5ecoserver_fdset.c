//Echo server program using non-blocking IO
/*
Using Select for Data-driven Processing
    A process calls select to wait for one (or more) of a collection of open files (or sockets) to be ready for I/O.
    int select(int n, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
    FD_CLR(int fd, fd_set *set);
    FD_ISSET(int fd, fd_set *set);
    FD_SET(int fd, fd_set *set);
    FD_ZERO(fd_set *set);
    select() returns the number of fd's ready for I/O.
    FD_ISSET is used to determine which fd's are ready.
    select() returns 0 if the timer expires.
    select() returns -1 if there is an error.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int echo(int fd)
{
	char buf[BUFSIZ];
	int  cc;
	cc = read(fd, buf, sizeof buf);
	if(cc < 0)
		error("echo read");
	if(cc && write(fd, buf, cc) < 0)
		error("echo write");
	return cc;
}

int main(int argc, char *argv[ ])
{
		char   *service = "echo";
		struct sockaddr_in serv_addr, cli_addr;
		int    sockfd, portno;
		fd_set rfds;
		fd_set afds;
		int    alen;
		int    fd, nfds;

if(argc != 2){
	error("Usage: %s hostname port",argv[0]);
}
//STEP1 socket function
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
		
//STEP2 address structure
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);

//STEP3 bind function
     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
              error("ERROR on binding");	

//STEP4 listen function
    listen(sockfd,10);
		
	nfds = getdtablesize();
	FD_ZERO(&afds);
	FD_SET(sockfd, &afds);
	while (1) {
		memcpy(&rfds, &afds, sizeof(rfds));
		if(select(nfds, &rfds, (fd_set *)0, (fd_set *)0, (struct timeval *)0) < 0)
			error("select");
		if(FD_ISSET(sockfd, &rfds))
		{
			int ssock;
			alen = sizeof(cli_addr);
			ssock = accept(sockfd, (struct sockaddr *)&cli_addr, &alen);
			if(ssock < 0)
				error("accept ");
			FD_SET(ssock, &afds);
		}
		for(fd=0; fd < nfds; ++fd)
		if(fd != sockfd && FD_ISSET(fd, &rfds))
		if(echo(fd) == 0)
		{
			(void) close(fd);
			FD_CLR(fd, &afds);
		}
	}
}