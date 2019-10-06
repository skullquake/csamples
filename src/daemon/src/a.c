#include<syslog.h>
#include<stdlib.h>
#include<stdbool.h>
int main(int,char**);
void handler(int);
void process();
int exitNow=0;
int main(int argc,char** argv){
	setlogmask(LOG_UPTO(LOG_NOTICE));
	openlog ("testd",LOG_CONS|LOG_PID|LOG_NDELAY,LOG_LOCAL1);
	syslog(LOG_INFO, "Entering Daemon");
	pid_t pid,sid;
	pid=fork();
	if(pid<0){exit(EXIT_FAILURE);}
	umask(0);
	sid=setsid();
	if(sid<0){exit(EXIT_FAILURE);}
	if((chdir("/"))<0){exit(EXIT_FAILURE);}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	signal(SIGTERM,handler);
	signal(SIGHUP,SIG_IGN);
	while(1){
		process();
		if(exitNow!=0)break;
		sleep(1);
	}
	syslog(LOG_INFO,"Ending Daemon");
	closelog();
	return(EXIT_SUCCESS);
}
void handler(int s){
	syslog(LOG_NOTICE,"Exit signal received!");
	exitNow=1;
}
void process(){
	syslog(LOG_NOTICE,"Writing to my Syslog");
}

