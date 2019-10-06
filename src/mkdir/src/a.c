#include<stdio.h>
#include<sys/stat.h>
int main(int argc,char** argv){
	if(mkdir("asdf",S_IRUSR|S_IWUSR|S_IXUSR)==0){
		printf("Created\n");
	}else{
		printf("Not created\n");
	};
	return 0;
}
