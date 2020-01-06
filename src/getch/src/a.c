/*
 * getch()
 *  a nonstandard function and is present in conio.h header file
 *  which is mostly used by MS-DOS compilers like Turbo C. It is not part
 *  of the C standard library or ISO C, nor is it defined by POSIX
 *  (Source: http://en.wikipedia.org/wiki/Conio.h)
 */
#include<stdio.h>
#include<termios.h>
#include"getch.h"
void printMenu(void){
	fprintf(stdout,
"\
------------------------------------\n\
Menu\n\
------------------------------------\n\
1. Option 1\n\
2. Option 2\n\
q. Quit\n\
Q. Quit\n\
------------------------------------\n\
"
	);
}
int main(int argc,char** argv){
	int done=0;
	int input;
	while(!done){
		printMenu();
		input=getch();
		switch(input){
			case '1':
				fprintf(stdout,"Option 1\n");
				break;
			case '2':
				fprintf(stdout,"Option 2\n");
				break;
			case 'q':
			case 'Q':
				done=1;
				break;
		}

	}
	fprintf(stdout,"Done\n");
	return 0;
}
