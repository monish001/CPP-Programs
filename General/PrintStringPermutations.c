//Filename: PrintStringPermutations.c
#include<stdio.h>
void rotateLeft(char* s, int pos){
	char tm = s[pos];
	int i;
	for(i=pos; i<strlen(s); i++){
		s[i] = s[i+1];
	}
	s[i-1]=tm;
}
void printPermutations(char* s, int pos){
	int len;
	if(pos >= (len=strlen(s))-1){
		puts(s);
		return;
	}
	int i;
	for(i=0; i< len-pos; i++){
		rotateLeft(s, pos);
		printPermutations(s, pos+1);
	}
}
int main(){
	char s[7]="Bat";
	printPermutations(s, 0);
	return getch();
}
