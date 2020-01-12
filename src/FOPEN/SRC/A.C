/* Demonstrates the fopen() function */
#include<stdio.h>
int main(int argc,char** argv){
	FILE *fp;
	char ch,filename[40],mode[4];
	while(1){
		/* Input filname and mode. */
		printf("\nEnter a filename: ");
		gets(filename);
		printf("\nEnter a mode (max 3 characters): ");
		gets(mode);
		/* Try to open the file. */
		if((fp=fopen(filename,mode))!=NULL){
			printf(
				"\nSuccesful opening %s in mode %s.\n",
				filename,
				mode
			);
			fclose(fp);
			puts("Enter x to exit, any other to continue.");
			if((ch=getch())=='x')
				break;
			else
				continue;
		}else{
			fprintf(
				stderr,
				"\nError opening file %s in mode %s.\n",
				filename,
				mode
			);
			puts("Enter x to exit, any other to try again.");
			if((ch=getch())=='x')
				break;
			else
				continue;
		}
	}
	return 0;
}
