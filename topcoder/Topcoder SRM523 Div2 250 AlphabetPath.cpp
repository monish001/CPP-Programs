/* BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given a 2-dimensional matrix of characters represented by the vector <string> letterMaze. The i-th character of the j-th element of letterMaze  represents the character at row i and column j. Each of the 26 letters from 'A' to 'Z' appears exactly once in letterMaze, the remaining characters are periods ('.').

An alphabet path is a sequence of 26 elements of the matrix such that:

The first element contains the letter 'A'.
The first element and the second element are (horizontally or vertically) adjacent.
The second element contains the letter 'B'.
The second element and the third element are (horizontally or vertically) adjacent.
...
The 25-th element and the 26-th element are (horizontally or vertically) adjacent.
The last, 26-th element contains the letter 'Z'.

Given letterMaze return string "YES" if the alphabet path exists in the matrix and "NO" otherwise.

DEFINITION
Class:AlphabetPath
Method:doesItExist
Parameters:vector <string>
Returns:string
Method signature:string doesItExist(vector <string> letterMaze)


NOTES
-Formally, elements (x1,y1) and (x2,y2) are horizontally or vertically adjacent if and only if abs(x1 - x2) + abs(x2 - y2) = 1. 


CONSTRAINTS
-letterMaze will contain between 1 and 50 elements, inclusive.
-Each element of letterMaze will contain between 1 and 50 characters, inclusive.
-All the elements of letterMaze will contain the same number of characters.
-Each element of letterMaze will only contain uppercase letters ('A'-'Z') and periods ('.').
-Each uppercase letter from 'A' to 'Z' will appear exactly once in letterMaze.


EXAMPLES

0)
{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}

Returns: "YES"

Simply go from left to right.

1)
{"ADEHI..Z",
 "BCFGJK.Y",
 ".PONML.X",
 ".QRSTUVW"}


Returns: "YES"



2)
{"ACBDEFGHIJKLMNOPQRSTUVWXYZ"}

Returns: "NO"



3)
{"ABC.......",
 "...DEFGHIJ",
 "TSRQPONMLK",
 "UVWXYZ...."}

Returns: "NO"

The cells marked with C and D are not adjacent, it is impossible to make an alphabet path in this case.

4)
{"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
 ".............."}

Returns: "YES"



 */
#line 93 "AlphabetPath.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
class AlphabetPath {
	public:
	string doesItExist(vector <string> l) {
		int numS = l.size(), numC= l[0].size();
		bool found = false;
		int i,j;
		for(i=0; !found;i++){
			for(j=0; j<numC && !found; j++)
				if(l[i][j] == 'A'){
					found=true;
					
				}
		}
		i--; j--;
	//	cout<<"A found at "<<i<<" "<<j<<endl;
		char c;
		for(c='B'; c<='Z'; c++){
			if(j!=0 && l[i][j-1]==c){
				j--; continue;}
			if(j!=numC-1 && l[i][j+1]==c)
				{j++; continue;}
			if(i!=0 && l[i-1][j]==c)
				{i--; continue;}
			if(i!=numS-1 && l[i+1][j]==c)
				{i++; continue;}
			break;
		}
		if(c > 'Z')
			return "YES";
		return "NO";
	}
};
