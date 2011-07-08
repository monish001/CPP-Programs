/* Filename:  extsort.cpp

   Programmer:  Br. David Carlson

   Date:  April 18, 2003

   This program does a case-insensitive sort of the text file that the user supplies
   when prompted by the program.  It is assumed that each line of the file contains a
   word and is no more than 31 characters in length.  No attempt is made to order in any
   way words that are identical except for capitalization.  (For example, there is no
   guarantee what order the sort will place the words MacIntosh and Macintosh since
   they are seen as identical.  Duplicate words such as these are kept in the file.)
   The output data is placed back under the original file name.

   Tested with:
      Microsoft Visual C++ 6.0
      Microsoft Visual C++ .NET
   This program will not work as is with g++ under Linux due to its use of items such as
   the constant _MAX_PATH as well as the functions _itoa, and stricmp.
*/

#include "extsort.h"


int main(void)
   {
   PathType FileName;
   fstream DataFile;
   int NumRuns;

   cout << "Enter the name of the text file to be sorted: ";
   cin.getline(FileName, _MAX_PATH);

   DataFile.open(FileName, ios::in);
   if (DataFile.fail())
      Error("Could not open the file named ", FileName);

   // Copy sections of the data file into sorted runs.
   NumRuns = MakeSortedRuns(DataFile, FileName);
   DataFile.close();

   // Merge the sorted runs until all of the data is in one sorted file (under the original FileName).
   HandleMerges(NumRuns, FileName);

   #ifdef DEBUG
      // Pause so the user can read the debugging messages.
      cout << "Press ENTER: ";
      cin.get();
   #endif

   return 0;
   }


/* Given:   DataFile    A text file stream already opened for input.
            FileName    The name of this text file (as a char array string).
   Task:    To copy data from this file stream into sorted files (runs).
   Return:  DataFile    The modified file stream is trivially modified by reading from it.
            In the function name the number of runs is returned.
            The sorted runs themselves are created and stored under the file names:
            ExtSortTemp.0, ExtSortTemp.1, etc.
*/
int MakeSortedRuns(fstream & DataFile, PathType FileName)
   {
   fstream OutFile;
   StringType Word, Extension;
   PathType OutFileName;
   int NumWords, k, NumFiles = 0;
   BufType Buffer;
   bool MoreData;

   // Repeatedly fill one buffer and quicksort it, writing the buffer out to a temp file.
   DataFile.getline(Word, MaxString);
   if (DataFile.fail())
      MoreData = false;
   else
      MoreData = true;

   while (MoreData)
      {
      // Fill one buffer.
      NumWords = FillBuffer(DataFile, Buffer, MoreData, Word);
      QuickSort(Buffer, 0, NumWords - 1);

      // Construct the temp file name.
      strcpy(OutFileName, "ExtSortTemp.");
      _itoa(NumFiles, Extension, 10);   // Convert the int in NumFiles to a char array string.
      strcat(OutFileName, Extension);

      OutFile.open(OutFileName, ios::out);
      if (OutFile.fail())
         Error("Could not open the file named ", OutFileName);

      for (k = 0; k < NumWords; k++)
         OutFile << Buffer[k] << endl;

      OutFile.close();
      NumFiles++;
      }

   return NumFiles;
   }


