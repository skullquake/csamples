/*
 * to write a line of characters to a stream
 * use the library function fputs()
 *  char fputs(char *str,FILE *fp)
 * the string in str is written to stream fp, minus the trailing '\0'
 */
#include<stdio.h>
#define BUFSIZE 80
int main(int argc,char** argv){
	{
		const char* filename="./out/a.txt";
		FILE* fp;
		char buf[BUFSIZE];
		int numlines=8;
		int lidx;
		if((fp=fopen(filename,"w"))==NULL){
			fprintf(
				stderr,
				"Failed to open %s for writing\n",
				filename
			);
		}else{
			for(lidx=0;lidx<numlines;lidx++){
				sprintf(buf,"%d*%d:%d\n",lidx,lidx,lidx*lidx);
 				if(fputs(buf,fp)>=0){
					fprintf(
						stdout,
						"Line %d written\n",
						lidx
					);
				}
			}
			fclose(fp);
		}
	}
	return 0;
}
