//filename: LiteralTable.c
#define LIT_HASHSIZE 41
/*
 * Finds hash value corresponding to char* p
 */
unsigned int hashLit(char const *ptr){//form hash value from string s
	int ans = strlen(ptr);
	for(; *ptr; ptr++)
		ans = ans *29 + *ptr;
	return ans%LIT_HASHSIZE;
}

enum relocation;
struct litRecord{
	char* name;//Name of the literal
	short length;//datatype length
	int value;//LC where memory is allocated
	enum relocation reloc;
	struct litRecord *next;
};
static struct litRecord *litHashTable[LIT_HASHSIZE]; /*pointer table*/ //Static means automatically initialises as NULL ptrs
struct litRecord* lookupInLit(const char * const key){
	struct litRecord* np;
	for(np = litHashTable[hashLit(key)]; np!=NULL; np = np->next)
		if(!strcmp(key, np->name))
			return np; //found
	return NULL; //not found
}

char *strCreate(const char *const s){//allocates memory for the new string and return its pointer
	char *p = (char*)malloc(strlen(s));
	if(p!=NULL)
		strcpy(p, s);
	return p;
}
struct litRecord* installInLit(const char* const literalName, short len, int val, enum relocation aReloc){//install: put litRecord in litHashTable[] if not alresdy there else update.
//return NULL for lack of memory
	struct litRecord* np;
	
	if( (np=lookupInLit(literalName)) == NULL ){//not found
		np = (struct litRecord*)malloc(sizeof(struct litRecord));
		if(np==NULL)
			return NULL;
		if( (np->name = strCreate(literalName)) == NULL){ 
			free(np);
			return NULL;
		}
		np->length = len;
		np->value = val;
		np->reloc = aReloc;
		unsigned hashval = hashLit(literalName);
		np->next = litHashTable[hashval];
		litHashTable[hashval] = np;
	}else{//found
		np->length = len;
		np->value = val;
		np->reloc = aReloc;
	}
	return np;
}

void addLiteral(const char *const litCharPtr){
	//puts(litCharPtr);
	installInLit(litCharPtr, -1, -1, NIL);
}
/*void LitAss(){

}*/
void deleteLT(){
	int i;
	for(i=0; i<LIT_HASHSIZE; i++){
		struct litRecord* np = litHashTable[i];
		litHashTable[i] = NULL;
		while(np!=NULL){
			struct litRecord* tmp = np;
			np = np->next;
			free(tmp);
		}
	}
}
//int main(){return 0;}
