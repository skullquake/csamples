#include<stdio.h>
#define QUIT 3
void print_menu(void);
void handle_selection(int);
void action0(void);
void action1(void);
int done=0;
int main(int argc,char** argv){
	int choice;
	while(!done){
		print_menu();
		fscanf(stdin,"%d",&choice);
		handle_selection(choice);
	}
	return 0;
}
void print_menu(void){
	printf(
"\
----------------------------------------\n\
Menu\n\
----------------------------------------\n\
1. Sum\n\
2. Product\n\
0. Quit\n\
----------------------------------------\n"
	);
}
void handle_selection(int choice){
	switch(choice){
		case 0:
			done=1;
			break;
		case 1:
			action0();
			break;
		case 2:
			action1();
			break;
		default:
			fprintf(stderr,"Invalid selection\n");
			break;
	}
}
void action0(void){
	int a;
	int b;
	fprintf(stdout,"Enter a:");
	fscanf(stdin,"%d",&a);
	fprintf(stdout,"Enter b:");
	fscanf(stdin,"%d",&b);
	fprintf(stdout,"%d+%d=%d\n",a,b,a+b);
}
void action1(void){
	int a;
	int b;
	fprintf(stdout,"Enter a:");
	fscanf(stdin,"%d",&a);
	fprintf(stdout,"Enter b:");
	fscanf(stdin,"%d",&b);
	fprintf(stdout,"%d*%d=%d\n",a,b,a*b);
}
