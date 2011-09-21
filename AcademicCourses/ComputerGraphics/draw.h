#define ROUND(a) (int)(a+0.5)
#include<graphics.h>
typedef struct point{int x; int y;} point;

void lineDDA(const point, const point, const int);
void circleBresenham(const point, const int, const int);

