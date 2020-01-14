/*
 * Precise control over a stream's position indicator is possible
 * with fseek(). You can set the position indicator anywhere in the file.
 * The function prorotype, in stdio.h is
 * int fseek(FILE *fp,long offset,int origin);
 * Possible values for origin
 *  SEEK_SET: Move the indicator offset bytes from the beginning
 *            of the file
 *  SEEK_CUR: Move the indicator offset bytes from its current position
 *  SEEK_END: Move the indicator offset bytes from the end of the file
 *  fseek() returns 0 if the indicator was successfully moved or
 *  nonzero if an error occured
 */
#include<stdio.h>
#define MAX 50
int main(int argc,char** argv){
	FILE *fp;
	int data,count,array[MAX];
	long offset;
	const char *filename="./out/a.bin";
	/* Initialize the array. */
	for(count=0;count<MAX;count++)
		array[count]=count*10;
	/* Open a binary file for writing */
	if((fp=fopen(filename,"wb"))==NULL){
		fprintf(
			stderr,
			"Failed to open file %s for writing\n",
			filename
		);
		exit(1);
	}
	/* Write the array to the file, then close it. */
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
	/* Ask user which element to read. Input the element */
	/* and display it, quitting when -1 is entered. */
	while(1){
		printf(
			"Enter element to read, 0-%d, -1 to quit: ",
			MAX-1
		);
		scanf("%ld",&offset);
		if(offset<0)
			break;
		else if(offset>MAX-1)
			continue;
		/* Move the position indicator to the specified element */
		if((fseek(fp,(offset*sizeof(array[0])),SEEK_SET))!=NULL){
			fprintf(stderr,"Error using fseek()\n");
			exit(1);
		}
		/* Read in a single integer. */
		fread(&data,sizeof(array[0]),1,fp);
		printf(
			"Element %ld has value %d.\n",
			offset,
			data
		);
	}
	return 0;
}
