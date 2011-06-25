#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, n, max_fd;
    fd_set rd_set, wr_set, temp_rd_set;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char exit_str[5] = "exit";
    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

//STEP1 socket function
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
	
//STEP2 prepare address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

//STEP3 connect function: request to server for connection
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    
    max_fd = (sockfd>fileno(stdin))?sockfd:fileno(stdin);
    //FD_ZERO(&wr_set);	
    FD_ZERO(&rd_set);
//    FD_SET(sockfd, &wr_set);
    FD_SET(sockfd, &temp_rd_set);
    FD_SET(fileno(stdin), &temp_rd_set);
//STEP4 read and write to server.
    while(1){
	memcpy(&rd_set, &temp_rd_set, sizeof(rd_set));
	if(select( max_fd+1, &rd_set, (fd_set *)NULL, (fd_set *)NULL, (struct timeval*)NULL)<0)	error("in select: ");
	if(FD_ISSET(sockfd, &rd_set)){
		//printf("CLIENT: sockfd is readable.\n");
		bzero(buffer,256);
		n = read(sockfd,buffer,255);//read from server and save it in array buffer
		if (n < 0) error("ERROR reading from socket");
		printf("%s\n",buffer);//write to stdout the buffer's contents
	}
	if(FD_ISSET(fileno(stdin), &rd_set)){
		//printf("CLIENT: stdin is readable.\n");
		bzero(buffer,256);
		fgets(buffer,255,stdin);//read from client stdin
		if(bcmp(exit_str, buffer, 4)==0){ close(sockfd); return 0; }    
		n = write(sockfd,buffer,strlen(buffer));//write to server
		if (n < 0) error("ERROR writing to socket");
	}
    }
    close(sockfd);
    return 0;
}
