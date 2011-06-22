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

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
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
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");	

//STEP4 listen function
    listen(sockfd,10);
	
//STEP5 accept and serve clients one by one in iterative fashion
	while(1){
		clilen = sizeof(cli_addr);
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		 if (newsockfd < 0) error("ERROR on accept");
		 bzero(buffer,256);
		 while(	 (n=read(newsockfd,buffer,255)) > 0  ){
		 if (n < 0) error("ERROR reading from socket");
		 n = write(newsockfd,buffer,n);
		 if (n < 0) error("ERROR writing to socket");
		 bzero(buffer,256);
		 }
		 close(newsockfd);
	}
     close(sockfd);
     return 0; 
}


