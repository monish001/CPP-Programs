#include<stdio.h>
#include<conio.h>
#include<math.h>
#include"draw.c"
int main(){
	int gd = DETECT, gm;
	point p1 = {100,100}, p2={325, 325}, radius={70,180};//try to tak it as long
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	lineDDA(p1, p2, YELLOW);
	circleBresenham(p2, 161, GREEN);
	ellipseMidPoint(p1, radius, GREEN);
	circleBresenham(p1, 100, RED);
	getch();
	closegraph();
	return 0;
}