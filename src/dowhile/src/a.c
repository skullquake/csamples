/*
 * facilitates continuous condition based flow control
 */
#include<stdio.h>
int main(int argc,char** argv){
	int i=0;
	do{
		printf("%d\n",i);
	}while(++i<4);
	return 0;
}
