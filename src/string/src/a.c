/*
 * int strcmp ( const char *s1, const char *s2 );
 * performs lexical comparison
 * char *strcat ( char *dest, const char *src );
 * concatenates src to dest, assumes dest is large enough
 * size_t strlen ( const char *s );
 * obtains string length
 */
#include<stdio.h>
#include<string.h>
int main(int argc,char** argv){
	char buf[128];
	const char *a="lorem";
	const char *b="ipsum";
	printf("%d\n",strcmp(a,a));
	printf("%d\n",strcmp(a,b));
	printf("%d\n",strcmp(b,a));
	printf("%d\n",strcmp(b,b));
	printf("%s\n",strcat(buf,a));
	printf("%s\n",strcat(buf,b));
	printf("%s\n",buf);
	printf("%d\n",strlen(a));
	printf("%d\n",strlen(b));
	printf("%d\n",strlen(buf));
	return 0;
}
