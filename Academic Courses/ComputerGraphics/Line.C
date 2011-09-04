#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
void LineDDA(int x1, int y1, int x2, int y2){
	int xdiff = abs(x1-x2), ydiff = abs(y1-y2);
	float m = (y2-y1)*1.0/(x2-x1);
	float c = y2 - m*x2;
	if(xdiff>=ydiff){//inc x by 1 and find y iteratively
		int x,y;
		for(x=x1; x<=x2; x++){
			y = m*x + c;
			putpixel(x,y,GREEN);
		}
	}else{
		int x,y;
		for(y=y1; y<=y2; y++){
			x = (y-c)*1.0/m;
			putpixel(x,y,GREEN);
		}
	}
}                             /*
void LineBresenham(int x1, int y1, int x2, int y2){
	int xdiff = abs(x2-x1), ydiff = abs(y2-y1);
	float m=1.0*(y2-y1)/(x2-x1);
	float c=y1-m*x1;
	if(xdiff > ydiff){//increment x by 1 and find y.
		int signOfY = (y2-y1)/ydiff;
		int x;
		float p=1;
		for(x=x1; x<=x2; x++){
			find p;
			if(p<0)
		}
	}else{//inc y by1 and find x

	}
}                               */
int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	circle(200, 100, 150);
	LineDDA(0, 0, 10, 10);
	//LineBresenham(100, 25, 500, 425);
//	LineDDA(105, 20, 325, 420);

	getch();
	closegraph();
	return 0;
}