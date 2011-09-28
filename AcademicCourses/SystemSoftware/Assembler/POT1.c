//POT1.c
struct potNode{
	char opcode[20];
	int (*f)();
};
int dLength(const char c){
	switch(c){
		case 'C':
		case 'c':
			return 1;
		case 'H':
		case 'h':
			return 2;
		case 'F':
		case 'f':
			return 4;
		case 'D':
		case 'd':
			return 8;
	}
	return 0;
}
int dsLength(char * opcodeCharPtr, char* operand1CharPtr){//example DS 100F
	int size = atoi(operand1CharPtr)*dLength(operand1CharPtr[strlen(operand1CharPtr)-1]);
	if(size != 0)
		return size;
	printf("POT.c: Unexpected Argument to length. Press any key to exit.");
	fflush(stdin);
	getch();
	exit(0);
}
int dcLength(char * opcodeCharPtr, char* operand1CharPtr){//example: H'25,26,27'
	//printf("In DC_DLENGTH with opcode = %s and operand1 = %s\n", opcodeCharPtr, operand1CharPtr);
	int len = dLength(operand1CharPtr[0]);
	int totalLen = len;
	while(*operand1CharPtr){
		if(*operand1CharPtr == ',')
			totalLen += len;
		operand1CharPtr++;
	}
	return totalLen;
}
int LitAss(){
	
}
struct potNode potTable[] = {
	{"equ", NULL},
	{"start", NULL},
	{"using", NULL},
	{"drop", NULL},
	{"end", NULL/*&LitAss*/},
	{"ltorg", NULL/*&LitAss*/},
	{"dc", &dcLength},//Define Constant
	{"ds", &dsLength}//Define Storage
};

int FindInPOT(char *opcodeCharPtr, char* operand1CharPtr){
	int i, count = sizeof(potTable)/sizeof(struct potNode);
	for(i=0; i<count; i++){
		if(!strcmp(opcodeCharPtr, potTable[i].opcode))//OPCODE found
			return ( (potTable[i].f)!=NULL ) ? ( (*(potTable[i].f))(opcodeCharPtr, operand1CharPtr) ) : (0) ;
	}
    return -1;//not found
}

