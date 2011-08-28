//filename: trie.c
//INCOMPLETE
#include<stdio.h>
#include<conio.h>
typedef struct node node;
struct node{
	char c;
	char word;//'y' or 'n'
	node *link[53];//a-z A-Z and space
};
node* createNode(){
	node* t= (node*)malloc(sizeof(node));
	int i;
	for(i=0; i<53; i++)	
		t->link[i]=NULL;
	t->word='n';
	return t;
}
int decode(char c){
	return (c >= 'a' && c <= 'z')?(c-'a'):((c >= 'A' && c <= 'Z')?(c+26-'A'):(52));
}
void appendInTrie(node *root[], char* s, int index){
	if(index >= strlen(s))
		return;
	int pos = decode(s[index]);
	if(root[pos] == NULL){
		root[pos] = createNode();
		root[pos]->c = s[index];
	}
	appendInTrie(root[pos]->link, s, ++index);
}
void makeTrie(node* start[], char* s[], int n){
    //int n = sizeof(s)/sizeof(char*);//number of names
	int i;
	for(i=0; i<n; i++){//for each string
		appendInTrie(start, s[i], 0);
		printf("%s added\n", s[i]);
	}
	printf("Total %d added.\n", n);
}
void triePrintOptions(node* start[], char str[]){//to read the prefix
	int len = strlen(str), i;
	node *t = start[decode(str[0])];
	//char printStr[100]={0};
	for(i=1; i<len; i++){
	//	printStr[i-1] = t->c;
		if(t==NULL) break;
		t = t->link[decode(str[i])];
	}
	//printStr[i-1] = t->c;

	int j, flag=0;
	for(j=0; j<53; j++)
		if(t == NULL){fputs("No Word With Such Prefix Exists", stdout); getch(); exit(0);}
		else if(t->link[j] != NULL){
			((t->link[j]->c)==' ')?(fputs("<space>", stdout)):(putchar(t->link[j]->c)); flag=1;}
	puts("");
//	if(flag==0)
//		fputs("No Word With this prefix Exists",stdout);
}
void takeInput(node* start[]){
	char str[100]={0}; int next_char=0;
	puts("Press ENTER to exit and any other key for input.");
	do{
		char c= getch();
		fputs(str, stdout); printf("%c:\n", c);
		if(c=='\r' || c=='\n') break;
		str[next_char++]=c;
		triePrintOptions(start, str);
	}while(1);
}
void freeTrie(node* tree){
	int i;
	for(i=0; i<53; i++){
	if(tree->link[i] != NULL)
		freeTrie(tree->link[i]);
	}
	free(tree);
}
int main(){
	int i; char *s[] = {"abcde", "Aashish Kumar","Aastha","Aastha Channa","Abhishek Bathla","Aditi Garg","Akshita Batra","Anubhav Saxena","ashish gupta","Ayush Bhatt","Bateesh","Brijesh Jyoti Upadhyay","Chahat Garg","Chunky Garg","Deepak Jindal","Deepak Narula","Degant Puri","Divya Suhag","Gaurav Jain","Gaurav Sharma","Ginni Gujral","Gurdeep Kaur","Gurjashan Singh Pannu","Heeral Dixit","Iqbal Singh","Jaskiran Kaur","Jatin Khanna","Jatinderpal singh","Jugal Kishore","Kartik Jhanwar","Kirandeep Kaur","Madhav Sharan","Manmeet Pahuja","Manoj Goyal","Meenal Goyal","Mohnish Modi","Monish Gupta","Neeraj Goyal","Nikhil Arora","Nitish Garg","Paahul Sikand","Paramjit Gupta","Parul Verma","Pavas Jindal","Pavas Jindal","Pooja","Prachi Goel","Priyank Bhatia","Pulkit Khurana","Rachit Gupta","Raghav Goel","Rajat Jindal","RAJEEV NAYAN","Ravi Maggon","Rimaljit Kaur","Rishabh Goyal","Rohit Bansal","Ruhani","Sahil Aggarwal","Sahil Singla","Sandeep Chugh","Sarabjot Singh","Shanuj Bansal","Sheetal Garg","Shilpa Singla","Siddharth Arora","Silky  Gambhir","Sulabh Rastogi","Sulabh Rastogi","Supriya singla","Surabhi Agarwal","Tanya Gupta","Tejinder Singh","Vikas Singla","Vipul Gupta","Vipul Singla","Vishal Sharma","Yash Singh"};
	//strArrayToLower(s);
	node* start[53];//={NULL};
	for(i=0; i<53; i++)	
		start[i]=NULL;

	makeTrie(start, s, 78);
	takeInput(start);
	
	for(i=0; i<53; i++)
	if(start[i] != NULL)
		freeTrie(start[i]);
	return 0;
}
