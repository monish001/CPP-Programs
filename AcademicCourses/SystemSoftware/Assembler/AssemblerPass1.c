//Assumptions: 
//1. When there is no label, use tab followed by space.

//PASS 1: For each line
//			add symbol (along with LC value) into ST
//			check in POT if pseudo-op (and correcsponing action) else check in MOT
//			add literal into LT and it's value(LC) when LTORG/END is found

#define MAXLINE 200
#include <stdio.h>
#include "hashingWithChainingMOT.c"
#include "POT1.c"
#include "BaseTable.c"
#include "SymbolTable.c"
#include "LiteralTable.c"
#include "AssemblerPass2.c"
//FILE *log = fopen("assembler.log", "w");

void completeOperand(char* p1){
	char *p2 = (char*)strtok(NULL, "\n");
	p1[strlen(p1)] = ',';
}
void tokenizeLine(char *str, FILE * fp){
	static int lcInt;
	int curOpcodeLength=0;
	char label[MAXLINE/4]={0};
	char opcode[MAXLINE/4]={0};
	char operand1[MAXLINE/4]={0};
	char operand2[MAXLINE/4]={0};
     
//Symbol
	char* token = (char*)strtok(str, " ");
	if(token[0] == '\t') 
		token=NULL;   
    if(token!=NULL){
        strcpy(label, token);
	}
//Opcode
	token = (char*)strtok(NULL, " \n"); 
	if(token!=NULL){
		strcpy(opcode, token);
		
	}
//OPERAND1
	token = (char*)strtok(NULL, ",\n");
	if(token!=NULL){
		char *c = strchr(token, '\'');
		if(c!=NULL)
	        completeOperand(token);//Example: f'1,3,3,3,3,4,5,9,0'
		strcpy(operand1, token);
	} 
//OPERAND2
	token = (char*)strtok(NULL, "\n");
	if(token!=NULL){
		strcpy(operand2, token);
		if(operand2[0] == '=')
		addLiteral(operand2+1);//Add literal to Literal Table
	}


	//Print to PassOneOutput.tmp
	fprintf(fp, "%d %s %s %s\n", lcInt, (label==NULL)?("NoLabel"):(label), opcode, (operand1==NULL)?("\t"):(operand1), (operand2==NULL)?("\t"):(operand2));

//LC to add storage space for this opcode
	if(FindInPOT(opcode ,operand1) != -1)//found in POT
		curOpcodeLength = FindInPOT(opcode ,operand1);// puts("foud in POT");}
	else if(lookupInMOT(opcode) != NULL)//find in MOT
		curOpcodeLength = lookupInMOT(opcode)->length;
	else{//invalid opcode
		puts("Opcode NOT Found! Press any key to exit."); 
		getch(); 
		exit(0);
	}
//add Symbol to ST
	if(strcmp(label, "equ")==0){//Example: 1.setup	equ		*			2.database	equ		13 
	//1 is Relocatable but 2. is abs
		int value = 1;//EVAL(operand1, lcInt);
		STSTO(label, value, 1, (enum relocation)((strchr(operand1, '*')==NULL)?(ABS):(RELOC))); 
	}
	else if(strlen(label)>0){
		STSTO(label, lcInt, ((curOpcodeLength==0)?1:curOpcodeLength), (enum relocation)RELOC); }

	lcInt += curOpcodeLength;
}

int main(){

	FILE *fp = fopen("Prog.asm", "r");
	FILE *out = fopen("PassOneOutput.tmp", "w+");
	fprintf(fp, " LC Label Opcode Operand1 Operand2\n");
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
		tokenizeLine(str, out);
		getchar();
		if(breakFlag) break;
	}while(1  &&  !feof(fp) );
	//Pass2(out);
	deleteMOT();
	deleteST();
	deleteLT();
	return 0;
}

