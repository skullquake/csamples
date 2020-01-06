#include<stdio.h>
int main(int argc,char** argv){
	int i;
	int j;
	fprintf(stdout,"Enter i: \n");
	fscanf(stdin,"%d",&i);
	fprintf(stdout,"Enter j: \n");
	fscanf(stdin,"%d",&j);
	fprintf(stdout,"%d*%d=%d\n",i,j,i*j);
	return 0;
}
