/*
 * pointer to functions
 *  a pointer may hold the address of a function
 *  when the program runs the code for each function is loaded into memory starting at a specific address
 *  a pointer to a function holds the starting address of a function, its entry point
 * declaration
 *  type (*ptr_to_func)(parameter_list);
 *  e.g.
 *   int (*func1)(int x);
 *   int (*func2)(double y,double z);
 *   int (*func3(char *p[]);
 *   void (*func4)();
 */
#include<stdio.h>
float square(float x);
int main(int argc,char** argv){
	float (*p)(float x)=square;
	fprintf(stdout,"%f\n",p(2));
	return 0;
}
float square(float x){
	return x*x;
}
