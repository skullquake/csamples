#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<pthread.h>
#include<time.h>
static const int e0=0;
static const int e1=1;
static const int e2=2;
static const int e3=3;
static const int e4=4;
void*f(void*);
int main(void){
	srand(time(0));
	pthread_attr_t a;
	pthread_mutex_t m;
	pthread_attr_init(&a);
	pthread_attr_setdetachstate(&a,PTHREAD_CREATE_JOINABLE);
	pthread_mutex_init(&m,NULL);
	pthread_t t;
	int d=42;
	pthread_create(&t,&a,f,(void*)&d);
	pthread_attr_destroy(&a);
	void*r=NULL;
	pthread_join(t,&r);
	if(r!=NULL){
		fprintf(stderr,"info:main:r:%d\n",*((int*)r));
	}
	pthread_mutex_destroy(&m);
	return EXIT_SUCCESS;
}
void*f(void*data){
	switch(rand()%4){
		case 0:
			pthread_exit((void*)&e0);
			break;
		case 1:
			pthread_exit((void*)&e1);
			break;
		case 2:
			pthread_exit((void*)&e2);
			break;
		case 3:
			pthread_exit((void*)&e3);
			break;
		default:
			pthread_exit((void*)&e4);
			break;
	}
	return (void*)0;
}