/* Given:   NumFiles    Number of sorted runs (files) to be merged.
            FileName    The name of the text file to contain the merged data.
            Indirectly this function is also given the sorted runs, which are assumed to be
            files named  ExtSortTemp.0, ExtSortTemp.1, etc.
   Task:    To merge the data from these sorted runs into one combined, sorted file with
            the name given by FileName.
   Return:  Nothing directly, but the file named by FileName is modified (by being sorted).
*/
void HandleMerges(int NumFiles, PathType FileName)
   {
   StringType Extension;
   PathType OutFileName, InFileName1, InFileName2;
   int k, NumPairs, Count;
   bool Odd;

   // Repeatedly merge 2 runs, writing data to a new temp file (but write last one to original file).
   if (NumFiles == 0)   // No data is present, so there is no work to do.
      return;
   else if (NumFiles == 1)
      {
      // Remove original file and rename the temp file using name of the original.
      remove(FileName);
      rename("ExtSortTemp.0", FileName);

      #ifdef DEBUG
         cout << "Renaming ExtSortTemp.0 as " << FileName << endl;
      #endif

      return;   // The sort is finished.
      }
   else if (NumFiles == 2)
      {
      // Merge the 2 sorted temp files into original file.
      Merge("ExtSortTemp.0", "ExtSortTemp.1", FileName);
      remove("ExtSortTemp.0");
      remove("ExtSortTemp.1");
      return;   // The sort is finished.
      }
   else   // We have 3 or more files.
      {
      // Merge temp files, 2 at a time, until only 2 remain, then proceed as in last case.
      while (NumFiles > 2)
         {
         // Merge ExtSortTemp.0 and ExtSortTemp.1 into ExtSortTempA.0,
         // merge ExtSortTemp.2 and ExtSortTemp.3 into ExtSortTempA.1, etc.
         NumPairs = NumFiles / 2;
         for (k = 0, Count = 0; k < NumPairs; k++)
            {
            strcpy(InFileName1 , "ExtSortTemp.");
            _itoa(Count++, Extension, 10);
            strcat(InFileName1, Extension);
            strcpy(InFileName2 , "ExtSortTemp.");
            _itoa(Count++, Extension, 10);
            strcat(InFileName2, Extension);
            strcpy(OutFileName , "ExtSortTempA.");
            _itoa(k, Extension, 10);
            strcat(OutFileName, Extension);
            Merge(InFileName1, InFileName2, OutFileName);
            }
         // If the number of files is odd, just rename the last one.
         if (2 * NumPairs < NumFiles)
            {
            Odd = true;
            strcpy(InFileName1 , "ExtSortTemp.");
            _itoa(Count, Extension, 10);
            strcat(InFileName1, Extension);
            strcpy(OutFileName , "ExtSortTempA.");
            _itoa(NumPairs, Extension, 10);
            strcat(OutFileName, Extension);
            rename(InFileName1, OutFileName);

            #ifdef DEBUG
               cout << "Renaming " << InFileName1 << " as " << OutFileName << endl;
            #endif
            }
         else
            Odd = false;

         // Remove the temp files from before the merge.
         for (k = 0; k < NumFiles; k++)
            {
            strcpy(InFileName1 , "ExtSortTemp.");
            _itoa(k, Extension, 10);
            strcat(InFileName1, Extension);
            remove(InFileName1);
            }

         // Get the new number of sorted files.
         NumFiles = NumPairs;
         if (Odd)
            NumFiles++;

         // If number of ExtSortTempA files is now 2, merge them with output to original file and return.
         if (NumFiles == 2)
            {
            Merge("ExtSortTempA.0", "ExtSortTempA.1", FileName);
            remove("ExtSortTempA.0");
            remove("ExtSortTempA.1");
            return;   // The sort is finished.
            }

         // Otherwise, merge pairs of files as above, but start at the top end so as to 
         // incorporate any small remainder file.  Note that we now merge from the
         // ExtSortTempA files into ExtSortTemp files.
         NumPairs = NumFiles / 2;
         for (k = 0, Count = NumFiles - 1; k < NumPairs; k++)
            {
            strcpy(InFileName1 , "ExtSortTempA.");
            _itoa(Count--, Extension, 10);
            strcat(InFileName1, Extension);
            strcpy(InFileName2 , "ExtSortTempA.");
            _itoa(Count--, Extension, 10);
            strcat(InFileName2, Extension);
            strcpy(OutFileName , "ExtSortTemp.");
            _itoa(k, Extension, 10);
            strcat(OutFileName, Extension);
            Merge(InFileName1, InFileName2, OutFileName);
            }
         // If the number of files is odd, just rename the last one.
         if (2 * NumPairs < NumFiles)
            {
            Odd = true;
            strcpy(InFileName1 , "ExtSortTempA.");
            _itoa(0, Extension, 10);
            strcat(InFileName1, Extension);
            strcpy(OutFileName , "ExtSortTemp.");
            _itoa(NumPairs, Extension, 10);
            strcat(OutFileName, Extension);
            rename(InFileName1, OutFileName);

            #ifdef DEBUG
               cout << "Renaming " << InFileName1 << " as " << OutFileName << endl;
            #endif
            }
         else
            Odd = false;

         // Remove the temp files from before the merge.
         for (k = 0; k < NumFiles; k++)
            {
            strcpy(InFileName1 , "ExtSortTempA.");
            _itoa(k, Extension, 10);
            strcat(InFileName1, Extension);
            remove(InFileName1);
            }

         // Get the new number of sorted files.
         NumFiles = NumPairs;
         if (Odd)
            NumFiles++;

         // If number of ExtSortTemp files is now 2, merge them with output to original file and return.
         if (NumFiles == 2)
            {
            Merge("ExtSortTemp.0", "ExtSortTemp.1", FileName);
            remove("ExtSortTemp.0");
            remove("ExtSortTemp.1");
            return;   // The sort is finished.
            }
         }
      }
   }


