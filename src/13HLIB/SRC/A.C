#include<13hlib.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#define WIDTH 48
#define HEIGHT 48
Mode13hLib Mode13h;
int main(int argc,char** argv){
	if(Mode13h.DetectVGA()==FAILURE)
		exit(1);
	/*
	Mode13h.SetMode13h();
	if(Mode13h.SetUpPage()==FAILURE)
		exit(1);
	Mode13h.ClearScreen(0);
	Mode13h.ClosePage();
	Mode13h.CloseMode13h();
	*/
	return 0;
}
