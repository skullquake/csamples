#include<stdio.h>
#define FOO 0
#define BAR "BAZ"
#define QUX 1.23
int main(int argc,char** argv){
	fprintf(stdout,"%d\n",FOO);
	fprintf(stdout,"%s\n",BAR);
	fprintf(stdout,"%f\n",QUX);
	return 0;
}
