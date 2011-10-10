#include<stdio.h>
#include<conio.h>
#include<math.h>
#include"CLIP.H"
#include<graphics.h>

int main(){
	int gd = DETECT, gm;
	//top
	point p1 = {17,-11}, p2={22, 20};
	//bottom
	point p3 = {40,700}, p4={52, 20};
	//left
	point p5 = {20,200}, p6={-20, 220};
	//right
	point p7 = {20,400}, p8={700, 380};
	//top-left
	point po1 = {-11,-11}, po2={22, 20};
	//top-right
	point po3 = {700,-11}, po4={52, 20};
	//bottom-left
	point po5 = {-20,700}, po6={20, 220};
	//bottom-right
	point po7 = {700,700}, po8={70, 300};
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	
/*	CohenSutherLineClip(p1, p2, YELLOW);
	CohenSutherLineClip(p3, p4, YELLOW);
	CohenSutherLineClip(p5, p6, YELLOW);
	CohenSutherLineClip(p7, p8, YELLOW);
*/	CohenSutherLineClip(po1, po2, YELLOW);
	CohenSutherLineClip(po3, po4, YELLOW);
	CohenSutherLineClip(po5, po6, YELLOW);
	CohenSutherLineClip(po7, po8, YELLOW);

	getch();
	closegraph();
	return 0;
}
