/* BEGIN CUT HERE
// PROBLEM STATEMENT
// Lecette has a clock with an hour hand and a minute hand. 
The hour hand makes a full rotation in 12 hours, and the minute hand makes a full rotation in one hour. 
Both hands move smoothly, at constant speeds. 
The clock has a scale marked in 30 degree increments, and both hands point to the same mark at 00:00. 

Lecette wants to know what time it is, but the clock is rotated, so she can't tell where the top of the clock is. 
She measured the angles of hands from a certain mark, clockwise: 
hourHand and minuteHand (both in degrees). 
Return the earliest possible time that is consistent with these measurements. 
Format the return value as a string of the form "HH:MM" (quotes for clarity). 
Lecette might have measured the angles incorrectly. 
If there is no corresponding time, return an empty string instead. 


DEFINITION
Class:RotatedClock
Method:getEarliest
Parameters:int, int
Returns:string
Method signature:string getEarliest(int hourHand, int minuteHand)


CONSTRAINTS
-hourHand and minuteHand will each be between 0 and 359, inclusive. 


EXAMPLES

0)
70
300

Returns: "08:20"

This is how the clock were positioned when Lecette made her measurements: 



In order to show a valid time, the clock needs to be turned upside down: 




1)
90
120

Returns: "11:00"

2)
240
36

Returns: ""

3)
19
19

Returns: ""

4)
1
12

Returns: "00:02"

The time when the coding phase started. 


 */
#line 75 "RotatedClock.cpp"
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
void check(int h, int m, string& s){

		s[1] = 48 + (h/30)%10;
		s[0] = 48 + (h/30)/10;
		s[2] = ':';
		s[3] = 48 + (m/6)/10;
		s[4] = 48 + (m/6)%10;
	cout<<s<<"\n";
	double hh = h, mm = m;
	printf(" h=%lf m=%lf\n",(2* fmod(hh,30.0)),((mm/6.0)));
	if( 2* fmod(hh,30.0) == (mm/6.0) ){
//	if( 2* h%30 == m%6 ){
		return;
	}else
		s[0] = s[1] = s[2] = s[3] = s[4] = '\0';
}
class RotatedClock {
	public:
	string getEarliest(int h, int m) {
		//int tmp = h/30; h-= tmp*30; m-= tmp*30;
		string s(5, 0);
		for(int i=0; i<=11; i++){
			
			check( (h+30*i)%360 , (m+30*i)%360, s);
			if(s[0] != '\0'){
				printf("Match Found.");
				return s;
			}
		}
		return string("");
	}
};
