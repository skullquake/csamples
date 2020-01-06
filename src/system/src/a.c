#include<stdio.h>
int main(int argc,char** argv){
	char cmd[][8]={
		"pwd",
		"ls",
		"date"
	};
	for(int i=0;i<3;i++){
		system(cmd[i]);
	}
	return 0;
}
