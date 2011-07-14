//NOT COMPLETE
#include <string>
#include <vector>
using namespace std;
using namespace std;
int getP(char c){
	if(c <= '9')
		return c- '0';
	if(c<='Z')
		return c-'A'+10;
	return c-'a'+36;
}
class MysteriousRestaurant{
	vector<string> p;
	int *ar;//price for the day so far
	int budget;
	int getMinPriceDishIndex(const int &w,const int &d, int &price, const int dish){
		int dishCount = p[0].length(), minPriceDishIndex = 0 ;
		
		for(int j=0; j<dishCount; j++){
			ar[j] += getP(p[w+d][j]);
		}
		for(int j=0; j<dishCount; j++){
			if(ar[j] < ar[minPriceDishIndex])
				minPriceDishIndex = j;
		}
		int ch = 0;
		if(dish != -1 && dish != minPriceDishIndex){
			ch = ar[dish] - getP(p[w+d][dish]) - ar[minPriceDishIndex] +getP(p[w+d][minPriceDishIndex]);
		}
		budget -= ch;
		price = getP(p[w+d][minPriceDishIndex]);
		return minPriceDishIndex;
	}
	public:int maxDays(const vector<string> pr,const int b){
		budget = b;
		p = pr;
		int n = p.size();//num of days
		if(n==0)
			return 0;
		ar = new int[p[0].size()];//p[0].size() is num of dishes
		for(unsigned int i=0; i<p[0].size(); i++)
			ar[i]=0;
		int days=0, dish[7]/*dish index*/;
		for(int i=0; i<7; i++)
			dish[i]=-1;//no dish index selected initially
		for(int w=0; w<n; w+=7){//for each week
			for(int d=0; d<7; d++){//for each day of a week
				int price;
				dish[d] = getMinPriceDishIndex(w, d, price, dish[d]);
				if(budget < price || w+d=n)
					return days;
				days++;
				budget -= price;
			}
		}
	}
};

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
