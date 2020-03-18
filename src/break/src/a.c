/*
 * facilitates breaking out of flow control, or loops
 */
#include<stdio.h>
int main(int argc,char** argv){
	int i;
	for(i=0;i<4;i++){
		printf("for:%d:0\n",i);
		printfu"for:%d:1\n",i);
		if(i>1)
			break;
		printf("for:%d:2\n",i);
		printf("for:%d:3\n",i);
	}
	i=0;
	while(1){
		printf("while:%d:0\n",i);
		printf("while:%d:1\n",i);
		if(i>1)
			break;
		printf("while:%d:2\n",i);
		printf("while:%d:3\n",i);
		i++;
	}
	i=0;
	do{
		printf("dowhile:%d:0\n",i);
		printf("dowhile:%d:1\n",i);
		if(i>1)
			break;
		printf("dowhile:%d:2\n",i);
		printf("dowhile:%d:3\n",i);
		i++;
	}while(1);
	return 0;
}
