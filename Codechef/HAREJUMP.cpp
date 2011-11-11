//https://ideone.com/dgAKs
/*
Chefs new Pet
Problem code: HAREJUMP
	
ALL SUBMISSIONS
All submissions for this problem are available.

The chef got a new rabbit and he is going to train him so that he can perform for him whenever he needs entertainment. The chef teaches k types of jumps to the rabbit. Each jump has definite length L units. The rabbit does not have any brains he will use any type of jump he feels like at any point of time. He is placed on a very long mat and starts at 0 unit. The chef wants to know in how many ways he can perform his jumps and cover exactly N units of distance.
Input

The first line contains the number of the test cases T(<=100). Each test case consists of 2 lines. The first line defines the distance N (1<=N<=10^18) which tells us the number of units the chef wants the rabbit to cover. The next line contains k the number of jumps which are taught to the rabbit, k (k<=15) integers follow in the same line each denoting distinct distance L (L<=15) units which can be jumped by the rabbit.
Output

Print T integers each denoting the number of ways the rabbit can perform jumps of N units of distance. Print the remainder obtained on dividing the answer by 1000000007 if the answer is greater than or equal to 1000000007.
Example

Input:
3
10
1 1
13
3 1 2 8
15
5 1 2 3 4 5



Output:
1
415
13624
Date:	2011-08-31
Time limit:	7
s
Source limit:	50000
Languages:	TCL PERL6 CLOJ GO PYTH 3.1.2 F# C C99 strict C++ 4.0.0-8 C++ 4.3.2 PAS gpc PAS fpc JAVA NICE JAR C# NEM ST ASM D FORT ADA BASH PERL PYTH RUBY LUA ICON PIKE PHP SCM guile SCM qobi LISP sbcl LISP clisp SCALA HASK ERL CAML CLPS PRLG WSPC BF ICK TEXT JS
*/
#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
int main(){
    
    ifstream cin("HAREJUMP_IN.TXT");
    ofstream cout("HAREJUMP_OUT.TXT");
    
	const int MOD = 1000000007;
	int t;
	cin>>t;
	while(t--){
		long long int n;
		int k;
		cin>>n>>k;
		int *l = new int[k];
		for(int i=0; i<k; i++){
			cin>>l[i];
		}

    
		int ans[16]; ans[15]=1;
		time_t initSecs = time(NULL);
		for(long long int i=1; i<=n; i++){//for each n
			int count=0;
			//if(count%1000==0)
            //cout<<"forLoop: "<<i<<" Seconds: "<<time(NULL)-initSecs<<endl;
			for(int j=0; j<k; j++){//for each jump
				if(i-l[j]<0) continue;
                int tmp = ans[(i-l[j])%15? (i-l[j])%15 :15];
                count = (count+tmp)%MOD;
                //cout<<j<<" ";
			}
			cout<<i<<" "<<count<<endl;
			ans[i%15?i%15:15] = count;
		}
		cout<<ans[n%15?n%15:15]<<"******************************\n";
	}
//	getchar();
	return 0;
}
