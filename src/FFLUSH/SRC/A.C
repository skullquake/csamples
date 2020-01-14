/*
 * flushes data from stream buffer to stream
 *  e.g. buffer sent to block device (e.g. disk)
 *
 * note: try and implement these concepts in Mendix
 *
 * When a program terminates (either by reaching the end of main() or
 * executing the exit() function), all streams are automatically
 * flushed and closed. However, it's a good idea to close streams
 * explicitly - particularly those linked to files - as soon
 * as you are finished using them
 *
 * When you create a stream linked to a disk file, a buffer is
 * automatically created and associated with the stream. A buffer
 * is a block of memory used for temporary storage of data written
 * to and read from the file
 *
 * Buffers are needed because disk drives are block-oriented devices,
 * which means that they operate most efficiently when data is read
 * and written in blocks of a certain size. The size of the ideal
 * block differs depending on the specific hardware used and is
 * typically on the order of a few hundred to thousand bytes.
 *
 * The buffer associated with a file stream serves as an interface
 * between the stream (which is character oriented) and the disk
 * hardware (which is block oriented).
 *
 * If a file is not explicitly closed on program termination, data might
 * still be in the buffer that has not been written to the block device.
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
			fflush(fp);
			fprintf(stdout,"done\n");
			if(rand()%2==0){
				fprintf(stdout,"Closing %s\n",filename);
				fclose(fp);
			}else{
				fprintf(stdout,"Not closing %s\n",filename);
			}
		}
	}
	fprintf(stdout,"Closed %d unclosed files\n",fcloseall());
	return 0;
}
