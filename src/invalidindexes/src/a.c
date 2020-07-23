#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
void f(const char*);
int main(void){
	char a[]="01";
	char b[]="ab";
	f((const char*)a);
	f((const char*)b);
	b[-1]='_';
	f((const char*)a);
	f((const char*)b);
	return EXIT_SUCCESS;
}
void f(const char*buf){
	const char*pos=NULL;
	pos=buf;
	fputs("c:",stdout);
	while(*pos!='\0'){fprintf(stdout,"|%16c",*pos++);}
	fprintf(stdout,"|%16c",' ');
	fprintf(stdout,"|\n");
	pos=buf;
	fputs("d:",stdout);
	while(*pos!='\0'){fprintf(stdout,"|%16d",*pos++);}
	fprintf(stdout,"|%16d",*pos++);
	fprintf(stdout,"|\n");
	pos=buf;
	fputs("p:",stdout);
	while(*pos!='\0'){fprintf(stdout,"|%16p",pos++);}
	fprintf(stdout,"|%16p",pos++);
	fprintf(stdout,"|\n");
	pos=buf;
	fprintf(stdout,"  ");
	while(*pos!='\0'){fprintf(stdout,"-----------------"),++pos;}
	fprintf(stdout,"------------------");
	fprintf(stdout,"\n");
	pos=buf;
}
