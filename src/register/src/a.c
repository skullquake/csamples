#include<stdio.h>
int main(int argc,char** argv){
	register int i=0;
	for(i=0;i<8;i++){
		fprintf(stdout,"%d\n",i);
	}
	return 0;
}
