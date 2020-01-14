/*
 * int fcloseall(void);
 *  closes all open streams except standard ones
 *  flushes any stream buffers that needs to be flushed
 *  returns number of streams closed
 */
#include<stdio.h>
#include<time.h>
int main(int argc,char** argv){
	char filename[80];
	int numfiles=8;
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
			fprintf(stdout,"done:");
			if(rand()%2==0){
				fprintf(stdout,"closing\n");
				fclose(fp);
			}else{
				fprintf(stdout,"not closing\n");
			}
		}
	}
	fprintf(stdout,"Closed %d unclosed files\n",fcloseall());
	return 0;
}
