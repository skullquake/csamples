#include<stdio.h>
void clean(void);
int main(int argc,char** argv){
	atexit(clean);
	{
		fprintf(stdout,"Hello\n");
	}
	{
		FILE* fp=stdout;
		fprintf(fp,"Hello\n");
	}
	return 0;
}
void clean(void){
	fclose(stdout);
}
