/* BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You have several squares arranged in a single row. Each square is currently painted red or green. You can choose any of the squares and paint it over with either color. The goal is that, after painting, every red square is further to the left than any of the green squares. We want you to do it repainting the minimum possible number of squares.

Squares are numbered from left to right. You will be given the initial arrangement as a string row, such that character i is 'R' if square i is red or 'G' if square i is green. Return the minimum number of repaints needed to achieve the goal.


DEFINITION
Class:RedAndGreen
Method:minPaints
Parameters:string
Returns:int
Method signature:int minPaints(string row)


CONSTRAINTS
-row will contain between 1 and 50 characters, inclusive.
-Each character of row will be either 'R' or 'G'.


EXAMPLES

0)
"RGRGR"

Returns: 2

Paint the squares in the marked positions in the picture below with the opposite color. There are other ways with 2 total paints.

RGRGR
 |  |
RRRGG


1)
"RRRGGGGG"

Returns: 0

There is no need to paint anything.

2)
"GGGGRRR"

Returns: 3

Paint all the red squares green.

3)
"RGRGRGRGRGRGRGRGR"

Returns: 8



4)
"RRRGGGRGGGRGGRRRGGRRRGR"

Returns: 9



 */
#line 66 "RedAndGreen.cpp"
#include <string>
#include <vector>
using namespace std;
class RedAndGreen {
	public:
	int minPaints(string row) {
		int n=row.size();
		int ans = 100;//Infinity
		for(int i=0; i<=n; i++){//pos where G starts
			int curCost=0;
			for(int j=0; j<i; j++){//inc cost if not R
				if(row[j] != 'R')
					curCost++;
			}
			for(int j=i; j<n; j++){
				if(row[j] != 'G')
					curCost++;
			}
			if(ans > curCost)
				ans = curCost;
		}
		return ans;
	}
};
