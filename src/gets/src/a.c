#include<stdio.h>
int main(int argc,char** argv){
	char buf[80];
	gets(buf);
	fprintf(stdout,"%s\n",buf);
	return 0;
}
