/*
 * long ftell(FILE *fp); 
 * To determine the value of a file's position indicator, use ftell().
 * returns -1L on error
 */
#include<stdio.h>
int main(int argc,char** argv){
	const char* filename="./res/a.txt";
	FILE *fp;
	char c;
	long pos;
	if((fp=fopen(filename,"r"))==NULL){
		fprintf(
			stderr,
			"Failed to open file %s\n",
			filename
		);
	}else{
		while((c=fgetc(fp))!=EOF&&c!=NULL){
			pos=ftell(fp);
			if(pos!=-1L){
				fprintf(
					stdout,
					"%lu: %c\n",
					pos,
					c
				);
			}else{
				fprintf(
					stdout,
					"Error: Could not determine position"
				);
			}
		}
		fclose(fp);
	}
	return 0;
}

