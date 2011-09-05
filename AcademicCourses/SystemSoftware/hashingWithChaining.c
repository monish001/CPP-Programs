//filename: hashingWithChaining.c
//Hashing for keys: string(char*), value: int
#define HASHSIZE 40
#include<stdio.h>
struct nlist{
	struct nlist *next;   
	char* opcode;
	int length;
};

static struct nlist *hashtable[HASHSIZE]; /*pointer table*/ //Static means automatically initialises as NULL ptrs

unsigned int hash(char *p){//form hash value from string s
	int ans = strlen(p);
	for(; *p; p++)
		ans = ans *29 + *p;
	return ans%HASHSIZE;
}
struct nlist* lookup(char *s){
	struct nlist* np;
	for(np = hashtable[hash(s)]; np!=NULL; np = np->next)
		if(strcmp(s, np->opcode))
			return np; //found
	return NULL; //not found
}
char *strCopy(char *s){//allocates memory for the new string and return its pointer
	char *p = (char*)malloc(strlen(s));
	if(p!=NULL)
		strcpy(p, s);
	return p;
}
struct nlist* install(char *opcode_name, int len){//install: put (opcode_name, len) in hashtable[]
//return NULL for lack of memory
	struct nlist* np;
	
	if( (np=lookup(opcode_name)) ==NULL ){//not found
		np = (struct nlist*)malloc(sizeof(struct nlist));
		if(np==NULL)
			return NULL;
		if( (np->opcode = strCopy(opcode_name)) == NULL){ 
			free(np); 
			return NULL;
		}
		np->length = len;
		unsigned hashval = hash(opcode_name);
		np->next = hashtable[hashval];
		hashtable[hashval] = np;
	}else//found
		np->length = len;
	return np;
}
//main(){getch();}
