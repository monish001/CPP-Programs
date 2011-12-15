/*
space _ |

    _  _     _  _  _  _  _ 
  | _| _||_||_ |_   ||_||_|
  ||_  _|  | _||_|  ||_| _|
 _  _  _  _  _  _  _  _  _ 
|_||_||_||_||_||_||_||_|  |
|_||_||_||_||_||_||_||_|  |
    _  _  _  _  _  _  _  _ 
|_||_|| || ||_   |  |  ||_|
  | _||_||_||_|  |  |  ||_|

*/

#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<map>
using namespace std;

char decode(char* w1, char* w2, char* w3){
	if(	!strncmp(w1, " _ ", 3) && 
		!strncmp(w2, "| |", 3) && 
		!strncmp(w3, "|_|", 3))
		return '0';
	if(	!strncmp(w1, "   ", 3) && 
		!strncmp(w2, "  |", 3) && 
		!strncmp(w3, "  |", 3))
		return '1';
	if(	!strncmp(w1, " _ ", 3) && 
		!strncmp(w2, " _|", 3) && 
		!strncmp(w3, "|_ ", 3))
		return '2';
	if(	!strncmp(w1, " _ ", 3) && 
		!strncmp(w2, " _|", 3) && 
		!strncmp(w3, " _|", 3))
		return '3';
	if(	!strncmp(w1, "   ", 3) && 
		!strncmp(w2, "|_|", 3) && 
		!strncmp(w3, "  |", 3))
		return '4';
	if(	!strncmp(w1, " _ ", 3) && 
		!strncmp(w2, "|_ ", 3) && 
		!strncmp(w3, " _|", 3))
		return '5';
	if(	!strncmp(w1, " _ ", 3) && 
		!strncmp(w2, "|_ ", 3) && 
		!strncmp(w3, "|_|", 3))
		return '6';
	if(	!strncmp(w1, " _ ", 3) && 
		!strncmp(w2, "  |", 3) && 
		!strncmp(w3, "  |", 3))
		return '7';
	if(	!strncmp(w1, " _ ", 3) && 
		!strncmp(w2, "|_|", 3) && 
		!strncmp(w3, "|_|", 3))
		return '8';
	if(	!strncmp(w1, " _ ", 3) && 
		!strncmp(w2, "|_|", 3) && 
		!strncmp(w3, " _|", 3))
		return '9';
return 'E';
}

long decrypt(char* s, map<char, string>& mp, int& count){
long first;
	for(int i=0; i<9; i++){
		const char c=s[i];
		for(int j=0; j<mp[c].size(); j++){
			s[i] = mp[c][j];
			if(atol(s)%11 == 0L){
				count++;
				if(count == 1)
					first = atol(s);
			}
		}
		s[i] = c;
	}
return first;
}
int main(){
	char s[10]={0};
  filebuf fb;
  fb.open ("input.txt",ios::in);
  istream cin(&fb);

	ofstream cout("output.txt");
	char* in[3];
	in[0] = new char[27];
	in[1] = new char[27];
	in[2] = new char[27];
	string tmp;
	getline(cin, tmp);	strcpy(in[0], tmp.c_str());
	getline(cin, tmp);	strcpy(in[1], tmp.c_str());
	getline(cin, tmp);	strcpy(in[2], tmp.c_str());
	for(int i=0; i<27; i+=3){
		s[i/3] = decode(in[0]+i, in[1]+i, in[2]+i);
	}
	s[9]='\0';
	int n = atol(s);
	if(n%11 == 0)
        cout<<n<<endl;
	else{
		map<char, string> mp;
		mp['1'] = "7";
		mp['3'] = "9";
		mp['5'] = "69";
		mp['6'] = "58";
		mp['7'] = "1";
		mp['8'] = "69";
		mp['9'] = "853";
		int solutions=0;
	    int first = decrypt(s, mp, solutions);
		
		if(solutions==0)
			cout<<"failure";
		else if(solutions>1)
			cout<<"ambiguous";
		else
			cout<<first;
	}
	delete[] in[0];
	delete[] in[1];
	delete[] in[2];
  fb.close();
  cout.close();
	return 0;
}
