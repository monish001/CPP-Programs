/* BEGIN CUT HERE
// PROBLEM STATEMENT
// Mr. Dengklek introduced you to an online programming contest called SRM (Special Round Match)!

There are N coders in the contest, including you. Each coder has a skill measurement called rating. This information is given in ratings, where ratings[0] is your rating and ratings[1] through ratings[N-1] are the ratings of the other coders. Ratings of all coders are pairwise distinct.

You are now in the room assignment phase of the contest. There are K available rooms. Each coder will be assigned to exactly one room in the following way: the coders, in descending order of their ratings, are assigned one-by-one to rooms 1, 2, ..., K, 1, 2, ..., K, ... and so on in that order. See the examples for further clarification.

You wish to win your room, so you wonder how many stronger competitors you have. Return the number of coders in your room who have higher ratings than yours.

DEFINITION
Class:SRMRoomAssignmentPhase
Method:countCompetitors
Parameters:vector <int>, int
Returns:int
Method signature:int countCompetitors(vector <int> ratings, int K)


CONSTRAINTS
-ratings will contain between 2 and 50 elements, inclusive.
-Each element of ratings will be between 0 and 1199, inclusive.
-All elements of ratings will be distinct.
-K will be between 1 and the number of elements in ratings, inclusive.


EXAMPLES

0)
{491, 981, 1199, 763, 994, 879, 888}
3

Returns: 2

Here is the room assignment for all coders.

Room 1 coders' ratings:

1199
888
491


Room 2 coders' ratings:

994
879


Room 3 coders' ratings:

981
763


You are in Room 1, and there are 2 coders with greater ratings than yours.



1)
{1024, 1000, 600}
1

Returns: 0

You are the highest rated coder in Room 1.

2)
{505, 679, 900, 1022}
2

Returns: 1

You are the lowest rated coder in Room 2.

3)
{716, 58, 1000, 1004, 912, 822, 453, 1100, 558}
3

Returns: 1

You are the second highest rated coder in Room 3.

4)
{422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500}
4

Returns: 3



5)
{1197, 1198, 1196, 1195, 1199}
1

Returns: 2



 */
#line 101 "SRMRoomAssignmentPhase.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
class SRMRoomAssignmentPhase {
	public:
	int countCompetitors(vector <int> r, int K) {
		int ass = r[0];
		sort(r.begin(), r.end(), std::greater<int>());
		
		int pos=0;
		for(int i=0; i<r.size(); i++)
			if(r[i] == ass)	
				pos = i;
		
		int a=0;
		cout<<r[0];
		for(int i=(pos%K); i<r.size(); i+=K)
			if(r[i] > ass)
			a++;
		return a;
	}
};
