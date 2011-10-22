#define ROUND(a) (int)(a+0.5)
#include<graphics.h>
typedef struct point{int x; int y;} point;

void _boundaryFill4(const int x, const int y, const int boundaryColor, const int newColor);
void _floodFill4(const int x, const int y, const int defaultColor, const int fillColor);
void lineDDA(const point p1, const point p2, const int color);
void circleBresenham(const point center, const int r, const int color);
void ellipseMidPoint(const point center, const point radius, const int color);

void boundaryFill4(const point aPoint, const int boundaryColor, const int newColor);
void floodFill4(const point p ,const int defaultColor, const int fillColor);
void putPixelAllOctants(const point center, const int x, const int y, int color);
void putPixelAllQuaters(const point center, const int x, const int y, int color);

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
void _boundaryFill4(const int x, const int y, const int boundaryColor, const int newColor){
	if(getpixel(x, y)==boundaryColor || getpixel(x,y)==newColor || x<0 || y<0 || x>getmaxx() || y>getmaxy())
		return;
	delay(1);
	putpixel(x,y,newColor);
	_boundaryFill4(x-1, y, boundaryColor,newColor);
	_boundaryFill4(x+1, y, boundaryColor,newColor);
	_boundaryFill4(x, y-1, boundaryColor,newColor);
	_boundaryFill4(x, y+1, boundaryColor,newColor);
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
void boundaryFill4(const point p, const int boundaryColor, const int newColor){
	_boundaryFill4(p.x, p.y, boundaryColor, newColor);
}
void _floodFill4(const int x, const int y, const int defaultColor, const int fillColor){
	if(getpixel(x, y)!=defaultColor || getpixel(x,y)==fillColor || x<0 || y<0 || x>getmaxx() || y>getmaxy())
		return;
	delay(5);
	putpixel(x,y,fillColor);
	_floodFill4(x-1, y, defaultColor,fillColor);
	_floodFill4(x+1, y, defaultColor,fillColor);
	_floodFill4(x, y-1, defaultColor,fillColor);
	_floodFill4(x, y+1, defaultColor,fillColor);
}
void floodFill4(const point p ,const int defaultColor, const int fillColor){
	_floodFill4(p.x, p.y, defaultColor, fillColor);
}
