#include<stdio.h>
#include<stdlib.h>
void foo();
void bar();
int main(int argc,char** argv){
	atexit(foo);
	atexit(bar);
	return 0;
}
void foo(){
	fprintf(stdout,"foo()\n");
}
void bar(){
	fprintf(stdout,"bar()\n");
}
