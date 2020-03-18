#include<stdio.h>
#include<stdlib.h>
#define BUFSZ 128
struct Vec2f{
	float x;
	float y;
};
int main(int argc,char** argv){
	int nelem=BUFSZ;
	int i;
	struct Vec2f* arrVec2f=(struct Vec2f*)malloc(sizeof(struct Vec2f)*nelem);
	FILE* fp;
	if(arrVec2f!=NULL){
		for(i=0;i<nelem;i++){
			arrVec2f[i].x=i;
			arrVec2f[i].y=i+1;
		}
		if((fp=fopen("./out/a.bin","wb"))!=NULL){
			if(fwrite(arrVec2f,sizeof(struct Vec2f)*nelem,1,fp)==1){
			}else{
				fprintf(stderr,"Error: Failed to write to file\n");
			}
			fclose(fp);
		}else{
			fprintf(stderr,"Error: Failed to open file\n");
		}
		free(arrVec2f);
	}else{
		fprintf(stderr,"Error: Failed to allocate buffer\n");
	}
	return 0;
}
