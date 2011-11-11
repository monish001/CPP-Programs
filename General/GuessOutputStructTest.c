


//Snippet 1:
struct S1{
	int a;//4
	float b;//4
	char c;//1
};

//Snippet 2:
struct S2{
	float b;//4
	char c[5];//1
	int a;//4
};

//Snippet 3:
struct S3{
	char c;//1
	float b;//4
	int a;//4
};

int main(){
    printf("%u %u %u\n", sizeof(struct S1), sizeof(struct S2), sizeof(struct S3)); 
    getch(); 
    return 0; 
}
