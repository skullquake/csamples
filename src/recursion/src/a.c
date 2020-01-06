#include<stdio.h>
int factorial(int a);
int main(int argc,char** argv){
	printf("%d\n",factorial(8));
	return 0;
}
int factorial(int a){
	if(a>0)a+=factorial(a-1);
	return a;
}