/* Given:   InFile      Text file stream already opened for input.
            MoreData    Indicates if there is more data from InFile to place into Buffer.
                        At the very least this indicates if there is an unused item in NextWord.
            NextWord    If MoreData is true, then NextWord contains an unprocessed word from
                        InFile that has yet to be placed into Buffer.
   Task:    If MoreData is true, this function places as much data as possible from InFile into
            Buffer.  This data includes NextWord and then as much new data as possible from InFile.
            The Buffer will be filled if there is enough data to do so.
   Return:  In the function name is returned the number of words placed into Buffer.
            InFile      The modified file stream.
            Buffer      Contains the data that has been copied in from InFile.
            MoreData    Indicates if NextWord contains a word that has not yet been placed into Buffer.
            NextWord    If MoreData is true, this contains the next word from InFile that has
                        not yet been placed into Buffer.
*/
int FillBuffer(fstream & InFile, BufType Buffer, bool & MoreData, StringType NextWord)
   {
   int k = 0;

   while (MoreData && (k < BufSize))
      {
      strcpy(Buffer[k], NextWord);
      InFile.getline(NextWord, MaxString);
      if (InFile.fail())
         MoreData = false;
      else
         MoreData = true;
      k++;
      }

   return k;
   }


/* Given:   InFileName1   The name of the first text file to be merged.
            InFileName2   The name of the second text file to be merged.
            OutFileName   The name of the file in which to place the merged data.
   Task:    To merge the sorted text files named InFileName1 and InFileName2 into one
            named by OutFileName.
   Return:  Nothing directly, but the text file named by OutFileName is created and filled
            with the sorted data from InFileName1 and InFileName2.
*/
void Merge(StringType InFileName1, StringType InFileName2, StringType OutFileName)
   {
   fstream InFile1, InFile2, OutFile;
   BufType Buffer1, Buffer2, Buffer3;
   bool HaveData1, HaveData2, MoreData1, MoreData2;
   StringType NextWord1, NextWord2;
   int k, Result, NumWords1, NumWords2, Index1, Index2, Index3 = 0;

   InFile1.open(InFileName1, ios::in);
   if (InFile1.fail())
      Error("Could not open the file named ", InFileName1);

   InFile2.open(InFileName2, ios::in);
   if (InFile2.fail())
      Error("Could not open the file named ", InFileName2);

   OutFile.open(OutFileName, ios::out);
   if (OutFile.fail())
      Error("Could not open the file named ", OutFileName);

   #ifdef DEBUG
      cout << "Merging " << InFileName1 << " and " << InFileName2 << " to " << OutFileName << endl;
   #endif

   // Try to fill a buffer from InFile1.
   InFile1.getline(NextWord1, MaxString);
   if (InFile1.fail())
      MoreData1 = false;
   else
      {
      MoreData1 = true;
      NumWords1 = FillBuffer(InFile1, Buffer1, MoreData1, NextWord1);
      }

   // Try to fill a buffer from InFile2.
   InFile2.getline(NextWord2, MaxString);
   if (InFile2.fail())
      MoreData2 = false;
   else
      {
      MoreData2 = true;
      NumWords2 = FillBuffer(InFile2, Buffer2, MoreData2, NextWord2);
      }

   Index1 = 0;
   Index2 = 0;
   // Each HaveData boolean indicates if we have more unmerged data.  This data could be in
   // the corresponding NextWord variable, the corresponding Buffer, or both.
   HaveData1 = MoreData1 || (Index1 < NumWords1);
   HaveData2 = MoreData2 || (Index2 < NumWords2);

   while (HaveData1 && HaveData2)
      {
      if (Index1 == NumWords1)
         {
         NumWords1 = FillBuffer(InFile1, Buffer1, MoreData1, NextWord1);
         if (NumWords1 == 0)
            break;   // We are out of data from InFile1.
         else
            Index1 = 0;
         }
      if (Index2 == NumWords2)
         {
         NumWords2 = FillBuffer(InFile2, Buffer2, MoreData2, NextWord2);
         if (NumWords2 == 0)
            break;   // We are out of data from InFile2.
         else
            Index2 = 0;
         }

      Result = stricmp(Buffer1[Index1], Buffer2[Index2]);   // case insensitive compare

      if (Result == 0)   // Copy both data items.
         {
         Copy(Buffer1[Index1], Buffer3, Index3, OutFile);
         Copy(Buffer2[Index2], Buffer3, Index3, OutFile);
         Index1++;
         Index2++;
         }
      else if (Result < 0)   // Copy the first data item.
         {
         Copy(Buffer1[Index1], Buffer3, Index3, OutFile);
         Index1++;
         }
      else   // Result > 0, so copy the second data item.
         {
         Copy(Buffer2[Index2], Buffer3, Index3, OutFile);
         Index2++;
         }

      HaveData1 = MoreData1 || (Index1 < NumWords1);
      HaveData2 = MoreData2 || (Index2 < NumWords2);
      }
   
   // Handle remaining data in either file.
   while (HaveData1)
      {
      if (Index1 == NumWords1)
         {
         NumWords1 = FillBuffer(InFile1, Buffer1, MoreData1, NextWord1);
         if (NumWords1 == 0)
            break;   // We are out of data from InFile1.
         else
            Index1 = 0;
         }

      Copy(Buffer1[Index1], Buffer3, Index3, OutFile);
      Index1++;
      HaveData1 = MoreData1 || (Index1 < NumWords1);
      }

   while (HaveData2)
      {
      if (Index2 == NumWords2)
         {
         NumWords2 = FillBuffer(InFile2, Buffer2, MoreData2, NextWord2);
         if (NumWords2 == 0)
            break;   // We are out of data from InFile2.
         else
            Index2 = 0;
         }

      Copy(Buffer2[Index2], Buffer3, Index3, OutFile);
      Index2++;
      HaveData2 = MoreData2 || (Index2 < NumWords2);
      }

   // Flush any remaining data from the output buffer.
   for (k = 0; k < Index3; k++)
      OutFile << Buffer3[k] << endl;

   InFile1.close();
   InFile2.close();
   OutFile.close();
   }


