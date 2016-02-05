#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isSquare(const int top, const int right, const int bottom, const int left){
    return top == right && right == bottom && bottom == left && left == top;
}

bool isValidSides(const int top, const int right, const int bottom, const int left){
    return top > 0 && right > 0 && bottom > 0 && left > 0;
}
bool isRect(const int top, const int right, const int bottom, const int left){
    return top == bottom && right == left;
}

int main() {
    int numTestCases, numSquares=0, numRects = 0, numOther = 0;
    cin>>numTestCases;
    for(int tc=0; tc<numTestCases; tc++){
        int top, right, bottom, left;
        cin>>top>>right>>bottom>>left;
        if(isValidSides(top, right, bottom, left)){
            if(isSquare(top, right, bottom, left)){
                numSquares++;
            }else if(isRect(top, right, bottom, left)){
                numRects++;
            }else{numOther++;}
        }else{
            numOther++;
        }
    }
    cout << numSquares << " " << numRects << " " << numOther << endl;
    return 0;
}
