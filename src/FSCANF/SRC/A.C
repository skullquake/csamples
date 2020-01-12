/* Reading formatted file data with fscanf(). */
#include<stdio.h>
/* ---------------------------------------------------------------------- */
/* borland bug: force including floating point library */
static void force_fpf(){float x,*y;y=&x;x=*y;}
/* ---------------------------------------------------------------------- */
int main(int argc,char** argv){
	FILE *fp;
	float f1,f2,f3,f4,f5;
	if((fp=fopen("./res/a.txt","r"))==NULL){
		fprintf(stderr,"Error opening file.");
		exit(1);
	}
	fscanf(
		fp,
		"%f %f %f %f %f",
		&f1,
		&f2,
		&f3,
		&f4,
		&f5
	);
	printf(
		"%f %f %f %f %f\n",
		f1,
		f2,
		f3,
		f4,
		f5
	);
	return 0;
}
