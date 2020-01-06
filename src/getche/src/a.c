#include<stdio.h>
#include"getch.h"
/*
 * getch echoes to stdout and gets character input
 */
#define BUFSTRD 8
int main(int argc,char** argv){
	{
		char a='a';
		char b='\n';
		putchar(a);
		putchar(b);
	}
	{
		size_t bufSz=BUFSTRD;
		char* buf=(char*)malloc(sizeof(buf[0])*bufSz);
		char* bufTmp;
		char cInput;
		int idx=0;
		fprintf(stdout,"Input [q to quit]:\n");
		if(buf!=NULL){
			do{
				cInput=getche();
				if(idx>bufSz-1){
					bufSz+=BUFSTRD;
					fprintf(stdout,"\nReallocating..[%d]\n",bufSz);
					bufTmp=(char*)realloc(buf,sizeof(buf[0])*(bufSz+2));//not +2 (https://www.reddit.com/r/C_Programming/comments/9q5tt9/problem_with_dynamically_loading_from_input/)
					if(buf==NULL){
						fprintf(stderr,"Failed to reallocate buffer\n");
						free(buf);
					}else{
						buf=bufTmp;
					}
				}
				buf[idx]=cInput;
				buf[idx+1]='\0';
				idx++;
				//putchar(cInput);
				fprintf(stdout,"%s\n",buf);
			}while(cInput!='q');
			free(buf);
		}else{
			fprintf(stderr,"Failed to allocated buffer\n");
			exit(1);
		}
	}
	return 0;
}
