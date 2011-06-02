//NOT COMPLETE. LOGIC IS WRONG
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
struct pt{
	int x, y;
};
class CandyShop{
	public: int countProbablePlaces(vector <int> X, vector <int> Y, vector <int> R){
		vector<int>  s;
		vector<int>::iterator it;
		int n = X.size();
		for(int x,y,i=0; i<n; i++){
			vector<int> tem; X[i] += 200, Y[i] += 200;
			x= R[i] + X[i], y = Y[i];
			do{//1
				tem.push_back(x<<10 & y);
				x--; y++;
			}while(x != X[i]);
			do{//2
				tem.push_back(x<<10 & y);
				x--; y--;
			}while(y != Y[i]);
			do{//3
				tem.push_back(x<<10 & y);
				x++; y--;
			}while(x != X[i]);
			do{//4
				tem.push_back(x<<10 & y);
				x++; y++;
			}while(y != Y[i]);
			sort(tem.begin(), tem.end());
			it = set_intersection(s.begin(), s.end(), tem.begin(), tem.end(), s.begin());
		}
		int c=0;
		for(int j=0; j<s.size(); j++)	if(s[j]!=0)	c++;
		return c;
	}
};
