/*
 * variable length arguments
 * for this you need to include stdarg.h
 * va_start initializes va_list to some size to read from the variable length arguments
 * va_arg gets the next value cast to the specified type
 * va_end ends the loop
 */
#include<stdio.h>
#include<stdarg.h>
int a(int sz,...){
	int acc=0;
	va_list val;                     
	va_start(val,sz);           
	for(int c=0;c<sz;c++){
		acc+=va_arg(val,int);
	}
	va_end(val);
	return acc;
}
int main(int argc,char** argv){
	printf("%d\n",a(0));
	printf("%d\n",a(1,1));
	printf("%d\n",a(2,1,2));
	printf("%d\n",a(3,1,2,3));
	return 0;
}
