#include<stdio.h>
int main(int argc,char** argv){
	int width;
	int height;
	int **a;
	if(argc>2){
		width=atoi(argv[1]);
		height=atoi(argv[2]);
		a=(int**)malloc(sizeof(int*)*height);
		if(a!=NULL){
			for(int i=0;i<height;i++){
				a[i]=(int*)malloc(sizeof(int)*width);
				if(a==NULL){
					fprintf(stderr,"Failed to allocate memory\n");
					for(int j=0;j<i;j++){
						free(a[i]);
					}
					free(a);
					exit(1);
				}else{
				}
			}
			for(int i=0;i<height;i++){
				for(int j=0;j<width;j++){
					a[i][j]=i*width+j;
				}
			}
			for(int i=0;i<height;i++){
				for(int j=0;j<width;j++){
					fprintf(stdout,"%d",a[i][j]);
					if(j!=width-1)fprintf(stdout,",");
				}
				fprintf(stdout,"\n");
			}
			for(int i=0;i<height;i++){
				free(a[i]);
			}
			free(a);
		}else{
			fprintf(stderr,"Failed to allocate memory\n");
			exit(1);
		}
	}else{
		fprintf(stderr,"Usage: %s width height\n",argv[0]);
		exit(1);
	}
	return 0;
}
