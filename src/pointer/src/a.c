#include<stdio.h>
int main(int argc,char** argv){
	{
		int a=0;
		int* aP=&a;
		fprintf(stdout,"%d\n",a);
		a++;
		fprintf(stdout,"%d\n",a);
		(*aP)++;
		fprintf(stdout,"%d\n",a);
		fprintf(stdout,"%d\n",*aP);
		a++;
		fprintf(stdout,"%d\n",*aP);
		(*aP)++;
		fprintf(stdout,"%d\n",*aP);
		aP=(int*)malloc(sizeof(int));
		if(aP!=NULL){
			*aP=0;
			fprintf(stdout,"%d\n",*aP);
			(*aP)++;
			fprintf(stdout,"%d\n",*aP);
			free(aP);
		}else{
			fprintf(stderr,"Failed to allocate memory\n");
			exit(1);
		}
		int na=8;
		aP=(int*)malloc(na*sizeof(int));
		if(aP!=NULL){
			/* indexing */
			for(int i=0;i<na;i++){
				aP[i]=i;
			}
			for(int i=0;i<na;i++){
				fprintf(stdout,"%d",aP[i]);
				if(i!=na-1)fprintf(stdout,",");
			}
			fprintf(stdout,"\n");
			int* bP;
			int idx=0;
			bP=aP;
			/* ptr arith */
			while(bP<&aP[na]){
				*bP=na-idx-1;
				bP++;
				idx++;
			}
			bP=aP;
			while(bP<&aP[na]){
				fprintf(stdout,"%d",*bP);
				if(bP!=&aP[na-1])fprintf(stdout,",");
				bP++;
			}
			fprintf(stdout,"\n");
			free(aP);
		}else{
			fprintf(stderr,"Failed to allocate memory\n");
			exit(1);
		}
	}	
	{
		int a[4][4];
		int *b=a;/*!*/
		for(int i=0;i<4*4;i++){
			b[i]=i;
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				fprintf(stdout,"%d",a[i][j]);
				if(j<4-1)fprintf(stdout,",");
			}
			fprintf(stdout,"\n");
		}

	}
	return 0;
}
