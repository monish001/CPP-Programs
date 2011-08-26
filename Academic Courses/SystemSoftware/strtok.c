#include<stdio.h>

int main(){
	char str[] = "Hello World! token = strtok(str, del); ", del[] = " ";
	char *token = strtok(str, del);
	while(token != NULL){
		puts(token);
		token = strtok(NULL, del);
	}

    return 0, getchar();
}
