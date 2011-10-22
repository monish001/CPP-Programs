//Filename: PrintStringPermutations.c
//Running Web-link: http://www.ideone.com/gfK3H
#include<stdio.h>
#include<assert.h>
#include<string.h>
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
	if(pos == (len=strlen(s))-1){
		puts(s);
		return;
	}
	assert(pos < len-1);
	int i;
	int charRepeat[256] = {0};
	for(i=0; i< len-pos; i++){
		rotateLeft(s, pos);
		if(charRepeat[(unsigned int)s[pos]] == 1)//check if new string are achieved after rotation and continue if same char comes again
			continue;
		printPermutations(s, pos+1);
		charRepeat[(unsigned int)s[pos]] = 1;
	}
}
int main(){
	char s[7]="bat";
	printPermutations(s, 0);
	
	puts("");
	char ss[7]="seeen";
	printPermutations(ss, 0);
	
	puts("");
	char sss[7]="see";
	printPermutations(sss, 0);

	return 0;
}
