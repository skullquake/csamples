#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<unistd.h>
void*f(void*);
typedef struct ShDat{
	int x;
	int y;
	int z;
}ShDat;
typedef struct TS{
	pthread_t t;
	size_t id;
	int x;
	int y;
	int z;
	ShDat*shd;
}TS;
int main(void){
	srand(time(0));
	ShDat shd={1,2,3};
	TS tbuf[8];
	for(size_t i=0;i<sizeof(tbuf)/sizeof(*tbuf);++i){
		tbuf[i].id=i;
		tbuf[i].x=i*2;
		tbuf[i].y=i*2*2;
		tbuf[i].z=i*2*2*2;
		tbuf[i].shd=&shd;
		pthread_create(&(tbuf[i].t),NULL,f,(void*)&tbuf[i]);
	}
	for(size_t i=0;i<sizeof(tbuf)/sizeof(*tbuf);++i){
		pthread_join(tbuf[i].t,NULL);
	}
	printf("info:main:shd:   [%4d,%4d,%4d]\n",shd.x,shd.y,shd.z);
	return EXIT_SUCCESS;
}
void*f(void*data){
	if(data==NULL){
		fprintf(stderr,"error:f:data null\n");
		return NULL;
	}
	TS*ts=(TS*)data;
	printf("info:f[%4zu]:start\n",ts->id);
	usleep((rand()%500)*1000);
	printf("info:f[%4zu]:dat:[%4d,%4d,%4d]\n",ts->id,ts->x,ts->y,ts->z);
	if(ts->shd==NULL){
		printf("info:f[%4zu]:shd:NULL\n",ts->id);
	}else{
		printf("info:f[%4zu]:shd:[%4d,%4d,%4d]\n",ts->id,ts->shd->x,ts->shd->y,ts->shd->z);
		ts->shd->x+=1;
		ts->shd->y+=1;
		ts->shd->z+=1;
	}
	usleep((rand()%500)*1000);
	printf("info:f[%4zu]:end\n",ts->id);
	return NULL;
}
