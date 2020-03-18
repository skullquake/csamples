#include<stdio.h>
#include<stdlib.h>
#define BUFSZ 8
struct Vec2c{
	char x;
	char y;
};
struct Vec2i{
	int x;
	int y;
};
struct Vec2f{
	float x;
	float y;
};
struct Vec2l{
	long x;
	long y;
};
void testVec2c(){
	//write
	{
		int nelem=BUFSZ;
		int i;
		struct Vec2c* arrVec2c=(struct Vec2c*)malloc(sizeof(struct Vec2c)*nelem);
		FILE* fp;
		if(arrVec2c!=NULL){
			for(i=0;i<nelem;i++){
				arrVec2c[i].x=i;
				arrVec2c[i].y=i+1;
			}
			if((fp=fopen("./out/Vec2c.bin","wb"))!=NULL){
				if(fwrite(arrVec2c,sizeof(struct Vec2c)*nelem,1,fp)==1){
				}else{
					fprintf(stderr,"Error: Failed to write to file\n");
				}
				fclose(fp);
			}else{
				fprintf(stderr,"Error: Failed to open file\n");
			}
			free(arrVec2c);
		}else{
			fprintf(stderr,"Error: Failed to allocate buffer\n");
		}
	}
	//read
	{
		long int fsz;
		int nelem;
		int i;
		struct Vec2c* arrVec2c;
		FILE* fp;
		if((fp=fopen("./out/Vec2c.bin","rb"))!=NULL){
			//get file size
			fseek(fp,0,SEEK_END);
			fsz=ftell(fp);
			fseek(fp,0,SEEK_SET);
			//read file
			arrVec2c=(struct Vec2c*)malloc(sizeof(struct Vec2c)*nelem);
			if(arrVec2c!=NULL){
				if(fread(arrVec2c,fsz,1,fp)==1){
					nelem=fsz/sizeof(struct Vec2c);
					for(i=0;i<nelem;i++){
						printf("%d:[%d,%d]\n",i,arrVec2c[i].x,arrVec2c[i].y);
					}
				}else{
					fprintf(stderr,"Error: Failed to read to file\n");
				}
				free(arrVec2c);
			}else{
				fprintf(stderr,"Error: Failed to allocate buffer\n");
			}
			fclose(fp);
		}else{
			fprintf(stderr,"Error: Failed to open file\n");
		}
	}
}
void testVec2i(){
	//write
	{
		int nelem=BUFSZ;
		int i;
		struct Vec2i* arrVec2i=(struct Vec2i*)malloc(sizeof(struct Vec2i)*nelem);
		FILE* fp;
		if(arrVec2i!=NULL){
			for(i=0;i<nelem;i++){
				arrVec2i[i].x=i;
				arrVec2i[i].y=i+1;
			}
			if((fp=fopen("./out/Vec2i.bin","wb"))!=NULL){
				if(fwrite(arrVec2i,sizeof(struct Vec2i)*nelem,1,fp)==1){
				}else{
					fprintf(stderr,"Error: Failed to write to file\n");
				}
				fclose(fp);
			}else{
				fprintf(stderr,"Error: Failed to open file\n");
			}
			free(arrVec2i);
		}else{
			fprintf(stderr,"Error: Failed to allocate buffer\n");
		}
	}
	//read
	{
		long int fsz;
		int nelem;
		int i;
		struct Vec2i* arrVec2i;
		FILE* fp;
		if((fp=fopen("./out/Vec2i.bin","rb"))!=NULL){
			//get file size
			fseek(fp,0,SEEK_END);
			fsz=ftell(fp);
			fseek(fp,0,SEEK_SET);
			//read file
			arrVec2i=(struct Vec2i*)malloc(sizeof(struct Vec2i)*nelem);
			if(arrVec2i!=NULL){
				if(fread(arrVec2i,fsz,1,fp)==1){
					nelem=fsz/sizeof(struct Vec2i);
					for(i=0;i<nelem;i++){
						printf("%d:[%d,%d]\n",i,arrVec2i[i].x,arrVec2i[i].y);
					}
				}else{
					fprintf(stderr,"Error: Failed to read to file\n");
				}
				free(arrVec2i);
			}else{
				fprintf(stderr,"Error: Failed to allocate buffer\n");
			}
			fclose(fp);
		}else{
			fprintf(stderr,"Error: Failed to open file\n");
		}
	}
}
void testVec2f(){
	//write
	{
		int nelem=BUFSZ;
		int i;
		struct Vec2f* arrVec2f=(struct Vec2f*)malloc(sizeof(struct Vec2f)*nelem);
		FILE* fp;
		if(arrVec2f!=NULL){
			for(i=0;i<nelem;i++){
				arrVec2f[i].x=i;
				arrVec2f[i].y=i+1;
			}
			if((fp=fopen("./out/Vec2f.bin","wb"))!=NULL){
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
	}
	//read
	{
		long int fsz;
		int nelem;
		int i;
		struct Vec2f* arrVec2f;
		FILE* fp;
		if((fp=fopen("./out/Vec2f.bin","rb"))!=NULL){
			//get file size
			fseek(fp,0,SEEK_END);
			fsz=ftell(fp);
			fseek(fp,0,SEEK_SET);
			//read file
			arrVec2f=(struct Vec2f*)malloc(sizeof(struct Vec2f)*nelem);
			if(arrVec2f!=NULL){
				if(fread(arrVec2f,fsz,1,fp)==1){
					nelem=fsz/sizeof(struct Vec2f);
					for(i=0;i<nelem;i++){
						printf("%d:[%d,%d]\n",i,arrVec2f[i].x,arrVec2f[i].y);
					}
				}else{
					fprintf(stderr,"Error: Failed to read to file\n");
				}
				free(arrVec2f);
			}else{
				fprintf(stderr,"Error: Failed to allocate buffer\n");
			}
			fclose(fp);
		}else{
			fprintf(stderr,"Error: Failed to open file\n");
		}
	}
}
void testVec2l(){
	//write
	{
		int nelem=BUFSZ;
		int i;
		struct Vec2l* arrVec2l=(struct Vec2l*)malloc(sizeof(struct Vec2l)*nelem);
		FILE* fp;
		if(arrVec2l!=NULL){
			for(i=0;i<nelem;i++){
				arrVec2l[i].x=i;
				arrVec2l[i].y=i+1;
			}
			if((fp=fopen("./out/Vec2l.bin","wb"))!=NULL){
				if(fwrite(arrVec2l,sizeof(struct Vec2l)*nelem,1,fp)==1){
				}else{
					fprintf(stderr,"Error: Failed to write to file\n");
				}
				fclose(fp);
			}else{
				fprintf(stderr,"Error: Failed to open file\n");
			}
			free(arrVec2l);
		}else{
			fprintf(stderr,"Error: Failed to allocate buffer\n");
		}
	}
	//read
	{
		long int fsz;
		int nelem;
		int i;
		struct Vec2l* arrVec2l;
		FILE* fp;
		if((fp=fopen("./out/Vec2l.bin","rb"))!=NULL){
			//get file size
			fseek(fp,0,SEEK_END);
			fsz=ftell(fp);
			fseek(fp,0,SEEK_SET);
			//read file
			arrVec2l=(struct Vec2l*)malloc(sizeof(struct Vec2l)*nelem);
			if(arrVec2l!=NULL){
				if(fread(arrVec2l,fsz,1,fp)==1){
					nelem=fsz/sizeof(struct Vec2l);
					for(i=0;i<nelem;i++){
						printf("%d:[%d,%d]\n",i,arrVec2l[i].x,arrVec2l[i].y);
					}
				}else{
					fprintf(stderr,"Error: Failed to read to file\n");
				}
				free(arrVec2l);
			}else{
				fprintf(stderr,"Error: Failed to allocate buffer\n");
			}
			fclose(fp);
		}else{
			fprintf(stderr,"Error: Failed to open file\n");
		}
	}
}
int main(int argc,char** argv){
	testVec2c();
	testVec2i();
	testVec2f();
	testVec2l();
	return 0;
}
