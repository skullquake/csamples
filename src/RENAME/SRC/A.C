/*
 * int rename(const char *oldname,const char *newname);
 * The rename() function changes the name of an existing disk file.
 * The function retuns 0 on succes
 */
#include<stdio.h>
#include<time.h>
int main(int argc,char** argv){
	char filenamesrc[80];
	char filenametgt[80];
	int numfiles=32;
	int i;
	FILE *fp;
	srand(time(0));
	for(i=0;i<numfiles;i++){
		fp=NULL;
		sprintf(filenamesrc,"./out/%d.txt",i);
		fprintf(stdout,"Creating %s...",filenamesrc);
		if((fp=fopen(filenamesrc,"w"))==NULL){
			fprintf(stderr,"error: failed to open file\n");
		}else{
			fprintf(stdout,"done\n");
			fclose(fp);
		}
	}
	/* rename test */
	for(i=0;i<numfiles;i++){
		sprintf(filenamesrc,"./out/%d.txt",i);
		sprintf(filenametgt,"./out/_%d.txt",i);
		fprintf(stdout,"Renaming %s...",filenamesrc);
		if(rename(filenamesrc,filenametgt)==0){
			fprintf(stdout,"done\n");
		}else{
			fprintf(stderr,"error: failed to rename file %s\n",filenamesrc);
		};
	}
	return 0;
}
