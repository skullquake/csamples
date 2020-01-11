/*
 * Inputs a list of strings from the keyboard, sorts them,
 * then displays them on the screen
 */
#include<stdio.h>
#include<string.h>
#define MAXLINES 25
char *lines[MAXLINES];
int get_lines(char**);
/* ** issue: no deallocation function provided in example */
void sort(char**,int);
void print_strings(char**,int);
int main(int argc,char** argv){
	int number_of_lines;
	/* Read in the lines from the keyboard. */
	number_of_lines=get_lines(lines);
	if(number_of_lines<0){
		puts(" Memory allocation error");
		exit(-1);
	}
	sort(lines,number_of_lines);
	print_strings(lines,number_of_lines);
	exit(0);
}
int get_lines(char **lines){
	int n=0;
	char buffer[80];/* Temporary storage for each line. */
	/* ** issue: exceeding buffer size??? how to handle */
	while((n<MAXLINES)&&(gets(buffer)!=0)&&(buffer[0]!='\0')){
		if((lines[n]=(char*)malloc(strlen(buffer)+1))==NULL)
			/* issue: propper deallocation on failure */
			return -1;
		/* issue: handle strcpy failure */
		strcpy(lines[n++],buffer);
	}
	return n;
}
void sort(char **p,int n){
	/* ** note: brute force sort */
	int a,b;
	char *x;
	for(a=0;a<n;a++){
		for(b=0;b<n-1;b++){
			if(strcmp(p[b],p[b+1])>0){
				x=p[b];
				p[b]=p[b+1];
				p[b+1]=x;
			}
		}
	}
}
void print_strings(char **p,int n){
	int count;
	for(count=0;count<n;count++)
		printf("\n%s ",p[count]);
}
