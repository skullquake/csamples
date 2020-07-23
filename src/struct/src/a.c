#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>
typedef struct S{
	unsigned int v;
	unsigned int x;
	unsigned int y;
	unsigned int z;
}S;
int main(void){
	S*s=NULL;
	if(fwrite(memcpy(s=(S*)malloc(sizeof(S)),&(S){UINT_MAX>>0,UINT_MAX>>8,UINT_MAX>>16,UINT_MAX>>24},sizeof(S)),sizeof(S),1,stdout))free(s);
	fwrite(&(S){0,0,0,0},sizeof(S),1,stdout);
	s=&(S){UINT_MAX,0,UINT_MAX,0};
	fwrite(s,sizeof(S),1,stdout);
	*(((unsigned int*)s)+1)=UINT_MAX;
	fwrite(s,sizeof(S),1,stdout);
	*(((unsigned int*)s)+0)=0;
	*(((unsigned int*)s)+1)=0;
	*(((unsigned int*)s)+2)=0;
	*(((unsigned int*)s)+3)=0;
	fwrite(s,sizeof(S),1,stdout);
	*(((unsigned int*)s)+0)=UINT_MAX;
	*(((unsigned int*)s)+1)=0;
	*(((unsigned int*)s)+2)=UINT_MAX;
	*(((unsigned int*)s)+3)=0;
	fwrite(s,sizeof(S),1,stdout);
	*(((unsigned int*)s)+0)=0;
	*(((unsigned int*)s)+1)=UINT_MAX;
	*(((unsigned int*)s)+2)=0;
	*(((unsigned int*)s)+3)=UINT_MAX;
	fwrite(s,sizeof(S),1,stdout);
	return EXIT_SUCCESS;
}
