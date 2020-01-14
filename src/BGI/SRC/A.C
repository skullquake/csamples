#include <dos.h>
#include <stdio.h>
#include <graphics.h>
int main(int argc,char** argv){
	int drv;
	int mod;
	int err;
	int i;
	int j;
	int color;
	drv=DETECT;
	initgraph(
		&drv,
		&mod,
		"\\usr\\bin"
	);
	err=graphresult();
	if(err!=grOk){	
		fprintf(
			stderr,
			" Graphics System Error: %s\n",
			grapherrormsg(err)
		);
		exit(1);
	}
	//outtextxy(0,0,"test");
	for(i=0;i<getmaxy();i++){
		for(j=0;j<getmaxx();j++){
			color=rand()%3;
			switch(color){
				case 0:
					color=WHITE;
					break;
				case 1:
					color=LIGHTGRAY;
					break;
				default:
					color=DARKGRAY;
			};
			putpixel(j,i,color);
		}
	}
	closegraph();
	return 0;
}
/*
//setcolor(rand()%getmaxcolor());
//gotoxy(0,0);
*/
