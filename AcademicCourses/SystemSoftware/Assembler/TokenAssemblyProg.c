//Assumptions: 
//1. When there is no label, use tab followed by space.
//2. Append an empty line at the end of the program.

#define MAXLINE 300
#include <stdio.h>
#include "hashingWithChainingMOT.c"
#include "POT.c"

void completeOperand(char* p1){
	char *p2 = strtok(NULL, "\n");
	p1[strlen(p1)] = ',';
}
void tokenizeLine(char *str){
	static int lc;

	int lab_next=0, opc_next=0, ope1_next=0, ope2_next=0;
	char label[MAXLINE][MAXLINE];
	char opcode[MAXLINE][MAXLINE];
	char operand1[MAXLINE][MAXLINE];
	char operand2[MAXLINE][MAXLINE];
     
//Symbol
	char* token = strtok(str, " ");
	if(token[0] == '\t') 
		token=NULL;   
    if(token!=NULL){
        strcpy(label[lab_next++], token);}
	printf("Label : %s\n", token);
//Opcode
	token = strtok(NULL, " \n"); 
	if(token!=NULL) strcpy(opcode[opc_next++], token);
	printf("Opcode : %s\n", token);
//OPERAND1
	token = strtok(NULL, ",\n");
	if(token!=NULL){
		char *c = strchr(token, '\'');
		if(c!=NULL)
	        completeOperand(token);//Example: f'1,3,3,3,3,4,5,9,0'
		strcpy(operand1[ope1_next++], token);
	} 
	printf("Operand1 : %s\n", token);
//LC (char* token points to Operand1)
	printf("LC: %d\n", lc);
	if(FindInPOT(opcode[opc_next-1] ,token) != -1)//found in POT
		lc += FindInPOT(opcode[opc_next-1] ,token);// puts("foud in POT");}
	else if(lookupInMOT(opcode[opc_next-1]) != NULL)//find in MOT
		lc += lookupInMOT(opcode[opc_next-1])->length;
	else{//invalid opcode
		puts("Opcode NOT Found! Press any key to exit."); 
		getch(); 
		exit(0);
	}
//OPERAND2
	token = strtok(NULL, "");
	printf("Operand2 : %s\n", token);
	if(token!=NULL) strcpy(operand2[ope2_next++], token);
}
void initMOT(){
	installInMOT("sr", 2);
	installInMOT("balr", 2);
	installInMOT("br", 2);
	installInMOT("l", 4);
	installInMOT("a", 4);
	installInMOT("st", 4);
	installInMOT("bct", 4);
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
		printf("--------------------------\n    %s", str);
		int breakFlag=0;
		if(strstr(str, "\t end") != NULL) breakFlag=1;
		tokenizeLine(str);
		getchar();
		if(breakFlag) break;
	}while(1  &&  !feof(fp) );
	deleteHash();
	return 0;
}

