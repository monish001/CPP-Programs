//POT1.c
struct potNode{
	char opcode[20];
	int (*f)();
};
int dLength(const char c){
	switch(c){
		case 'c':
			return 1;
		case 'h':
			return 2;
		case 'f':
			return 4;
		case 'd':
			return 8;
	}
	return 0;
}
int dsLength(const int lc, /*char * opcodeCharPtr,*/ char* operand1CharPtr){//example DS 100F
	int size = atoi(operand1CharPtr) * dLength(operand1CharPtr[strlen(operand1CharPtr)-1]);
	if(size != 0)
		return size;
	printf("POT.c: Unexpected Argument to length. Press any key to exit.");
	fflush(stdin);
	getch();
	exit(0);
}
int dcLength(const int lc, /*char * opcodeCharPtr,*/ char* operand1CharPtr){//example: h'25,26,27'
	//printf("In DC_DLENGTH with operand1 = %s\n", operand1CharPtr);
	int len = dLength(operand1CharPtr[0]);
	int totalLen = len;
	while(*operand1CharPtr){
		if(*operand1CharPtr == ',')
			totalLen += len;
		operand1CharPtr++;
	}
	return totalLen;
}
extern int litStackTop;

int LitAss(int lcInt, /*char * opcodeCharPtr,*/ char* operand1CharPtr){
	int initLc = lcInt;
	if(lcInt%8 != 0)
		lcInt += 8-lcInt%8;
	while(litStackTop!=-1){
		struct litRecord* np = LitStack[litStackTop];
		LitStack[litStackTop--] = NULL;
		np->value = lcInt;
		np->length = dLength(*(np->name));
		printTimeToLog(); fprintf(logFile, "Literal %s allocated %d bytes of memory at LC=%d.\n", np->name, np->length, np->value);
		lcInt += np->length;
		np->reloc = REL;
	}
	return lcInt-initLc;
}
struct potNode potTable[] = {
	{"equ", NULL},
	{"start", NULL},
	{"using", NULL},
	{"drop", NULL},
	{"end", &LitAss},
	{"ltorg", &LitAss},
	{"dc", &dcLength},//Define Constant
	{"ds", &dsLength}//Define Storage
};

int FindInPOT(const int lcInt, char *opcodeCharPtr, char* operand1CharPtr){
	int i, count = sizeof(potTable)/sizeof(struct potNode);
	for(i=0; i<count; i++){
		if(!strcmp(opcodeCharPtr, potTable[i].opcode)){//OPCODE found
			printTimeToLog();
			fprintf(logFile, "Op-Code %s found at LC=%d with Operand1 as %s\n", opcodeCharPtr, lcInt, operand1CharPtr);
			return ( (potTable[i].f)!=NULL ) ? ( (*(potTable[i].f))(lcInt, /*opcodeCharPtr,*/ operand1CharPtr) ) : (0) ;
		}
	}
    return -1;//not found
}

