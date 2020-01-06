/*
 * & defines the address of
 * * dereferences/declares ptr
 * ** dereferences/declares ptr2ptr
 */
#include<stdio.h>
int main(int argc,char** argv){
	{
		int a=8;
		int *b=&a;
		int **c=&b;
		fprintf(stdout,"%d\n",a);
		fprintf(stdout,"%d\n",*b);
		fprintf(stdout,"%d\n",**c);
	}
	{
		char *a="0123456789abcdef";
		char *b=a;
		char **c=&a;/*ptr2ptr*/
		fprintf(stdout,"%s\n",a);
		fprintf(stdout,"%s\n",b);
		fprintf(stdout,"%s\n",*c);
	}
	return 0;
}
