/*
 * int remove(const char *filename);
 * removes a file
 * returns 0 on success
 */
#include<stdio.h>
#include<time.h>
int main(int argc,char** argv){
	char filename[80];
	int numfiles=128;
	int i;
	FILE *fp;
	srand(time(0));
	for(i=0;i<numfiles;i++){
		fp=NULL;
		sprintf(filename,"./out/%d.txt",i);
		fprintf(stdout,"Creating %s...",filename);
		if((fp=fopen(filename,"w"))==NULL){
			fprintf(stderr,"error: failed to open file\n");
		}else{
			fprintf(stdout,"done\n");
			fclose(fp);
		}
	}
	/* remove test */
	for(i=0;i<numfiles;i++){
		sprintf(filename,"./out/%d.txt",i);
		fprintf(stdout,"Removing %s...",filename);
		if(remove(filename)==0){
			fprintf(stdout,"done\n");
		}else{
			fprintf(stderr,"error: failed to remove file\n");
		};
	}
	return 0;
}
