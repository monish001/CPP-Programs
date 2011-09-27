//Assumptions: 
//1. When there is no label, use tab followed by space.

#define MAXLINE 200
#include <stdio.h>
#include "hashingWithChainingMOT.c"
#include "POT.c"

void completeOperand(char* p1){
	char *p2 = (char*)strtok(NULL, "\n");
	p1[strlen(p1)] = ',';
}
void tokenizeLine(char *str){
	static int lc;

	char label[MAXLINE/4]={0};
	char opcode[MAXLINE/4]={0};
	char operand1[MAXLINE/4]={0};
	char operand2[MAXLINE/4]={0};
     
//Symbol
	char* token = (char*)strtok(str, " ");
	if(token[0] == '\t') 
		token=NULL;   
    if(token!=NULL){
        strcpy(label, token);}
//Opcode
	token = (char*)strtok(NULL, " \n"); 
	if(token!=NULL) 
		strcpy(opcode, token);
//OPERAND1
	token = (char*)strtok(NULL, ",\n");
	if(token!=NULL){
		char *c = strchr(token, '\'');
		if(c!=NULL)
	        completeOperand(token);//Example: f'1,3,3,3,3,4,5,9,0'
		strcpy(operand1, token);
	} 
//OPERAND2
	token = (char*)strtok(NULL, "");
	if(token!=NULL) strcpy(operand2, token);

//Print to stdout
	printf("LC: %d\n", lc);
	printf("Label : %s\n", label);
	printf("Opcode : %s\n", opcode);
	printf("Operand1 : %s\n", operand1);
	printf("Operand2 : %s\n", operand2);
//LC (char* token points to Operand1)
	if(FindInPOT(opcode ,operand1) != -1)//found in POT
		lc += FindInPOT(opcode ,operand1);// puts("foud in POT");}
	else if(lookupInMOT(opcode) != NULL)//find in MOT
		lc += lookupInMOT(opcode)->length;
	else{//invalid opcode
		puts("Opcode NOT Found! Press any key to exit."); 
		getch(); 
		exit(0);
	}	
}

int main(){

	FILE *fp = fopen("Prog.asm", "r");

	if(fp == NULL)
	{ puts("FILE NOT FOUND"); getchar(); exit(0); }

	initMOT();
	
	char str[MAXLINE] = {0};
	do{
		memset(str, 0, MAXLINE);
		fgets(str, MAXLINE-1, fp);
		int breakFlag=0;
		if(strstr(str, "\t end") != NULL){
			if(str[strlen(str)-2]!='\n')
				strcat(str, "\n");
			breakFlag=1;
		}
		printf("--------------------------\n    %s", str);
		tokenizeLine(str);
		getchar();
		if(breakFlag) break;
	}while(1  &&  !feof(fp) );
	deleteMOT();
	return 0;
}

