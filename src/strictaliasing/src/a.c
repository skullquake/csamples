#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
void f(uint32_t*a,float*b){
	float c=*b;
	*a=0;
	float d=*b;
	printf("[%p,%p,%f,%f]\n",a,b,c,d);
	/* sample optimization 
	float c=*b;
	*a=0;
	printf("[%p,%p,%f,%f]\n",a,b,c,c);
	*/
}
int main(void){
	uint32_t a=1;
	float    b=2;
	uint32_t*c=(uint32_t*)&b;
	f(&a,&b);
	f(c,&b);
	return EXIT_SUCCESS;
}
