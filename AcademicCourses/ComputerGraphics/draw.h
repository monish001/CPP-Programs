#define ROUND(a) (int)(a+0.5)
#include<graphics.h>
typedef struct point{int x; int y;} point;

void lineDDA(const point p1, const point p2, const int color);
void circleBresenham(const point center, const int r, const int color);
void ellipseMidPoint(const point center, const point radius, const int color);

