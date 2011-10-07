//filename: hashingWithChainingMOT.c
//MOT: Machine OperationCode Table as in IBM 360/370
//Hashing for keys: string(char*), value: int
#define MOT_HASHSIZE 41 //prime number
#include<stdio.h>
struct nlist{
	struct nlist *next;   
	char* opcode;
	int length;
};

static struct nlist *motTable[MOT_HASHSIZE]; /*pointer table*/ //Static means automatically initialises as NULL ptrs

unsigned int hashMOT(char *p){//form hash value from string s
	int ans = strlen(p);
	for(; *p; p++)
		ans = ans *29 + *p;
	return ans%MOT_HASHSIZE;
}
struct nlist* lookupInMOT(char *s){
	struct nlist* np;
	for(np = motTable[hashMOT(s)]; np!=NULL; np = np->next)
		if(!strcmp(s, np->opcode)){
			printTimeToLog(); 
			fprintf(logFile, "Op-Code %s found having length=%d\n", np->opcode, np->length);
			return np; //found
		}
	return NULL; //not found
}
char *strCopy(char const *s){//allocates memory for the new string and return its pointer
	char *p = (char*)malloc(strlen(s));
	if(p!=NULL)
		strcpy(p, s);
	return p;
}
struct nlist* installInMOT(char *opcode_name, int len){//install: put (opcode_name, len) in motTable[]
//return NULL for lack of memory
	struct nlist* np;
	
	if( (np=lookupInMOT(opcode_name)) ==NULL ){//not found
		np = (struct nlist*)malloc(sizeof(struct nlist));
		if(np==NULL)
			return NULL;
		if( (np->opcode = strCopy(opcode_name)) == NULL){ 
			free(np); 
			return NULL;
		}
		np->length = len;
		unsigned hashval = hashMOT(opcode_name);
		np->next = motTable[hashval];
		motTable[hashval] = np;
	}else//found
		np->length = len;

	return np;
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

void deleteMOT(){
	int i;
	for(i=0; i<MOT_HASHSIZE; i++){
		struct nlist* np = motTable[i];
		motTable[i] = NULL;
		while(np!=NULL){
			struct nlist* tmp = np;
			np = np->next;
			free(tmp);
		}
	}
}

//int main(){return 0;}
