/*
 * flush all streams
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
		sprintf(filename,".\\out\\%d.txt",i);
		fprintf(stdout,"Creating %s...",filename);
		if((fp=fopen(filename,"w"))==NULL){
			fprintf(stderr,"error: failed to open file\n");
		}else{
			fprintf(stdout,"done\n");
			fprintf(stdout,"Writing %s...",filename);
			fprintf(fp,"%s test data",filename);
			fprintf(stdout,"done\n");
			if(rand()%2==0){
				fprintf(stdout,"Closing %s\n",filename);
				fclose(fp);
			}else{
				fprintf(stdout,"Not closing %s\n",filename);
			}
		}
	}
	fprintf(stdout,"Flushed %d streams\n",flushall());
	fprintf(stdout,"Closed %d unclosed streams\n",fcloseall());
	return 0;
}
