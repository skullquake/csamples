#include<stdio.h>
int main(int argc,char** argv){
	int a[8];
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
		a[i]=i;
	}
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