/* Given:   Word      One word of data to be placed into Buffer.
            Buffer    A buffer that may already contain words.
            Index     The first unused index in Buffer.
            OutFile   A text file stream already opened for output.
   Task:    To place Word into Buffer.  If the Buffer is full, the data
            already in it is first written out to OutFile, then Word
            is placed into Buffer as the only item present.
   Return:  Buffer    The updated buffer.
            Index     The updated index of the first unused location in Buffer.
            OutFile   The possibly updated file stream.
*/
void Copy(StringType Word, BufType Buffer, int & Index, fstream & OutFile)
   {
   int k;

   if (Index == BufSize)   // There is no room in Buffer, so first write the Buffer data to OutFile.
      {
      for (k = 0; k < BufSize; k++)
         OutFile << Buffer[k] << endl;
      Index = 0;
      }

   strcpy(Buffer[Index], Word);
   Index++;
   }


/* Given:  First    A char array string.
           Second   Another char array string.
   Task:   To swap these values.
   Return: First    Updated string.
           Second   Updated string.
*/
inline void Swap(StringType First, StringType Second)
   {
   StringType Temp;

   strcpy(Temp, First);
   strcpy(First, Second);
   strcpy(Second, Temp);
   }


/* Given:  Buf       Array of char array strings
           Lower     An index into the array.
           Upper     An index into the array.
   Task:   To quicksort the section of the array from index Lower to Upper.
   Return: Buf       The sorted array.
*/
void QuickSort(BufType Buf, int Lower, int Upper)
   {
   int PivotIndex;

   if (Lower < Upper)
      {
      PivotIndex = Partition(Buf, Lower, Upper);
      QuickSort(Buf, Lower, PivotIndex - 1);   // sort left side
      QuickSort(Buf, PivotIndex + 1, Upper);   // sort right side
      }
   }


/* Given:  Buf       Array of char array strings.
           Lower     An index into the array.
           Upper     An index into the array.
   Assume: Lower < Upper
   Task:   To partition the section of Buf between index Lower and
           index Upper so that everything to the left of the returned
           index is less or equal to the pivot item, which is Buf[Lower],
           everything to the right of the returned index is greater
           than the pivot item, and the pivot item itself is located
           at the returned index.
   Return: Buf      The partitioned array.
           In the function name this returns the index of the pivot value.
*/
int Partition(BufType Buf, int Lower, int Upper)
   {
   int Left, Right;
   StringType Pivot;

   strcpy(Pivot, Buf[Lower]);
   Left = Lower;
   Right = Upper;

   while (Left < Right)
      {
      // Scan from left, skipping items that belong there. Use case-insensitive compare.
      while ((stricmp(Buf[Left], Pivot) <= 0) && (Left < Upper))
         Left++;
      // Scan from right, skipping items that belong there.  Use case-insensitive compare.
      while (stricmp(Buf[Right], Pivot) > 0)
         Right--;
      if (Left < Right)
         Swap(Buf[Left], Buf[Right]);
      }

   strcpy(Buf[Lower], Buf[Right]);
   strcpy(Buf[Right], Pivot);
   return Right;  // return the pivot index
   }



/* Given:  MsgA, MsgB    Two messages (string objects) to display.
   Task:   Display MsgA and MsgB, then exit the program.
   Return: Nothing to the program, but does return an error code of 1 to the operating system.
*/
void Error(const string & MsgA, const string & MsgB)
   {
   cerr << "Error: " << MsgA << MsgB << endl;
   exit(1);
   }

