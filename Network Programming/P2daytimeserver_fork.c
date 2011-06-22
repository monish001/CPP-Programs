#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include  <time.h>
#define BACKLOG 10

int main(int argc,char **argv)
{
 int listenfd,connfd;
 struct sockaddr_in servaddr;
 char buff[1000];
 time_t ticks;        

//server admin provides the servers IP address and port number
	if(argc != 2) {
		printf("Error with arguments!!! Usage:%s <portno>\n", argv[0]);
		exit(0);
	}

//STEP 1: socket function
 listenfd = socket(AF_INET,SOCK_STREAM,0);
 printf("SERVER: Listening socket opened with listenfd = %d\n",listenfd);

 //STEP 2: initialize address structure
 bzero(&servaddr, sizeof(servaddr));
 servaddr.sin_family = AF_INET;
 servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
 servaddr.sin_port = htons(atoi(argv[1])); 
 
 //STEP 3: bind (int) listenfd and (struct sockaddr_in) servaddr
 bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
        
 //STEP 4: start listening to client requests
 listen(listenfd,BACKLOG);
 for( ; ; ) {
 //accept client request
  connfd = accept(listenfd,(struct sockaddr *)NULL,NULL);
  if(fork()==0){
//if in CHILD process
    close(listenfd);
    printf("SERVER: Connection established with connfd=%d\n", connfd);
//prepare data to be sent to connected client
    ticks = time(NULL);
    snprintf(buff,sizeof(buff),"%.24s\r\n--ByMonishGupta\r\n",ctime(&ticks));
    write(connfd,buff,strlen(buff));//send data to client
    close(connfd);//close client connection
    exit(0);//end child process
  }
  close(connfd);//close client connection with original server process
 }
 close(listenfd);//close listening socket
}
