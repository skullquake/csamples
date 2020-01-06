/*
 * todo: error checking
 */
#include<stdlib.h>
#include<stdio.h>
int main(int argc,char** argv){
	int width;
	int height;
	int depth;
	int ***a;
	if(argc>3){
		width=atoi(argv[1]);
		height=atoi(argv[2]);
		depth=atoi(argv[3]);
		a=(int***)malloc(sizeof(int**)*height);
		for(int i=0;i<height;i++){
			a[i]=(int**)malloc(sizeof(int*)*width);
			for(int j=0;j<width;j++){
				a[i][j]=(int*)malloc(sizeof(int)*depth);
			}
		}
		int idx=0;
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				for(int k=0;k<depth;k++){
					a[i][j][k]=idx++;
				}
			}
		}
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				for(int k=0;k<depth;k++){
					fprintf(stdout,"%d",a[i][j][k]);
					if(k<depth-1)fprintf(stdout,",");
				}
				fprintf(stdout,"\n");
			}
			fprintf(stdout,"\n");
		}
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				free(a[i][j]);
			}
			free(a[i]);
		}
		free(a);

	}else{
		fprintf(stderr,"Usage: %s width height\n",argv[0]);
		exit(1);
	}
	return 0;
}
