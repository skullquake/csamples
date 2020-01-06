#include<stdio.h>
void f0();
void f1(int);
void f2(int*);
int  f3();
int* f4();
int  main(int argc,char** argv){
	f0();
	int a=0;
	f1(a);
	printf("%d\n",a);
	f2(&a);
	printf("%d\n",a);
	printf("%d\n",f3());
	int* b=f4();
	if(b!=NULL){
		printf("%d\n",*b);
		free(b);
		b=NULL;
	}
	return 0;
}
void f0(){
}
void f1(int a){
	a++;
}
void f2(int *a){
	if(a!=NULL){
		(*a)++;
	}
}
int  f3(){
	return 0;
}
int* f4(){
	int* a=(int*)malloc(sizeof(int));
	*a=8;
	return a;
}
