/* next question is given an array of integers...like 10 12 16 17 24 27 8 6 5 4 2....first from 10 to 27 it is in increasing order... .and then decreasing order starts....so he asked me to find the position from where decreasing starts....it should be done in O(logn). 
TestCase: 10 12 16 17 24 27 8 6 5 4 2
 indices: 0  1  2  3  4  5  6 7 8 9 10
Output: 6		   
Running Link: http://www.ideone.com/BGiNk
*/

#include<stdio.h>
//#include<stdio.h>
int main(){
        int i, n, *a;
        printf("Enter count of numbers..");
        scanf("%d", &n);
        a = (int*)malloc(n*sizeof(int));
        for(i=0; i<n; i++){
                scanf("%d",a+i);
                printf("%d ",a[i]);
        }
        int ansInd = binaryVariant(a, 0, n-1, n);
        (ansInd!=-1)?printf("Ans: a[%d] = %d\n", ansInd, a[ansInd]):printf("Not Found");
        return 0;
}
int binaryVariant(int* a, int beg, int end, int n){//assuming no three consecutive nums have same value
        int ans=-1;
        while(beg<=end){
                //printf("%d %d\n",beg,end);
                int m = (beg+end)/2;
                if((m==0 || a[m] >= a[m-1]) && (m==n-1 || a[m]>=a[m+1])){
                        ans = m;
                        break;
                }
                else if((m==0 || a[m]>=a[m-1]) && (m==n-1 || a[m]<=a[m-1]))
                        beg = m+1;
                else
                        end = m-1;
        }
        return (ans+1)%n;
}

