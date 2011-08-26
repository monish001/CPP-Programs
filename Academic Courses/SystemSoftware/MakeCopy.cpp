#include<stdio.h>

int main(){
    FILE *fr, *fw;
	char c;
	if((fr= fopen("MakeCopy.txt", "r"))== NULL)
		return(0), printf("Error in fr");
	if((fw= fopen("copy.txt", "w"))== NULL)
		return(0), printf("Error in fw");
	while((c = fgetc(fr))!=EOF){
		fputc(c, fw);
		printf("%c", c);
	}
	getchar();
    return 0;
}
