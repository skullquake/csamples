#include<stdio.h>
#define WIDTH 8
#define HEIGHT 8
int main(int argc,char** argv){
	int a[WIDTH][HEIGHT];
	for(int i=0;i<HEIGHT;i++){
		for(int j=0;j<WIDTH;j++){
			a[i][j]=i*WIDTH+j;
		}
	}
	for(int i=0;i<HEIGHT;i++){
		for(int j=0;j<WIDTH;j++){
			fprintf(stdout,"%d",a[i][j]);
			if(j!=WIDTH-1)fprintf(stdout,",");
		}
		fprintf(stdout,"\n");
	}
	return 0;
}
