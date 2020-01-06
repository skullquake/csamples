#include<stdio.h>
void foo();
int main(int argc,char** argv){
	foo();
	foo();
	foo();
	return 0;
}
void foo(){
	static int x=0;
	printf("%d\n",x);
	x++;
}
