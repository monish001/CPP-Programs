//DUTCH NATIONAL FLAG PROBLEM
//Running link: http://www.ideone.com/SXAl7

#include<iostream>
using namespace std;
class DNF{
public:
	static void solveDNF2Color(string& in){
		//cout<<(void*)&in[0]<<" "<<(void *)(in.c_str())<<endl;
		int i=0, j=in.size()-1;
		char pivot = '0';
		while(i<=j){
			if(in[i] <= pivot)
			i++;
			else{
				char tmp = in[i];
				in[i] = in[j];
				in[j] = tmp;
				j--;
			}
		}
	}
	static void solveDNF3Color(string& in){
		int l=0, m=0, h=in.size()-1;
		char pivot = '1';
		while(m<=h){
//			cout<<l<<" "<<m<<" "<<h<<" "<<in<<endl;
			if(in[m] < pivot){
				char tmp = in[l];
				in[l] = in[m];
				in[m] = tmp;
				l++; m++;
			}else if(in[m]>pivot){
				char tmp = in[m];
				in[m] = in[h];
				in[h] = tmp;
				h--;
			}else
				m++;
		}
	}
	static void solveDNF4Color(string& in){
	}
};

int main(){
	int count;
	cin>>count;
	while(count--){
		string in;
		cin>>in;
		DNF::solveDNF2Color(in);
		cout<<in<<endl;
	}

	cin>>count;
	while(count--){
		string in;
		cin>>in;
		DNF::solveDNF3Color(in);
		cout<<in<<endl;
	}

	cin>>count;
	while(count--){
		string in;
		cin>>in;
		DNF::solveDNF4Color(in);
		cout<<in<<endl;
	}
	return 0;
}