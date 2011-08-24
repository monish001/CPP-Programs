/* BEGIN CUT HERE
// PROBLEM STATEMENT
// Lecette thinks that 5 and 8 are fortunate digits. 
A positive integer is called a fortunate number if it has only fortunate digits in its decimal representation. 

You are given three vector <int>s a, b and c. 
Return that number of fortunate numbers which can be expressed as a[i] + b[j] + c[k] for some indices i, j and k. 
Note that you must not count the same fortunate number more than once. 


DEFINITION
Class:FortunateNumbers
Method:getFortunate
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int getFortunate(vector <int> a, vector <int> b, vector <int> c)


CONSTRAINTS
-a, b and c will each contain between 1 and 50 elements, inclusive. 
-Each element of a, b and c will be between 1 and 30,000, inclusive. 


EXAMPLES

0)
{ 1, 10, 100 }
{ 3, 53 }
{ 4, 54 }

Returns: 2

We have two fortunate numbers 8 = 1 + 3 + 4 and 58 = 1 + 3 + 54. 
58 can be also expressed as 1 + 53 + 4, but you must not count 58 twice. 


1)
{ 47 }
{ 500 }
{ 33 }

Returns: 0

580 is not a fortunate number. 


2)
{ 100, 1, 10, 100, 1, 1 }
{ 3, 53, 53, 53, 53, 53, 53 }
{ 4, 54, 4, 54, 4, 54 }

Returns: 2

3)
{ 500, 800 }
{ 50, 80 }
{ 5, 8 }

Returns: 8

4)
{ 30000, 26264 }
{ 30000, 29294 }
{ 30000, 29594 }

Returns: 3

 */
#line 70 "FortunateNumbers.cpp"
#include <map>
#include <vector>
using namespace std;
int check(char* s){
	for(; *s != '\0'; s++){
		if((*s == '5') || (*s == '8'))
			continue;
		else return 0;
	}
	return 1;
}
char* itoa(int value, char* result, int base=10) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }
	
		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;
	
		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );
	
		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}
class FortunateNumbers {
	public:
	int getFortunate(vector <int> a, vector <int> b, vector <int> c) {
		map<int, int> m;
		char s[50];
		for(int i=0; i<a.size(); i++)
		for(int j=0; j<b.size(); j++)
		for(int k=0; k<c.size(); k++){
			int n = a[i] + b[j] + c[k];
			itoa(n, s);
			puts(s);
			if(check(s))
				m[n]=1;
		}
		
		return m.size();
	}
};
