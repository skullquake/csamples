#include<stdio.h>
#define MAX_GRADE 100
#define STUDENTS 10
int grades[STUDENTS];
int idx;
float total=0;
main(int argc,char **argv){
	for(idx=0;idx<STUDENTS;idx++){
		printf("Enter Person %d's grade: ",idx+1);
		scanf("%d",&grades[idx]);
		while(grades[idx]>MAX_GRADE){
			printf("\nThe highest grade possible is %d",MAX_GRADE);
			printf("\nEnter correct grade: ");
			scanf("%d",&grades[idx]);
		}
		total+=grades[idx];
	}
	printf("\n\nThe average score is %f\n",(total/STUDENTS));
	return 0;
}
