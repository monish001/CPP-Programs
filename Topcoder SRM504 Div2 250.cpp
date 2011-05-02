#include<vector>
using namespace std;
class ComparerInator{
public:
	int makeProgram(vector<int> A, vector<int> B, vector<int> wanted){
		int n = A.size();
		int flag=1;
		for(int i=0; i<n; i++){
			if(wanted[i] != A[i]){
				flag=2;
				break;
			}
		}
		if(flag == 1)
			return 1;

		for(int i=0; i<n; i++){
			if(wanted[i] != B[i]){
				flag=3;
				break;
			}
		}
		if(flag == 2)
			return 1;

		for(int i=0; i<n; i++){
			if(wanted[i] != (A[i]<B[i] ? A[i] : B[i])){
				flag=4;
				break;
			}
		}
		if(flag == 3)
			return 7;

		for(int i=0; i<n; i++){
			if(wanted[i] != (A[i]<B[i] ? B[i] : A[i])){
				flag=-1;
				break;
			}
		}
		if(flag == 4)
			return 7;
		return -1;
	}
};
