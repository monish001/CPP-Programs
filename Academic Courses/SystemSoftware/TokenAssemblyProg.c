//Assumptions: 
//1. When there is no label, use tab followed by space.
//2. Append an empty line at the end of the program.

#define MAXLINE 300
#include<stdio.h>

int lab_next=0, opc_next=0, ope1_next=0, ope2_next=0;

char label[MAXLINE][MAXLINE];
char opcode[MAXLINE][MAXLINE];
char operand1[MAXLINE][MAXLINE];
char operand2[MAXLINE][MAXLINE];

void competeOperand(char* p1){
	char *p2 = strtok(NULL, "\'");
	strcat(p1, p2);
	strcat(p1, "\'");
}
void processLine(char *str){
     
	char* token = strtok(str, " ");
	
    if(token!=NULL){
	//	if(token[0] == '\t') token[0] = '\0';   
		
        strcpy(label[lab_next++], token);}
	printf("Label : %s\n", label[lab_next-1]);

	token = strtok(NULL, " "); 
	
	if(token!=NULL) strcpy(opcode[opc_next++], token);
	
	printf("Opcode : %s\n", token);
	
	token = strtok(NULL, ",");
	if(token!=NULL){
		char *c = strchr(token, '\'');
		if(c!=NULL) competeOperand(token);//Example: f'1,3,3,3,3,4,5,9,0'
		strcpy(operand1[ope1_next++], token);
	} 
	printf("Operand1 : %s\n", token);
	
	token = strtok(NULL, "");
	printf("Operand2 : %s\n", token);
	if(token!=NULL) strcpy(operand2[ope2_next++], token);
}

int main(){

	FILE *fp = fopen("Prog.asm", "r");

	if(fp == NULL)
          { puts("FILE NOT FOUND"); getchar(); exit(0); }
	
	char str[MAXLINE] = {0};
	//fscanf(fp, "%[^\n]s", str);
	fgets(str, MAXLINE-1, fp);
	//while(strlen(str)){
	while(!feof(fp)){
		printf("--------------------------\n%s", str);
		processLine(str);
		memset(str, 0, MAXLINE);
		fgets(str, MAXLINE-1, fp);
		getchar();
	}
//	getchar();
	return 0;
}
