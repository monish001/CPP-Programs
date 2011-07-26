/* BEGIN CUT HERE
// PROBLEM STATEMENT
// You may remember an old computer game called "The Incredible Machine". It was a game where you could simulate simple processes like balls falling, lasers shooting, or cats pursuing mice.
Manao is faced with the following problem in this game.

The game is 2-dimensional. To make solving the problem easier, Manao introduced the cartesian coordinates on the screen. The OX axis goes from left to right and coincides with the ground. The OY axis goes from bottom to top.

There are N horizontal platforms mounted at different heights. The length of the i-th platform is platformLength[i] and it is mounted at point (platformMount[i], i + 1). Each platform can be moved horizontally in such a way that it does not disconnect from its mount, i.e., the mount resides between its ends or on one of them. In other words, the leftmost possible position of the i-th platform is when its left end is at (platformMount[i] - platformLength[i], i + 1) and the rightmost position is when its right end is at (platformMount[i] + platformLength[i], i + 1). The platforms may only be moved by integer distances, so both left and right ends of a platform are always located at points with integer coordinates.

Several balls will simultaneously fall downwards to the ground from a height that is above all platforms. All balls will fall vertically and the i-th of them will fall at X-coordinate balls[i]. The balls are very small and can be considered as points. Manao should set the platforms' placement in such a way that no ball falls on a platform. Falling on an end of a platform counts as falling on a platform. Manao is not allowed to move the platforms once the balls start falling.

Count the number of ways to place the platforms so that all of the balls miss them. Return this number modulo 1,000,000,009. Two placements are different if there's a platform that has different positions in these placements.

DEFINITION
Class:YetAnotherIncredibleMachine
Method:countWays
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls)


CONSTRAINTS
-platformMount will contain between 1 and 50 elements, inclusive.
-Each element of platformMount will be between -10000 and 10000, inclusive.
-platformLength will contain the same number of elements as platformMount.
-Each element of platformLength will be between 1 and 10000, inclusive.
-balls will contain between 1 and 50 elements, inclusive.
-Each element of balls will be between -10000 and 10000, inclusive.
-All elements of balls will be distinct.


EXAMPLES

0)
{7}
{10}
{3,4}

Returns: 3

A platform of length 10 is mounted at point (7, 1). Two balls will fall at coordinates 3 and 4. There are three placements of the platform which let the ball miss it: setting the platform's left end at X-coordinate 5, 6 and 7.

1)
{1,4}
{3,3}
{2,7}

Returns: 1

The only placement which ensures that balls land aside the platforms is when platform 0's right end is at point (1, 1) and platform 1's left end is at (3, 2).

2)
{4,4,4}
{10,9,8}
{1,100}

Returns: 27

There are 3 possible placements for each of the platforms.

3)
{0}
{1}
{0}

Returns: 0

There is no way to move the platform away from the ball's trajectory.

4)
{100, -4215, 251}
{400, 10000, 2121}
{5000, 2270, 8512, 6122}

Returns: 250379170



 */
#line 81 "YetAnotherIncredibleMachine.cpp"
#include <string>
#include <vector>
using namespace std;
class YetAnotherIncredibleMachine {
	public:
	int countWays(vector <int> m/*platformMount*/, vector <int> l/*platformLength*/, vector <int> ba/*alls*/) {
		//sort(b); 
		int nb = ba.size(), np = m.size();
		long long w=1;
		for(int pf=0; pf<np; pf++){
			int pos=0;
			int st = m[pf] - l[pf], en = m[pf];
			do{
				int able=1;
				for(int b=0; b<nb; b++){
					if(ba[b]>=st && ba[b]<=en){
						able=0; 
						break;
					}
				}
				if(able){
					pos++ ;
					printf("%d\n",st);//std::cout<<st<<"\n";
				}
				st++; en++;
			}while(st <= m[pf]);
			if(pos){
				if(w*pos < 0){
					long long tmp = w; w = -1000000009;
					for(int i=0; i<pos; i++){
						w += tmp;
					}
				}else
					w *= pos;
			}else
				return 0;
		}
		return w%1000000009;
	}
};
