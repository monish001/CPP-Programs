//Given a (decimal - e.g. 3.72) number that is passed in as a string, print the binary representation.
//If the number can not be represented accurately in binary, print “ERROR”
#include<stdio.h>
#include<string.h>

int main(){
	char in[50], fr[10], out[80];
	int i, inte; double frac;
	gets(in);// puts(in);
	for(i=0; in[i]!='.'; i++){
             if(in[i] == '\0'){ puts("Input Fractional Number"); getch(); return 0;}
             }
	in[i++] = '\0';
	
	strcpy(fr, in+i);
//	puts(fr);
	inte = atoi(in);
	frac = 1.0*atoi(fr)/pow(10,strlen(fr));
	
	i=0;
	while(inte){
		out[i++] = inte%2 + '0';
		inte >>= 1;
	}
	out[i] = '\0';
	strrev(out);
	out[i++] = '.';
	int frac_start = i;
//	printf("frac = %f\n", frac);
	while(frac && i-frac_start <=32){
		frac *= 2;
		if(frac >= 1){
			out[i++] = '1';
			frac -= 1;
		}else{
			out[i++]='0';
		}
	}
	out[i] = '\0';
//	puts(out);
	puts((i-frac_start <=32)?out:"ERROR");
	fflush(stdin);
    return 0, getchar();
}
