/*
 * putc() writes a single character to a specified stream
 * its prototype lives in stdio.h 
 */
#include<stdio.h>
int main(int argc,char** argv){
	{
		const char* filename="./out/a.txt";
		FILE *fp;
		char c;
		int i;
		int j;
		if((fp=fopen(filename,"w"))==NULL){
			fprintf(
				stderr,
				"Failed to open file %s for writing\n",
				filename
			);
		}else{
			fprintf(
				stdout,
				"Populating file %s...",
				filename
			);
			for(i=0;i<8;i++){
				c='a';
				for(j=0;j<26;j++){
					putc(c++,fp);
				}
				putc('\n',fp);
			}
			fprintf(
				stdout,
				"done\n"
			);
		}
	}
	return 0;
}
