//Server Program
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "SChat_register.h"

#define BACKLOG 1023

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

int serve(int fd){
printf("\nIn serve\n");
	int regisIndex = isRegistered(fd);
printf("Registered fds: ");
getRegisteredList();
	char buff[100], temp[100];
	int status=0, rd=0, wr=0;
	bzero(buff,100);
	rd = read(fd, buff, 99);
	if(rd == 0){
		clean(fd);
		printf("Closing connection");
		return status;
	}
	if(rd < 0)
		Error("read error in serve: ");

	if(regisIndex == -1){//if not registered
printf("Gonna register now\n");
		sscanf(buff, "%s", temp);
		if(strcmp((temp), "register") != 0){
			printf("Closing connection");
			return status;
		}
		//clean(fd);
		registerMe(fd);
printf("Registered\n");
		sprintf(buff, "You are now registered with registration id = %d\n", fd);
		wr = write(fd, buff, strlen(buff));
		if(wr < 0)
			Error("write error in serve: ");
		return status=1;
	}else{//if registered
printf("Already registered\n");
		sscanf(buff, "%s", temp);
		int conn_req = strcmp(temp, "connect");
		if(conn_req == 0){//if connect request
			int new_fd;
			sscanf(buff, "%s %d", temp, &new_fd);
			if(isRegistered(new_fd) < 0 ){//if new_fd NOT registered
				sprintf(buff, "No connection is registered with id = %d\n", new_fd);
			}else if(connectClients(fd, new_fd) == 1){//if connection accepted by new_fd
				sprintf(buff, "%d now connected with %d\n", fd, new_fd);
			}else{//if connection refused by new_fd
				sprintf(buff, "Connection refused by %d\n", new_fd);
			}
			wr = write(fd, buff, strlen(buff));
			if(wr < 0) Error("write error in serve: ");
			return status=1;
		}else if(isConnected(fd) == 0){//if not connected to anyone yet
			sprintf(buff, "Please connect to chat\n", fd);
			wr = write(fd, buff, strlen(buff));
			if(wr < 0) Error("write error in serve: ");
			return status=1;
		}else{//if already connected, send msg
			communicate(fd, buff);
		}
	}
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
	init();
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
	freeRegister();
	return 0;
}
