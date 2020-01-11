/*
 * read lines into array of strings
 */
#include<stdio.h>
#define NUMLINES 80
#define NUMCOLS 80
int readlines();
void printlines(int);
char lines[NUMLINES][NUMCOLS];
int main(int argc,char** argv){
	sprintf(lines[0],"asdf");
	size_t numlines=readlines();
	printlines(numlines);
	return 0;
}
int readlines(){
	int i=0;
	for(;i<NUMLINES;i++){
		fgets(lines[i],80,stdin);
		if(lines[i][0]=='\n'){
			i==0?0:i-1;
			break;
		}else{
			lines[i][strlen(lines[i])-1]='\0';
		}
	}
	return i;
}
void printlines(int nlines){
	for(size_t i=0;i<nlines;i++){
		fprintf(stdout,"%s\n",lines[i]);
	}
}
