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
 *
 * With a binary-mode stream, you cannot detect the end-of-file by looking
 * for -1 because a byte of data from a binary stream could have that value
 * which would result in premature end of input. Instead, you can use the
 * library function feof() (which can be used with both binary- and 
 * text mode files)
 *
 * int feof(FILE *fp)
 *
 * feof() returns 0 if the end of the file has been reached
 */
#include<stdio.h>
#define MAX 50
int main(int argc,char** argv){
	FILE *fp;
	int data,count,array[MAX];
	long offset;
	const char *filename="./out/a.bin";
	for(count=0;count<MAX;count++)
		array[count]=count*10;
	if((fp=fopen(filename,"wb"))==NULL){
		fprintf(
			stderr,
			"Failed to open file %s for writing\n",
			filename
		);
		exit(1);
	}
	if((fwrite(array,sizeof(array[0]),MAX,fp))!=MAX){
		fprintf(
			stderr,
			"Error writing to file %s\n",
			filename
		);
		exit(1);
	}
	fclose(fp);
	if((fp=fopen(filename,"rb"))==NULL){
		fprintf(
			stderr,
			"Failed to open file %s for reading\n",
			filename
		);
		exit(1);
	}
	while(!feof(fp)){
		fread(&data,sizeof(array[0]),1,fp);
		fprintf(
			stdout,
			"%d\n",
			data
		);
	}
	fclose(fp);
	fprintf(
		stdout,
		"feof() returned true: End of file\n"
	);
	return 0;
}
