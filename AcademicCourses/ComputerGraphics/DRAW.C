#include"draw.h"
//Digital Differencial Analyzer
void lineDDA(const point p1, const point p2, const int color){
	int dx = p2.x-p1.x, dy = p2.y-p1.y;
	int steps = ((abs(dx)>abs(dy))?abs(dx):abs(dy));
	float xInc = dx/(float)steps, yInc = dy/(float)steps;

	int k;
	float x=p1.x, y=p1.y;
	for(k=0; k<=steps; k++){
		putpixel(ROUND(x), ROUND(y), color);
		x += xInc;
		y += yInc;
	}
}
void putPixelAllQuaters(const point center, const int x, const int y, int color){
	putpixel(ROUND(x+center.x), ROUND(y+center.y), color);
	putpixel(ROUND(-x+center.x), ROUND(y+center.y), color);
	putpixel(ROUND(x+center.x), ROUND(-y+center.y), color);
	putpixel(ROUND(-x+center.x), ROUND(-y+center.y), color);
}
//Mid-point ellipse Algorithm
void ellipseMidPoint(const point center, const point radius, const int color){
	int x=0, y = radius.y, a=radius.x, b=radius.y;
	long a2 = a*a, b2 = b*b;
	double p = b2 - a2*b + a2/(double)4;
	while(b2*x < a2*y){
		putPixelAllQuaters(center, x, y, color);
		if(p<0){
			;
		}else{
			y--;
			p+= -2*a2*y;
		}
		p+= 2*b2*x + b2;
		x++;
	}
	p = b2*(x+.5)*(x+.5) + a2*(y-1)*(y-1) - a2 * b2;
	while(y>=0){
		putPixelAllQuaters(center, x, y, color);
		if(p>0){
			p+= -2*a2*y + a2;
		}else{
			x++;
			p+= -2*a2*y + a2 + 2*b2*x;
		}
		y--;
	}
}
void putPixelAllOctants(const point center, const int x, const int y, int color){
	putPixelAllQuaters(center, x, y, color);
	putPixelAllQuaters(center, y, x, color);
}
//Mid-point circle algorithm
void circleBresenham(const point center, const int r, const int color){
//if point P is (x+1,y), outer point
//D(P) = (x+1)^2 + y^2 - r^2
//if point Q is (x+1,y-1), inner point
//D(Q) = (x+1)^2 + (y-1)^2 - r^2

//D(i) = D(P) + D(Q) = 2 (xi+1)^2 + yi^2 + (yi-1)^2 - 2 r^2
//If it is +ve, plot Q else P

//Find recursive D(i+1) in terms of D(i)

	int x=0, y=r;
	int p = 3-2*r;// D(i) for (x,y)=(0,r)
	while(x<=y){
		putPixelAllOctants(center, x, y, color);
		if(p<0)
			p += 4*x+6;
		else{
			--y;
			p += 4*(x-y) +10;
		}
		x++;
	}

}
