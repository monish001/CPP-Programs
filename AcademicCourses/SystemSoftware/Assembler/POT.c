struct potNode{
	char opcode[20];
	int (*f)();
};
int lengthOfPCode();

int DS_DLENGTH(char * opcodeCharPtr, char* operand1CharPtr){
	//Incomplete yet
	return 100;
}
int DC_DLENGTH(char * opcodeCharPtr, char* operand1CharPtr){
	//printf("In DC_DLENGTH with opcode = %s and operand1 = %s\n", opcodeCharPtr, operand1CharPtr);
	//Incomplete yet
	return 100;
}
struct potNode potTable[] = {
	{"equ", NULL},
	{"start", NULL},
	{"using", NULL},
	{"end", NULL},
	{"ltorg", NULL},
	{"dc", &DC_DLENGTH},
	{"ds", &DS_DLENGTH}
};
static int count = -1;

int FindInPOT(char *opcodeCharPtr, char* operand1CharPtr){
	int i;
	if(count == -1)
		count = sizeof(potTable)/sizeof(struct potNode);
	for(i=0; i<count; i++){
		if(!strcmp(opcodeCharPtr, potTable[i].opcode))//OPCODE found
			return ( (potTable[i].f)!=NULL ) ? ( (*(potTable[i].f))() ) : (0) ;
	}
    return -1;//not found
}

