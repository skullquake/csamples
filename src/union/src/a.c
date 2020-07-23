#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<float.h>
typedef union U{
	unsigned char c;
	unsigned short s;
	unsigned int i;
	unsigned long l;
	unsigned long long ll;
	float f;
	double d;
	long double ld;
}U;
int main(void){
	U u;
	memset(&u,0,sizeof(U));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.c,0xFF,sizeof(u.c));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.s,0xFF,sizeof(u.s));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.i,0xFF,sizeof(u.i));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.l,0xFF,sizeof(u.l));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.ll,0xFF,sizeof(u.ll));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.f,0xFF,sizeof(u.f));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.d,0xFF,sizeof(u.d));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.ld,0xFF,sizeof(u.ld));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.c,0x00,sizeof(u.c));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.s,0x00,sizeof(u.s));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.i,0x00,sizeof(u.i));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.l,0x00,sizeof(u.l));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.ll,0x00,sizeof(u.ll));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.f,0x00,sizeof(u.f));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.d,0x00,sizeof(u.d));
	fwrite(&u,sizeof(U),1,stdout);
	memset(&u.ld,0x00,sizeof(u.ld));
	fwrite(&u,sizeof(U),1,stdout);
	return EXIT_SUCCESS;
};
