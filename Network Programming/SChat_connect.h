#ifndef SCHAT_CONNECT_H
#define SCHAT_CONNECT_H
//SChat_connect.h
#define true 1
#define false 0
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "SChat_register.h"
void Error(const char *msg){
    perror(msg);
    exit(1);
}

int **con_ar;
int con_num;//it num of conns

void con_init(){
	con_ar = NULL;
	con_num = 0;
}
void printConns(){
printf("erere");
	int i;
	for(i=0; i<con_num; i++){
		int j;
		for(j=0; j<con_num; j++){
			//printf("%d %d\n",i,j);
			printf("%d\t", con_ar[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void AddCon_num(int ind){
	printf("In AddCon_num()\n");
	printConns();
	++con_num;
	con_ar = (int**) realloc(con_ar, con_num*sizeof(int*));//add row at end
	if(con_ar == NULL) printf("realloc returns NULL\n"), exit(1);
	con_ar[con_num-1] = NULL;//initialize last row pointer to NULL
printf("In AddCon_num(): Row added\n");
	int i;
	for(i=0; i<con_num; i++){//for each row
		con_ar[i] = (int *) realloc(con_ar[i], con_num*sizeof(int));//add column at end
		if(con_ar[i] == NULL) printf("realloc returns NULL\n"), exit(1);
	}
printf("In AddCon_num(): col added\n");
	for(i=con_num-1; i>ind ; i--){//for each row
		int j;
		for(j=con_num-1; j>=ind; j--)//for each col
			con_ar[i][j] = con_ar[i-1][j-1];
	}
	for(i=0; i<con_num; i++){
		con_ar[ind][i] = 0;
		con_ar[i][ind] = 0;
	}
	printConns();
	printf("AddCon_num() ENDS\n");
}
void DeleteCon_num(int ind){
	printf("In DeleteCon_num()\n");
	printConns();
	int i;	
	for(i=ind+1; i<con_num ; i++){//for each row
		int j;
		for(j=ind+1; j<con_num; j++)//for each col
			con_ar[i-1][j-1] = con_ar[i][j];
	}
	con_num--;
	for(i=0; i<con_num; i++){
		con_ar[i] = (int *) realloc(con_ar[i], con_num*sizeof(int));//del col at end
		if(con_ar[i] == NULL) printf("realloc returns NULL\n"), exit(1);
	}
	con_ar = (int**) realloc(con_ar, con_num*sizeof(int*));//del row at end
	if(con_ar == NULL) printf("realloc returns NULL\n"), exit(1);
	printConns();
}

int connectClients(int fd, int new_fd){//both fds are already registered. Returns 1 if connection accepted else returns 0
	printf("In connectClients\n");
	//if not yet connected, ask new_fd for connection
	int fd_ind = isRegistered(fd);
	int new_fd_ind = isRegistered(new_fd);
	int res = 0, n;
	if(con_ar[fd_ind][new_fd_ind] == 0){
		char buff[100]; bzero(buff,100);
		sprintf(buff, "Allow %d to chat y/n?", fd);
		n=write(new_fd, buff, strlen(buff));
		if(n<0)	Error("In connectClients: ");
		bzero(buff,100);
		n=read(new_fd, buff, 99);
		if(n<0) Error("In connectClients: ");
		else if(n==0){
			close(new_fd); unRegister(new_fd);}
		else if(buff[0] == 'y' || buff[0] == 'Y')
			res = 1;
	}
	if(res == 1){
		con_ar[fd_ind][new_fd_ind] = 1;
		con_ar[new_fd_ind][fd_ind] = 1;
	}
	return res;
}

void communicate(int fd, char* msg){//sends msg to all connected to fd
	printf("In communicate\n");
	//write msg to all connections of fd
	int index = isRegistered(fd);
	if(index < 0)	Error("In communicate: ");
	int i;
	for(i=0; i<con_num; i++){
	if( con_ar[i][index]==1){
		//send msg to ar[i]
		if( write(getFd(i), msg, strlen(msg)) < 0 )	Error("In communicate: ");
	}
	}
}

//returns 0 if fd is not connected to anyone yet.
int isConnected(int fd){
	printf("In isConnected\n");
	int i, index = isRegistered(fd);
	for(i=0; i<con_num; i++){
		if(i==index)	continue;
		if(con_ar[i][index] == 1) return 1;
	}
	return 0;
}

//disconnects fd if connected to any.
void unConnect(int fd){
	printf("In unConnect\n");
}

//frees dynamic memory
void freeConnect(){
	printf("In freeConnect\n");
	int i;
	for(i=0; i< con_num; i++)
		free(con_ar[i]);
}

#endif // SCHAT_CONNECT_H
