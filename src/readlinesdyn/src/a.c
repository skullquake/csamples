/*
 * read lines into array of strings
 */
#include<stdio.h>
#include"getch.h"
#define BUFSTRD 8
struct Lines{
	char** lines;
	size_t nLines;
};
struct Lines* readlines(struct Lines*,FILE*);
void printLines(struct Lines*);
int main(int argc,char** argv){
	struct Lines lines;
	lines.nLines=0;
	lines.lines=(char**)malloc(sizeof(char*)*BUFSTRD);
	if(lines.lines!=NULL){
		readlines(&lines,stdin);
		fprintf(stdout,"----------------------------------------\n");
		printLines(&lines);
		free(lines.lines);
	}else{
		fprintf(stderr,"Failed to allocate buffer\n");
		exit(1);
	}
	return 0;
}
struct Lines* readlines(struct Lines* lines,FILE* fp){
	if(lines!=NULL){
		size_t bufSz=BUFSTRD;
		char* buf=(char*)malloc(sizeof(buf[0])*bufSz);
		char* bufTmp;
		char cInput;
		int idx=0;
		int lidx=0;
		fprintf(stdout,"Input [q to quit]:\n");
		if(buf!=NULL){
			do{
				cInput=getch();
				fprintf(stdout,"%c",cInput);
				if(cInput=='\n'){
					lines->lines=(char**)realloc(lines->lines,sizeof(lines->lines[0])*(lines->nLines+1));
					lines->lines[lidx]=buf;
					lines->nLines++;
					lidx++;
					bufSz=BUFSTRD;
					buf=(char*)malloc(sizeof(buf[0])*bufSz);
					idx=0;
				}else if(cInput=='q'&&idx==0){
					if(buf!=NULL)free(buf);
				}else{
					if(idx>bufSz-1){
						bufSz+=BUFSTRD;
						bufTmp=(char*)realloc(buf,sizeof(buf[0])*(bufSz+2));
						if(bufTmp==NULL){
							fprintf(stderr,"Failed to reallocate buffer\n");
						}else{
							buf=bufTmp;
						}
					}
					buf[idx]=cInput;
					buf[idx+1]='\0';
					idx++;
				}
			}while(cInput!='q');
			free(buf);
		}else{
			fprintf(stderr,"Failed to allocated buffer\n");
		}
	}else{
		fprintf(stderr,"Lines NULL\n");
	}
	fprintf(stdout,"\n");
	return lines;
}
void printLines(struct Lines* lines){
	if(lines!=NULL){
		for(int i=0;i<lines->nLines;i++){
			fprintf(stdout,"%s\n",lines->lines[i]);
		}
	}else{
		fprintf(stderr,"Lines NULL\n");
	}
}
