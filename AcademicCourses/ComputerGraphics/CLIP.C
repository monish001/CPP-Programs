#include"DRAW.C"
#define ACCEPT(a, b) (!(a|b))
#define REJECT(a, b) (a&b)
#define LEFT 0x1
#define RIGHT 0x2
#define BOTTOM 0x4
#define TOP 0x8
#define false 0
#define true 1
#define getminx() 0
#define getminy() 0
#include<conio.h>
#include<assert.h>
char getCode(const point p){
	char code=0;
	if(p.x<getminx())
		code |= LEFT;
	else if(p.x>getmaxx())
		code |= RIGHT;
	if(p.y<getminy())
		code |= TOP;
	else if(p.y>getmaxy())
		code |= BOTTOM;
	return code;
}
void swap(point* p1, point* p2, char* c1, char* c2){
	char tmp = *c1;
	point p=*p1;
	*c1 = *c2;
	*c2 = tmp;
	*p1=*p2;
	*p2=p;
}
void CohenSutherLineClip(point p1, point p2, const int color){
	char c1 = getCode(p1), c2 = getCode(p2);
	int done=false, print=true;
	printf("Given points %d,%d and %d,%d.\n", p1.x, p1.y, p2.x, p2.y);
	while(!done){
		if(REJECT(c1, c2)){
			done=true;
			print=false;
		}
		else if(ACCEPT(c1, c2))
			done=true;
		else{
			double slope = (p1.y-p2.y)/((double)(p1.x-p2.x));
			printf("Before swap: points %d,%d and %d,%d. Codes %d and %d\n", p1.x, p1.y, p2.x, p2.y, c1, c2);
			getch();
			if(c1 == 0){
				swap(&p1, &p2, &c1, &c2);
				printf("After  swap: points %d,%d and %d,%d. Codes %d and %d\n", p1.x, p1.y, p2.x, p2.y, c1, c2);
			}
			assert(c1!=0);
			if(c1&LEFT){//p1 is in left of window
				p1.y += slope * (getminx()-p1.x);
				p1.x = getminx();
				printf("left\n");
			}else if(c1&RIGHT){
				p1.y -= slope * (p1.x-getmaxx());
				p1.x = getmaxx();
				printf("right\n");
			}
			c1 = getCode(p1);
			if(c1&TOP){//p1 is in top of window
				p1.x += (1.0/slope) * (getminy()-p1.y);
				p1.y = getminy();
				printf("top\n");
			}else if(c1&BOTTOM){
				p1.x -= (1.0/slope) * (p1.y-getmaxy());
				p1.y = getmaxy();
				printf("bottom\n");
			}
			c1 = getCode(p1);
		}
	}
	printf("New points %d,%d and %d,%d.\nPrint Status=%d.\nMin x,y %d,%d\nMax x,y %d,%d\n\n", p1.x, p1.y, p2.x, p2.y, print, getminx(), getminy(), getmaxx(), getmaxy());
	if(print)
		lineDDA(p1,p2, color);
}
