//It is assumed that the input program is a c language program which is already compile-error free.
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;

//asks the user to input filename and
//returns a pointer to a new allocated memory where the contents of the file are copied.
char* getFileContents(){
	char filename[255];
	cout<<"Enter the file name.. ";
	cin>>filename;
	cout<<"---------------Input program is "<<filename<<": ---------------\n";
	ifstream in(filename);
	in.seekg(0L, ios::end);
	int count = in.tellg();
	in.clear();
	in.seekg(0L, ios::beg);
	char *str = (char*)malloc(count+1);
	for(int i=0; i<(count+1) && (in) ; i++){
		in.get(str[i]);
	}
	in.close();
	return str;
}

int search(const char* str, const char* substr){//non-overlapping 'substr's
	int count =0;
	str = strstr(str, substr);
	while(str != NULL){
		cout<<str[0]<<str[1]<<str[2]<<str[3]<<str[4]<<str[5]<<str[6]<<str[7]<<str[8]<<"\n";
		count++;
		str = strstr(++str, substr);
	}
	return count;
}

//deletes comments and other things
void neatNTidy(char* &str){
	char *start;
	char *end;
	while(1){//remove /*abc*/
		start = NULL;
		end = NULL;
		start = strstr(str, "/*");
		if(start == NULL)
			break;
		//cout<<"\n"<<start[0]<<start[1]<<start[2]<<start[3]<<start[4]<<start[5]<<start[6]<<start[7]<<start[8];
		end = strstr(str, "*/");
		//cout<<"\n"<<end[0]<<end[1]<<end[2]<<end[3]<<end[4]<<end[5]<<end[6]<<end[7]<<end[8];
		end++; end++;
		*start='\0';
		strcat(str, end);
	}
	while(1){//remove \"
		start = strstr(str, "\\\"");
		if(start == NULL)
			break;
		start++;
		*start = ' ';
	}
	while(1){//remove "abc"
		start = NULL;
		end = NULL;
		start = strstr(str, "\"");
		if(start == NULL)
			break;
		//cout<<"\n"<<start[0]<<start[1]<<start[2]<<start[3]<<start[4]<<start[5]<<start[6]<<start[7]<<start[8];
		*start='A';
		end = strstr(str, "\"");
		//cout<<"\n"<<end[0]<<end[1]<<end[2]<<end[3]<<end[4]<<end[5]<<end[6]<<end[7]<<end[8];
		end++;
		*start='\0';
		strcat(str, end);
	}
	while(1){//remove //abc
		start = NULL;
		end = NULL;
		start = strstr(str, "//");
		if(start == NULL)
			break;
		//cout<<"\n"<<start[0]<<start[1]<<start[2]<<start[3]<<start[4]<<start[5]<<start[6]<<start[7]<<start[8];
		end = start+2;
		while(*end != '\n')
			end++;
		//cout<<"\n"<<end[0]<<end[1]<<end[2]<<end[3]<<end[4]<<end[5]<<end[6]<<end[7]<<end[8];
		end++;
		*start='\0';
		strcat(str, end);
	}
}

int main(){// ArrowKeys.c
	char *str = getFileContents();
	cout<<str<<"\n";
	neatNTidy(str);
	cout<<"------------------Modified program is :------------------------\n"<<str<<"\n";
	int count=0;
	cout<<"----------Keywords are found at following places: ----------\n";
	count += search(str, "if(");
	count += search(str, "if (");
	count += search(str, "for(");
	count += search(str, "for (");
	count += search(str, "while(");
	count += search(str, "while (");
	count += search(str, " && ");
	cout<<"Cyclomatic Complexity is "<<count<<"\n";
	return 0;
}