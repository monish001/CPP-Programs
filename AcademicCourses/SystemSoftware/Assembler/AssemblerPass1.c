#include "hashingWithChainingMOT.c"
#include "SymbolTable.c"
#include "LiteralTable.c"
#include "POT1.c"
#include "BaseTable.c"
#define MAXLINE 200

void completeOperand(char* p1){
	char *p2 = (char*)strtok(NULL, "\n");
	p1[strlen(p1)] = ',';
}
void tokenizeLine(char *str, FILE *fp){
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
		addLiteral(operand2+1);//Add literal to Literal Table. Example =f'31'
	}


	//Print to PassOneOutput.tmp
	fprintf(fp, "% 3d %s %s %s %s\n", lcInt, (strlen(label)==0)?("\t"):(label), opcode, (strlen(operand1)==0)?("\t"):(operand1), (strlen(operand2)==0)?("\t"):(operand2));

//LC to add storage space for this opcode
struct nlist* np;
	if((curOpcodeLength = FindInPOT(lcInt, opcode ,operand1)) != -1){
	//found in POT
	//add Symbol to ST
		if(strlen(label)>0){
			if(strcmp(opcode, "equ")==0){//Example: 1.setup	equ		*	2.database	equ		13   3. A equ B//Forward referencing can be implemented using a stack
			//1 is Relocatable but 2. is abs
				int value = 1;//EVAL(operand1, lcInt);
				STSTO(label, value, 1, (enum relocation)((strchr(operand1, '*')==NULL)?(ABS):(REL))); //if * is not present then Absolute
			}else if(strcmp(opcode, "ds")==0){//eg. ds 100f
				STSTO(label, lcInt, curOpcodeLength/atoi(operand1), (enum relocation)REL);
			}else if(strcmp(opcode, "dc")==0){//eg. dc h'25,26,27'
				STSTO(label, lcInt, dLength(operand1[0]), (enum relocation)REL);
			}else{
				STSTO(label, lcInt, ((curOpcodeLength==0)?1:curOpcodeLength), (enum relocation)REL); 
			}
		}
	}else if((np=lookupInMOT(opcode)) != NULL){//find in MOT
		curOpcodeLength = np->length;
		if(strlen(label)>0){
			STSTO(label, lcInt, ((curOpcodeLength==0)?1:curOpcodeLength), (enum relocation)REL);
		}
	}else{//invalid opcode
		puts("Opcode NOT Found! Press any key to exit."); 
		getch(); 
		exit(0);
	}

	lcInt += curOpcodeLength;
}


