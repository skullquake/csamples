/*
 * flow control using case evaluation
 */
#include<stdio.h>
int main(int argc,char** argv){
	int i=2;
	switch(i){
		case 0:
			printf("Case 0\n");
			break;
		case 1:
			printf("Case 1\n");
			break;
		case 2:
			printf("Case 2\n");
			break;
		case 3:
			printf("Case 3\n");
			break;
		default:
			printf("Case default\n");
			break;
	}
	return 0;
}
