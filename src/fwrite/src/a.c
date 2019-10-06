#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define BUFSIZE 1024
int main(int argc,char** argv){
	uint8_t* buf=(uint8_t*)malloc(sizeof(uint8_t)*BUFSIZE);
	if(buf!=NULL){
		for(int i=0;i<BUFSIZE;i++){
			buf[i]=0x00;
		}
		FILE* fp=fopen("./out/a.bin","wb");
		if(fp!=NULL){
			fwrite(buf,1,sizeof(uint8_t)*BUFSIZE,fp);
			fclose(fp);
		}else{
			fprintf(stderr,"Could not open file for writing\n");
		}
		free(buf);
	}else{
	}
	return 0;
}
