/*
 * To copy a stream open the source file for reading in binary mode,
 * open the target stream for writing in binary mode, read data from
 * the source stream, and write the data to the targetstream until
 * the end of the source stream is reached
 */
#include<stdio.h>
#include<time.h>
/* ---------------------------------------------------------------------- */
/* borland bug: force including floating point library */
static void force_fpf(){float x,*y;y=&x;x=*y;}
/* ---------------------------------------------------------------------- */
int main(int argc,char** argv){
	char filenamesrc[80];
	char filenametgt[80];
	int numfiles=32;
	int i;
	int j;
	FILE *fpsrc;
	FILE *fptgt;
	srand(time(0));
	for(i=0;i<numfiles;i++){
		fpsrc=NULL;
		sprintf(filenamesrc,"./out/%d.txt",i);
		fprintf(stdout,"Creating %s...",filenamesrc);
		if((fpsrc=fopen(filenamesrc,"w"))==NULL){
			fprintf(stderr,"error: failed to open file\n");
		}else{
			for(j=0;j<8;j++){
				fwrite(&i,sizeof(i),1,fpsrc);
			}
			fprintf(stdout,"done\n");
			fclose(fpsrc);
		}
	}
	/* copy test */
	for(i=0;i<numfiles;i++){
		sprintf(filenamesrc,"./out/%d.txt",i);
		sprintf(filenametgt,"./out/_%d.txt",i);
		fprintf(stdout,"Copying %s > %s...",filenamesrc,filenametgt);
		fpsrc=NULL;
		if((fpsrc=fopen(filenamesrc,"rb"))==NULL){
			fprintf(stderr,"error: failed to open %s for reading\n",filenamesrc);
		}else{
			fptgt=NULL;
			sprintf(filenametgt,"./out/_%d.txt",i);
			if((fptgt=fopen(filenametgt,"wb"))==NULL){
				fprintf(stderr,"error: failed to open % for writing\n",filenametgt);
			}else{
				fprintf(stdout,"done\n");
				fclose(fptgt);
			}
			fclose(fptgt);
		}
	}
	return 0;
}
