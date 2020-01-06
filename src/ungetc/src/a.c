/*
 * ungetc places a character back into the input stream
 *  returns ch on success and EOF on fail
 */
#include<stdio.h>
int main(int argc,char** argv){
	char a;
	a=getc(stdin);
	fprintf(stdout,"%c\n",a);
	if(ungetc(a,stdin)!=EOF){
		a='b';
		fprintf(stdout,"%c\n",a);
		a=getc(stdin);
		fprintf(stdout,"%c\n",a);
	}
	return 0;
}
