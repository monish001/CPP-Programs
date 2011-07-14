#include<vector>
#include<map>
//#include<>
using namespace std;
class MarbleDecoration{
	public:int maxLength(int r, int g, int b){
		int x = max(r,g);
		int y = max(min(r,g), b);
		if(x==y)
			return x+y;
		else
			return 2*min(x,y)+1;
	}
};