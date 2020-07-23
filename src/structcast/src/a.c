#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdint.h>
#include<assert.h>
typedef struct S0{
	uint32_t x;
	uint32_t y;
	uint32_t z;
}S0;
typedef struct S1{
	float x;
	float y;
	float z;
}S1;
int main(void){
	printf("sizeof(S0): %zu\n",sizeof(S0));
	printf("sizeof(S1): %zu\n",sizeof(S1));
	assert(sizeof(S0)==sizeof(S1));
	S0 s0={1,2,3};
	S1 s1={0.1,0.2,0.3};
	S0*ps0=NULL;
	S1*ps1=NULL;
	printf("[%16u,%16u,%16u]\n",s0.x,s0.y,s0.z);
	printf("[%16f,%16f,%16f]\n",s1.x,s1.y,s1.z);
	ps0=&s0;
	ps1=&s1;
	printf("[%16u,%16u,%16u]\n",(*ps0).x,(*ps0).y,(*ps0).z);
	printf("[%16f,%16f,%16f]\n",(*ps1).x,(*ps1).y,(*ps1).z);
	ps0=(S0*)&s1;
	ps1=(S1*)&s0;
	printf("[%16u,%16u,%16u]\n",(*ps0).x,(*ps0).y,(*ps0).z);
	printf("[%16f,%16f,%16f]\n",(*ps1).x,(*ps1).y,(*ps1).z);
	return EXIT_SUCCESS;
}
