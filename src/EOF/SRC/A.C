/*
 * At times you know exactly how long a file is. Then there is no
 * need to be able to detect the file's end.
 * For example writing out an array of 100 element integers 
 * will result in a 200 byte file
 * At other times, however, you don't know how long a file is, but you
 * still want to read data from the file, starting at the beginning
 * and proceeding to the end. There are two ways to detect end-of-file
 * 
 * When reading from a text-mode file character-by-character, you can
 * look for the EOF character. The symbolic constant of EOF is
 * defined in stdio.h as -1, a value never used by a "real" character.
 * When a character input function reads EOF from a text-mode
 * stream, you can be sure that you have reached the end of the file.
 */
#include<stdio.h>
int main(int argc,char** argv){
	FILE *fp;
	char c;
	const char *filename="./res/a.txt";
	if((fp=fopen(filename,"r"))!=NULL){
		while((c=fgetc(fp))!=EOF){
			fputc(c,stdout);
		}
		fprintf(stdout,"\nEOF reached\n");
		fclose(fp);
	}else{
		fprintf(
			stderr,
			"Failed to open file %s for reading\n",
			filename
		);
		exit(1);
	}
	return 0;
}
