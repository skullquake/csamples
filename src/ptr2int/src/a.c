#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
int main(void){
	unsigned long a=42;
	printf(" &a: %p\n", &a);
	unsigned long*ap=(unsigned long*)&a;
	printf("&ap: %p\n",&ap);
	printf(" ap: %p\n", ap);
	printf("*ap: %zu\n",*ap);
	unsigned long b=(unsigned long)ap;
	printf(" &b: %p\n", &b);
	printf("  b: 0x%lx\n", b);
	ap=(unsigned long*)b;
	printf("&ap: %p\n",&ap);
	printf(" ap: %p\n", ap);
	printf("*ap: %zu\n",*ap);
	return EXIT_SUCCESS;
}
