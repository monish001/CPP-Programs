#define NUM 10
#include<stdio.h>
struct record{
       int roll;
       char name[10];
       float cg;
}data[NUM];
int hashFunction(int r){//Input: rollno. Output: index in array
	return r%NUM;
}
void search(){

}
void add(){
	int r, hash;
	puts("Enter roll no..");
	scanf("%d", &r);
	
	hash = hashFunction(r);
	if(data[hash].name[0] != '\0'){//if index hash busy, choose another. If not available, put NUM in hash;
	
	}
	if(hash != NUM){
		data[hash].roll=r;
		puts("Enter name..");	gets(data[hash].name); data[hash].name[9]='\0';
		puts("Enter CG.. "); scanf("%f", &(data[hash].cg));
	}else{
		printf("Cannot Save. No more memory available\n");
	}
}
int main(){
    int i=0;
    char choice;
    for(i=0; i<NUM; i++)
             data[i].name[0]= '\0';
    do{
        fputs("Enter choose:\n1 to add record\n2 to delete\n3 to read records\n0 to exit\n", stdout);
        fflush(stdin);
        choice = fgetc(stdin)-'0';
        switch(choice){
			case 1:
			add();
			break;
			case 2:
			//del();
			break;
			case 3:
			//read();
			break;
        }
    }while(choice);
    return 0, getchar();
}