/**
* EightPuzzle.c
* Goal State:
*  12
* 345
* 789
* 
* Strategy: Steepest Ascent Hill Climbing
* heuristic() needs to be improved
* In Windows XP, runs well in Dev-Cpp but not in Code::Blocks
*/
#include<stdio.h>
#define INF_INT 32500
int heuristic(int a[]){//return number of correctly placed blocks
	int ans=0;
	int i;
	for(i=0; i<9; i++)
		ans += abs(a[i]-i) + (a[i]==i);
	return ans;
}
void printBoard(int a[]){
	int i,j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++)
			(a[i*3+j]!=0)?printf("%d", a[i*3+j]):fputs(" ", stdout);
		puts("");
	}
	puts("");
}
int posOfSpace(int a[]){
	int i;
	for(i=0; i<9; i++)
		if(a[i]==0)
			break;
	return i;
}
int min(int a, int b){
	return (a<b)?a:b;
}
int chooseBest(int a[]){
	int pres_h = heuristic(a);
	int b[9], bh=INF_INT, c[9], ch=INF_INT, d[9], dh=INF_INT, e[9], eh=INF_INT;
	int i;
	for(i=0; i<9; i++)
		b[i]=c[i]=d[i]=e[i]=a[i];
	int posSpace = posOfSpace(a);
	if(posSpace/3 != 0){//empty block not in first row
		b[posSpace] ^= b[posSpace-3] ^= b[posSpace] ^= b[posSpace-3]; //swap
		bh = heuristic(b);
	}
	if(posSpace/3 != 2){//empty block not in last row
		c[posSpace] ^= c[posSpace+3] ^= c[posSpace] ^= c[posSpace+3]; //swap
		ch = heuristic(c);
		//printf("heuristic value to move  up: %d", );
	}
	if(posSpace%3 != 0){//empty block not in first col
		d[posSpace] ^= d[posSpace-1] ^= d[posSpace] ^= d[posSpace-1]; //swap
		dh = heuristic(d);
	}
	if(posSpace%3 != 2){//empty block not in last col
		e[posSpace] ^= e[posSpace+1] ^= e[posSpace] ^= e[posSpace+1]; //swap
		eh = heuristic(e);
	}
	int min_h = min(min(bh, ch), min(dh, eh));
	if(pres_h < min_h)
		return 0;//no better option available

	if(min_h == bh)
		memcpy(a, b, 9*sizeof(int));
	else if(min_h==ch)
		memcpy(a, c, 9*sizeof(int));
	else if(min_h==dh)
		memcpy(a, d, 9*sizeof(int));
	else
		memcpy(a, e, 9*sizeof(int));

	return 1;
}
int main(){
//	int a[] = {1,2,4,6,8,3,0,7,5};
	int a[] = {0,2,4, 1,8,3, 6,7,5};
	printBoard(a);
	int NoBetterStateExists = 0;
	while(heuristic(a) != 0){
		if(chooseBest(a) == 0){
			//printBoard(a);
			NoBetterStateExists = 1;
			break;
		}
		getch();
		printBoard(a);
	}
	(NoBetterStateExists)?(puts("No Better State Exists")):(puts("Goal State Reached."));
	puts("Press any key to exit.");
	getch();
}
