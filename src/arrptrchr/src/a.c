/*
 * array of pointers to char
 */
#include<stdio.h>
void fn000(char**);
void fn001(char**);
int main(int argc,char** argv){
	{
		//decl
		char *a[8];
		//sz
		fprintf(stdout,"%d\n",sizeof(a));
		fprintf(stdout,"%d\n",sizeof(a[0]));
		fprintf(stdout,"%d\n",sizeof(a[0][0]));
		fprintf(stdout,"----------------------------------------\n");
	}
	{
		//init
		char *a[8]={
			"0x00",
			"0x01",
			"0x02",
			"0x03",
			"0x04",
			"0x05",
			"0x06",
			"0x07",
		};
		//sz
		fprintf(stdout,"%d\n",sizeof(a));
		fprintf(stdout,"%d\n",sizeof(a[0]));
		fprintf(stdout,"%d\n",sizeof(a[0][0]));
		//itr
		for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){//using sz
			fprintf(stdout,"%s\n",a[i]);
		}
		fprintf(stdout,"----------------------------------------\n");
	}
	{
		//decl
		char *a[8];
		//pass to fn
		fn000(a);
		fprintf(stdout,"----------------------------------------\n");
	}
	{
		//init
		char *a[8]={
			"0x00",
			"0x01",
			"0x02",
			"0x03",
			"0x04",
			"0x05",
			"0x06",
			"0x07",
		};
		//pass to fn
		fn000(a);
		fprintf(stdout,"----------------------------------------\n");
	}
	/* danger:uninitialized */
	/*
	{
		//decl
		char *a[8];
		//pass to fn
		fn001(a);
		fprintf(stdout,"----------------------------------------\n");
	}
	*/
	{
		//init
		char *a[8]={
			"0x00",
			"0x01",
			"0x02",
			"0x03",
			"0x04",
			"0x05",
			"0x06",
			"0x07",
		};
		//pass to fn
		fn001(a);
		fprintf(stdout,"----------------------------------------\n");
	}
	return 0;
}
void fn000(char** a){
	fprintf(stdout,"%d\n",sizeof(a));
	fprintf(stdout,"%d\n",sizeof(a[0]));
	fprintf(stdout,"%d\n",sizeof(a[0][0]));
}
void fn001(char** a){
	for(int i=0;i<sizeof(a);i++){
		fprintf(stdout,"%s\n",a[i]);
	}
}
