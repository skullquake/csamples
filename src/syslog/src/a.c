#include<stdio.h>
#include <syslog.h>


int main(int argc,char** argv){
	printf("main()\n");
	setlogmask (LOG_UPTO (LOG_NOTICE));
	openlog ("exampleprog", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
	for(int i=0;i<1024;i++){
		syslog (LOG_NOTICE, "Program started by User %d", getuid ());
		syslog (LOG_INFO, "A tree falls in a forest");
	}
	closelog ();
	return 0;
}
