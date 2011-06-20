#include<vector>
#include<cstring>
#include<cstdlib>
//#include<>
using namespace std;
char* itoa(int value, char* result, int base) {
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
    

    
    class PalindromizationDiv2{
	public: int getMinimumCost(int X){
		int x=X;
		if(x == 0)
			return 0;
		char v[7];
		itoa(X, v, 10);
		int d = strlen(v);
		int d2 = d/2;
		for(; d2>0; d2--)
			v[d-d2] = v[d2-1];
		x= atoi(v);
		return max(X-x, x-X);
	}
};
