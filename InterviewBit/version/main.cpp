#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;
char* getCharArray(const string& str){
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    return cstr;
}
const vector<char*> getCharParts(const string& str){
    vector<char*> vec;
    char *strCharArray = getCharArray(str);
    char *strPart = strtok(strCharArray, ".");
    while(strPart != NULL){
        vec.push_back(strPart);
        strPart = strtok(NULL, ".");
    }
    return vec;
}
char* ignoreLeadingZeros(char* str){
    while(str != NULL && *str == '0'){
        str++;
    }
    return str;
}
bool isAllZeros(const int startIndex, const vector<char*>& parts){
    int len = parts.size();
    for(int index = startIndex; index<len; index++){
        char* part = ignoreLeadingZeros(parts[index]);
        int len = strlen(part);
        if(len > 0){
            return false;
        }
    }
    return true;
}
int compareVersion(string A, string B) {
//int Solution::compareVersion(string A, string B) {
    const vector<char*> aParts = getCharParts(A);
    int aPartsLen = aParts.size(), aIndex=0;
    const vector<char*> bParts = getCharParts(B);
    int bPartsLen = bParts.size(), bIndex=0;
    while(aIndex < aPartsLen && bIndex < bPartsLen){
        // read aPart and bPart
        char* aPart = ignoreLeadingZeros(aParts[aIndex]);
        char* bPart = ignoreLeadingZeros(bParts[bIndex]);
        size_t aPartLen = strlen(aPart);
        size_t bPartLen = strlen(bPart);
        if(aPartLen < bPartLen){
            return -1;
        }else if(aPartLen > bPartLen){
            return 1;
        }

        int result = strcmp(aPart, bPart);
        if(result == 0){
            aIndex++;
            bIndex++;
        }else if(result < 0){
            return -1;
        }else{
            return 1;
        }
    }
    if(aIndex == aPartsLen && bIndex == bPartsLen){
        return 0;
    }else if(aIndex == aPartsLen){
        if(isAllZeros(bIndex, bParts)){
            return 0;
        }
        return -1;
    }else{ // bIndex == bPartsLen
        if(isAllZeros(aIndex, aParts)){
            return 0;
        }
        return 1;
    }
    delete[] aParts[0];
    delete[] bParts[0];
}

int main()
{
// If version1 > version2 return 1,
// If version1 < version2 return -1,
// otherwise return 0.
    cout << compareVersion("2.0.1.999", "2.0.1") << endl;
    cout << compareVersion("2.0.0.999", "2.0.1") << endl;
    cout << compareVersion("0.0.1", "0.1") << endl;
    cout << compareVersion("1", "1.0") << endl;

    cout << compareVersion("01", "001") << endl;
    cout << compareVersion("01.01", "001.001") << endl;

    cout << compareVersion("1", "1") << endl;
    cout << compareVersion("123", "123") << endl;
    cout << compareVersion("12", "123") << endl;
    cout << compareVersion("123", "12") << endl;

    cout << compareVersion("1.1", "1.1") << endl;
    cout << compareVersion("1.1", "1.12") << endl;
    cout << compareVersion("1.123", "1.12") << endl;
    cout << compareVersion("1", "1.12") << endl;
    return 0;
}
