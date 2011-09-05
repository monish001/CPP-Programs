//Assumptions: 
//1. When there is no label, use tab followed by space.
//2. Append an empty line at the end of the program.

#define MAXLINE 300
#include<stdio.h>
#include"hashingWithChaining.c"

void completeOperand(char* p1){
	char *p2 = strtok(NULL, "\n");
	p1[strlen(p1)] = ',';
}
void tokenizeLine(char *str){
	int lab_next=0, opc_next=0, ope1_next=0, ope2_next=0;

	char label[MAXLINE][MAXLINE];
	char opcode[MAXLINE][MAXLINE];
	char operand1[MAXLINE][MAXLINE];
	char operand2[MAXLINE][MAXLINE];
     
	char* token = strtok(str, " ");
	
	if(token[0] == '\t') 
		token=NULL;   
    if(token!=NULL){
        strcpy(label[lab_next++], token);}
	printf("Label : %s\n", token);

	token = strtok(NULL, " \n"); 
	
	if(token!=NULL) strcpy(opcode[opc_next++], token);
	
	printf("Opcode : %s\n", token);
	
	token = strtok(NULL, ",\n");
	if(token!=NULL){
		char *c = strchr(token, '\'');
		if(c!=NULL)
	        completeOperand(token);//Example: f'1,3,3,3,3,4,5,9,0'
		strcpy(operand1[ope1_next++], token);
	} 
	printf("Operand1 : %s\n", token);
	
	token = strtok(NULL, "");
	printf("Operand2 : %s\n", token);
	if(token!=NULL) strcpy(operand2[ope2_next++], token);
}
void registerOpcodes(){
	struct node{
		char name[20];
		int len;
	};
	struct node opcode[] = {{"start", 0},{"balr", 0},{"using" ,0},{"sr", 5},{"l", 7},{"a", 4}, {"st", 5}, {"bct", 5}, {"br", 5}, {"dc", 5}, {"ltorg", 5}, {"end", 5} };
	int i, n = sizeof(opcode)/sizeof(struct node);
	for(i=0; i<n; i++)
		install(opcode[i].name, opcode[i].len);
}
int main(){

	FILE *fp = fopen("Prog.asm", "r");

	if(fp == NULL)
          { puts("FILE NOT FOUND"); getchar(); exit(0); }
	
	registerOpcodes();
	
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
	}while(1/*!feof(fp)*/);
//	getchar();
	return 0;
}
