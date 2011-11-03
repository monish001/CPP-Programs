
#define ST_HASHSIZE 41 //prime number
enum relocation{NIL, ABS, REL};
struct symbolList{
	struct symbolList *next;   
	char* symName;
	short length;//datatype length
	int lcValue;
	enum relocation reloc;
};

static struct symbolList *symbolTable[ST_HASHSIZE]; /*pointer table*/ //Static means automatically initialises as NULL ptrs


/* 
 * prints the ST to fp
 */
void printST(FILE* fp){
	int i=0;
	fprintf(fp, "Symbol Length Value(LC) Relocation\n");
	for(i=0; i<ST_HASHSIZE; i++){
		struct symbolList * np = symbolTable[i];
		while(np!=NULL){
			fprintf(fp, "%s\t%d\t%d\t%c\n", np->symName, np->length, np->lcValue, ((np->reloc == ABS)?'A':'R'));
			np=np->next;
		}
	}
}

unsigned int hashST(char const *p){//form hash value from string s
	int ans = strlen(p);
	for(; *p; p++)
		ans = ans *29 + *p;
	return ans%ST_HASHSIZE;
}
struct symbolList* lookupInST(char const *const s){
	struct symbolList* np;
	for(np = symbolTable[hashST(s)]; np!=NULL; np = np->next)
		if(!strcmp(s, np->symName))
			return np; //found
	return NULL; //not found
}
char *strCopy(char const *const s);//allocates memory for the new string and return its pointer

/*
 *Stores symbol with LC value
 */
struct symbolList* STSTO(char const* const symbolNameCharPtr, const int lcInt, const int len, enum relocation aRelocation){//install: put (symbolNameCharPtr, lcInt) in symbolTable[]
//return NULL for lack of memory
	struct symbolList* np;
	
	if( (np=lookupInST(symbolNameCharPtr)) ==NULL ){//not found
		np = (struct symbolList*)malloc(sizeof(struct symbolList));
		if(np==NULL)
			return NULL;
		if( (np->symName = strCopy(symbolNameCharPtr)) == NULL){ 
			free(np); 
			return NULL;
		}
		unsigned hashval = hashST(symbolNameCharPtr);
		np->next = symbolTable[hashval];
		symbolTable[hashval] = np;
	}
	np->lcValue = lcInt;
	np->length=len;//datatype length
	np->reloc=aRelocation;
	printTimeToLog(); fprintf(logFile, "Symbol %s added to ST with LC = %d, length=%d, A/R=%c\n", np->symName, np->lcValue, np->length, ((np->reloc==REL)?('R'):('A')));
	return np;
}
void deleteST(){
	int i;
	for(i=0; i<ST_HASHSIZE; i++){
		struct symbolList* np = symbolTable[i];
		symbolTable[i] = NULL;
		while(np!=NULL){
			struct symbolList* tmp = np;
			np = np->next;
			free(tmp);
		}
	}
}
/*
 * Evaluates an arithematic expression assuming * has value lcInt
 */
int EVAL(char *operand1, int lcInt){
	//incomplete
    while(strchr(operand1, '*')!=NULL){
		;//substitute();
	}
	
}
//int main(){return 0;}
