#include<stdio.h>
main(){
FILE *source = fopen(__FILE__, "r"); 
fseek(source, 0, SEEK_END); 
int byteCount = ftell(source); 
fclose(source); 

printf("%d", byteCount);
getchar();
}
