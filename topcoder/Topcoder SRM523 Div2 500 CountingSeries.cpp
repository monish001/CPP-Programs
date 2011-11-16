/* BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given long longs a, b, c and d. The numbers a and b define an arithmetic progression that consists of all numbers of the form a + b*x, where x is a nonnegative integer. Likewise, c and d define a geometric progression that consists of all the numbers that are equal to c * d^y, where y is a nonnegative integer. You are also given a long long upperBound. Return the total number of integers between 1 and upperBound, inclusive, that belong to the arithmetic progression, the geometric progression or both.

DEFINITION
Class:CountingSeries
Method:countThem
Parameters:long long, long long, long long, long long, long long
Returns:long long
Method signature:long long countThem(long long a, long long b, long long c, long long d, long long upperBound)


NOTES
-The ^ operator in this statement denotes the exponentiation operation. For example, 3^0 = 1 and 2^4 = 2*2*2*2 = 16.


CONSTRAINTS
-a, b, c and upperBound will each be between 1 and 1000000000000 (10^12), inclusive.
-d will be between 1 and 100000 (10^5), inclusive.


EXAMPLES

0)
1
1
1
2
1000

Returns: 1000

The arithmetic progression is: 1, 2, 3, 4, ... .
The geometric progression is: 1, 2, 4, 8, 16, ... . 
Each positive integer is contained in at least one of the progressions.

1)
3
3
1
2
1000

Returns: 343

This time, the arithmetic progression is: 3, 6, 9, 12, ... .
The geometric progression is still: 1, 2, 4, 8, 16, ....
There are 333 multiples of 3 between 1 and 1000, inclusive, and there are 10 powers of 2, 512 being the highest. As these two progressions do not have any common elements, the total result is 343.

2)
40
77
40
100000
40

Returns: 1



3)
452
24
4
5
600

Returns: 10

The 10 numbers are: 4, 20, 100, 452, 476, 500, 524, 548, 572 and 596.

4)
234
24
377
1
10000

Returns: 408



 */
#line 85 "CountingSeries.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
class CountingSeries {
	public:
	long long countThem(long long a, long long b, long long c, long long d, long long u) {
		long long p = c, r=0;
		// while(s<=u || p<=u){
			// if(p>s){
				// s+=b;
				// r++;
			// }else if(s==p){
				// s+=b;
			// }else{
				// p*=d;
				// r++;
			// }
		// }
		if(d!=1){
			while(p<a)
				p*=d;
			for(; p<=u; p*=d){
				if((p-a)%b == 0)
					r++;
			}
		}else if((p-a)%b == 0){
			r=1;
		}
		//cout<<(u-a)/b<<" "<<(log(u)-log(c))/log(d)<<" "<<r;
		return (u-a)/b + ((d!=1)?((log(u)-log(c))/log(d)):(0)) -r + 2;
	}
};
