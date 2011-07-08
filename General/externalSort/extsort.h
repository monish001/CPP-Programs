/* Filename:  extsort.h

   Programmer:  Br. David Carlson

   Date:  April 18, 2003

   This header file sets up the constants, types, and function prototypes used by the
   ExtSort program.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Comment off the following line if you do not want to see debugging information.
//#define DEBUG

const int MaxString = 32;

const int BufSize = 2048;


typedef char StringType[MaxString];

typedef StringType BufType[BufSize];   // A buffer will hold 2048 strings, for a total of 64K bytes.

typedef char PathType[_MAX_PATH];


void Error(const string & Msg);

void Error(const string & MsgA, const string & MsgB);

int MakeSortedRuns(fstream & DataFile, PathType FileName);

bool LessThan(StringType First, StringType Second);

void QuickSort(BufType Buf, int Lower, int Upper);

void Swap(StringType First, StringType Second);

int Partition(BufType Buf, int Lower, int Upper);

void Merge(StringType InFileName1, StringType InFileName2, StringType OutFileName);

int FillBuffer(fstream & InFile, BufType Buffer, bool & HaveData, StringType NextWord);

void Copy(StringType Word, BufType Buffer, int & Index, fstream & OutFile);

void HandleMerges(int NumFiles, PathType FileName);

