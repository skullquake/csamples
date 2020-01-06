#include<stdio.h>
int main(int argc,char** argv){
	{
		int a[8];
		for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
			a[i]=i;
		}
		for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
			printf("%d\n",a[i]);
		}
	}
	{
		int a[]={0,1,2,3,4,5,6,7,8};
		for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
			printf("%d\n",a[i]);
		}
	}
	{
		/*note use of sizeof operator in multidimensional array loops*/
		int a[][2]={{0,1},{2,3},{4,5},{6,7}};
		for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
			for(int j=0;j<sizeof(a[0])/sizeof(a[0][0]);j++){
				fprintf(stdout,"%d",a[i][j]);
				if(j<(sizeof(a[0])/sizeof(a[0][0])-1))fprintf(stdout,",");
			}
			fprintf(stdout,"\n");
		}
		fprintf(stdout,"%d\n",sizeof(a));
		fprintf(stdout,"%d\n",sizeof(a[0]));
		fprintf(stdout,"%d\n",sizeof(a[0][0]));
	}
	return 0;
}
