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
void putPixelAllOctants(const point center, const int x, const int y, int color){
	putpixel(x+center.x, y+center.y, color);
	putpixel(-x+center.x, y+center.y, color);
	putpixel(x+center.x, -y+center.y, color);
	putpixel(-x+center.x, -y+center.y, color);
	putpixel(y+center.x, x+center.y, color);
	putpixel(-y+center.x, x+center.y, color);
	putpixel(y+center.x, -x+center.y, color);
	putpixel(-y+center.x, -x+center.y, color);
}
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
/*void LineBresenham(const point a, const point b){
//y - p1.y = (x-p1.x)*dy/dx
	int dx = a.x-b.x, dy = a.y-a.x;
	if(abs(dx)<abs(dy)){//If slope is greater than 1
		LineBresenham();
		return;
	}
//D(x, y) = y - (x-x1)*dy/dx - y1
//D(x,y)+D(x,y-1)=2y-1
	int p = 
}*/
