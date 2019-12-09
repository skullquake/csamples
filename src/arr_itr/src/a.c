#include<stdio.h>
#define SZ 32
int main(int argc,char** argv){
	int a[SZ];
	int idx=0;
	for(int* p=&a[0];p!=&a[SZ-1];p++) {
		    *p=idx++;
	}
	for(int* p=&a[0];p!=&a[SZ-1];p++) {
		    printf("%d\n",*p);
	}
	return 0;
}
