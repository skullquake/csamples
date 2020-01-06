/*
 * ANSI:
 *  * size of char is 1 byte
 *  * size of short is less than or equal to size of int
 *  * size of int is less than or equal to size of long
 *  * size of unsigned is equal to size of int
 *  * size of float is less than or equal to size of double
 */
#include<stdio.h>
int main(int argc,char** argv){
	char           _char;
	short          _short;
	int            _int;
	float          _float;
	double         _double;
	long           _long;
	unsigned char  _unsigned_char;
	unsigned int   _unsigned_int;
	unsigned short _unsigned_short;
	unsigned long  _unsigned_long;
	fprintf(stdout,"_char:           %d\n",sizeof(_char));
	fprintf(stdout,"_short:          %d\n",sizeof(_short));
	fprintf(stdout,"_int:            %d\n",sizeof(_int));
	fprintf(stdout,"_float:          %d\n",sizeof(_float));
	fprintf(stdout,"_double:         %d\n",sizeof(_double));
	fprintf(stdout,"_long:           %d\n",sizeof(_long));
	fprintf(stdout,"_unsigned_char:  %d\n",sizeof(_unsigned_char));
	fprintf(stdout,"_unsigned_int:   %d\n",sizeof(_unsigned_int));
	fprintf(stdout,"_unsigned_short: %d\n",sizeof(_unsigned_short));
	fprintf(stdout,"_unsigned_long:  %d\n",sizeof(_unsigned_long));
	return 0;
}
