/*
 * fgets reads a line of text from an input stream
 * it allows you to specify the input stream to use and the
 * maximum characters to be input as well as the buffer to
 * store it at
 */
#include<stdio.h>
int main(int argc,char** argv){
	char buf[32];
	buf[0]='\0';
	fprintf(stdout,"Enter text (blank to quit):\n");
	fgets(buf,8,stdin);
	while(buf[0]!='\n'){
		fprintf(stdout,"%s",buf);
		fgets(buf,8,stdin);
	}
	return 0;
}
