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
        int sum = maxSum(a, n);
        printf("Sum: %d\n", sum);
fflush(stdin); getchar();        return 0;
}
int maxSum(int *a, int n){
        int max_so_far=0, cur_max=0, i;
        for(i=0; i<n; i++){
                cur_max += a[i];
                if(cur_max < 0)
                        cur_max=0;
                else if(cur_max > max_so_far)
                        max_so_far = cur_max;
        }
        return max_so_far;
}
