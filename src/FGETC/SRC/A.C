/*
 * there are three character input functions:
 *  getc() for a single character
 *  fgetc() for a single character
 *  fgets() for lines
 * getc() and fgetc() are identical and can be used interchangably 
 */
#include<stdio.h>
int main(int argc,char** argv){
	/* getc() */
	{
		const char* filename="./res/a.txt";
		FILE* fp;
		char c;
		int cidx;
		fprintf(stdout,"getc() test\n");
		if((fp=fopen(filename,"r"))==NULL){
			fprintf(
				stderr,
				"Failed to open file %s\n",
				filename
			);
		}else{
			cidx=0;
			while((c=fgetc(fp))!=EOF&&c!=NULL){
				fprintf(stdout,"%d:",cidx++);
				switch(c){
					case '\r':
						fprintf(stdout,"Character read: \\r\n");
						break;
					case '\n':
						fprintf(stdout,"Character read: \\n\n");
						break;
					default:
						fprintf(stdout,"Character read: %c\n",c);
				}
			}
			fclose(fp);
		}
	}
	/* fgetc() */
	{
		const char* filename="./res/a.txt";
		FILE* fp;
		char c;
		int cidx;
		fprintf(stdout,"fgetc() test\n");
		if((fp=fopen(filename,"r"))==NULL){
			fprintf(
				stderr,
				"Failed to open file %s\n",
				filename
			);
		}else{
			cidx=0;
			while((c=fgetc(fp))!=EOF&&c!=NULL){
				fprintf(stdout,"%d:",cidx++);
				switch(c){
					case '\r':
						fprintf(stdout,"Character read: \\r\n");
						break;
					case '\n':
						fprintf(stdout,"Character read: \\n\n");
						break;
					default:
						fprintf(stdout,"Character read: %c\n",c);
				}
			}
			fclose(fp);
		}
	}

	return 0;
}
