/*
 * string output to stderr only
 */
#include<stdio.h>
int main(int argc,char** argv){
	perror("Hello world\n");
	return 0;
}
