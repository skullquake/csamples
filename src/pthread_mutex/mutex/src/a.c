#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
static int running=0;
static pthread_mutex_t lock;
static useconds_t period=1000000;
void*tf0(void*data){
	printf("thread:%p:beg\n",pthread_self());
	int acc=0;
	while(running){
		pthread_mutex_lock(&lock);
		printf("thread:%p:%d\n",pthread_self(),acc);
		acc++;
		pthread_mutex_unlock(&lock);
		usleep(period);
	}
	free(data);
	printf("thread:%p:end\n",pthread_self());
	int*ret=(int*)malloc(sizeof(int));
	*ret=42;
	pthread_exit((void*)ret);
	/*
	*/
}
int main(int argc,char** argv){
	int*arg=(int*)malloc(sizeof(int));
	int*ret=NULL;
	if(!arg)exit(1);
	pthread_t t;
	running=1;
	pthread_mutex_init(&lock,NULL);//!=0 check
	pthread_create(&t,NULL,tf0,arg);
	pthread_join(t,(void**)&ret);
	free(ret);
	exit(0);
}
