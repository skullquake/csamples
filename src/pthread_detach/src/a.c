#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
static int running=0;
static pthread_mutex_t lock;
void*tf0(void*data){
	printf("thread:%lx:beg\n",pthread_self());
	int acc=0;
	while(running){
		pthread_mutex_lock(&lock);
		printf("thread:%lx:%d\n",pthread_self(),acc);
		acc++;
		pthread_mutex_unlock(&lock);
		usleep(100000);
	}
	free(data);
	printf("thread:%lx:end\n",pthread_self());
	pthread_exit(NULL);
}
int main(){
	printf("thread:%lx:beg\n",pthread_self());
	int*arg=(int*)malloc(sizeof(int));
	if(!arg)exit(1);
	pthread_t t;
	running=1;
	pthread_mutex_init(&lock,NULL);//!=0 check
	pthread_create(&t,NULL,tf0,arg);
	pthread_detach(t);
	usleep(1000000);
	printf("thread:%lx:end\n",pthread_self());
	exit(0);
}
