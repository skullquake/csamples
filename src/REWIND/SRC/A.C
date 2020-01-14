/*
 * void rewind(FILE*)
 * Use rewind if you want to move the file stream back to the beginning
 */
#include<stdio.h>
int main(int argc,char** argv){
	const char* filename="./res/a.txt";
	FILE *fp;
	char c;
	if((fp=fopen(filename,"r"))==NULL){
		fprintf(
			stderr,
			"Failed to open file %s\n",
			filename
		);
	}else{
		fprintf(
			stdout,
			"Position: %lu\n",
			ftell(fp)
		);
		while((c=fgetc(fp))!=EOF&&c!=NULL){}
		fprintf(
			stdout,
			"Position: %lu\n",
			ftell(fp)
		);
		rewind(fp);
		fprintf(
			stdout,
			"Position: %lu\n",
			ftell(fp)
		);
		fclose(fp);
	}
	return 0;
}

