#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;

int strStr(const string &haystack, const string &needle) {
    if(haystack.empty() || needle.empty()){
        return -1;
    }
    int haystackLen = haystack.size(), needleLen = needle.size();
    for(int index=0; index<haystackLen; index++){
        int needleIndex = 0, haystackIndex = index;
        while(haystackIndex < haystackLen
             && needleIndex < needleLen
             && haystack[haystackIndex] == needle[needleIndex]){
            needleIndex++; haystackIndex++;
        }
        if(needleIndex == needleLen){
            return index;
        }
    }
    return -1;
}

int main()
{
    cout << strStr("Hello world!", "world") << endl;
    return 0;
}
