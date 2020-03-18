/*
 * You use direct file I/O most often when you save data to be read later
 * by the same or different C program. Direct I/O is used only with
 * binary-mode files. With direct output, blocks of data are written
 * from memory to disk. Direct input reverses the process: a block of
 * data is read from disk file into memory. For example, a single direct
 * output function call can write an entire array of type double to disk,
 * and a single direct input function call can read the entire array from
 * disk back into memory.
 *
 * The direct I/O functions are fread() and fwrite()
 */
#include<stdio.h>
/* ---------------------------------------------------------------------- */
/* borland bug: force including floating point library */
static void force_fpf(){float x,*y;y=&x;x=*y;}
/* ---------------------------------------------------------------------- */
#define DATATYPE int
int main(int argc,char** argv){
	FILE *fp;
	int i;
	const char* filename="./out/a.bin";
	int bufsize;
	int nelem;
	int szelem;
	nelem=8;
	szelem=sizeof(DATATYPE);
	bufsize=nelem*szelem;
	/* write */
	{
		int *buf;
		if((fp=fopen(filename,"wb"))==NULL){
			fprintf(
				stderr,
				"Failed to open file %s for writing\n",
				filename
			);
		}else{
			fprintf(
				stdout,
				"Allocating buffer..."
			);
			if(
				(
					buf=(DATATYPE*)malloc(bufsize)
				)==NULL
			){
				fprintf(
					stderr,
					"error: Failed to allocate buffer\n"
				);
			}else{
				fprintf(
					stdout,
					"done\n"
				);
				fprintf(
					stdout,
					"Populating %s...",
					filename
				);
				for(i=0;i<nelem;i++){
					buf[i]=i+8;
				}
				if(fwrite(buf,szelem,nelem,fp)){
					fprintf(
						stdout,
						"done\n",
						filename
					);
				}else{
					fprintf(
						stderr,
						"error: File write failure\n",
						filename
					);
				}
				free(buf);
			}
			fclose(fp);
		}
	}
	/* read */
	{
		int *buf;
		if((fp=fopen(filename,"rb"))==NULL){
			fprintf(
				stderr,
				"Failed to open file %s for reading\n",
				filename
			);
		}else{
			fprintf(
				stdout,
				"Allocating buffer..."
			);
			if(
				(
					buf=(DATATYPE*)malloc(bufsize)
				)==NULL
			){
				fprintf(
					stderr,
					"error: Failed to allocate buffer\n"
				);
			}else{
				fprintf(
					stdout,
					"done\n"
				);
				fprintf(
					stdout,
					"Reading %s...",
					filename
				);
				if(fread(buf,szelem,nelem,fp)){
					fprintf(
						stdout,
						"\n",
						filename
					);
					for(i=0;i<nelem;i++){
						fprintf(
							stdout,
							"%d:%i\n",
							i,
							buf[i]
						);
					}
				}else{
					fprintf(
						stderr,
						"error: Read failure\n",
						filename
					);
				}
				free(buf);
				fprintf(
					stdout,
					"\ndone",
					filename
				);

			}
			fclose(fp);
		}
	}
	return 0;
}
