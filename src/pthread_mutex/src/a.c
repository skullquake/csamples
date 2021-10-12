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
	int*ret=(int*)malloc(sizeof(int));
	*ret=42;
	pthread_exit((void*)ret);
}
void*tf1(void*data){
	printf("thread:%lx:beg\n",pthread_self());
	usleep(2000000);
	pthread_mutex_lock(&lock);
	running=0;
	pthread_mutex_unlock(&lock);
	printf("thread:%lx:end\n",pthread_self());
	pthread_exit(NULL);
}

int main(){
	printf("thread:%lx:beg\n",pthread_self());
	int*arg=(int*)malloc(sizeof(int));
	int*ret=NULL;
	if(!arg)exit(1);
	pthread_t t1;
	pthread_t t2;
	running=1;
	pthread_mutex_init(&lock,NULL);//!=0 check
	pthread_create(&t1,NULL,tf0,arg);
	pthread_create(&t2,NULL,tf1,NULL);
	pthread_detach(t2);
	pthread_join(t1,(void**)&ret);
	printf("thread:%lx:t1:ret:%d\n",pthread_self(),*ret);
	free(ret);
	printf("thread:%lx:end\n",pthread_self());
	pthread_mutex_destroy(&lock);
	exit(0);
}
