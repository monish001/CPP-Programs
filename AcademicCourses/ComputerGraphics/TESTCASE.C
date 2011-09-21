#include<stdio.h>
#include<conio.h>
#include<math.h>
#include"draw.c"
int main(){
	int gd = DETECT, gm;
	point p1 = {100,70}, p2={325, 325};
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	lineDDA(p1, p2, YELLOW);
	circleBresenham(p2, 161, RED);
	circleBresenham(p1, 100, RED);
	getch();
	closegraph();
	return 0;
}