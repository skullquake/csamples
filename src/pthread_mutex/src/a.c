#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<pthread.h>
#include<time.h>
#include<unistd.h>
#include<stdio.h>
typedef struct VectorInfo{
	double*a;
	double*b;
	size_t vsz;
	int len;
	double sum;
}VectorInfo;
typedef struct Product{
	VectorInfo*vi;
	int bidx;
	int tidx;
}Product;
pthread_mutex_t mSum;
void*dotProduct(void*);
void printVectorInfo(VectorInfo*);
void printProduct(Product*);
int main(void){
#ifndef NDEBUG
	fprintf(stderr,"info:main:start\n");
#endif
	srand(time(0));
	size_t vsz=1024;
	size_t ntr=4;
	assert(vsz>0);
	assert(ntr>0);
	double*v0=(double*)malloc(vsz*sizeof(double));
	if(v0==NULL){
		fprintf(stderr,"error:main:failed to allocate v0\n");
		return EXIT_FAILURE;
	}
	double*v1=(double*)malloc(vsz*sizeof(double));
	if(v1==NULL){
		fprintf(stderr,"error:main:failed to allocate v0\n");
		free(v0);
		return EXIT_FAILURE;
	}
	for(size_t i=0;i<vsz;++i){
		v0[i]=i;
		v1[i]=i+vsz;
	}
	VectorInfo vi={v0,v1,vsz,vsz/ntr,0};
	Product*p=(Product*)malloc(ntr*sizeof(Product));
	if(p==NULL){
		fprintf(stderr,"error:main:failed to allocate p\n");
		free(v0);
		free(v1);
		return EXIT_FAILURE;
	}
	for(size_t i=0;i<ntr;++i){
		p[i].vi=&vi;
		p[i].bidx=i*vi.len;
		p[i].tidx=(int)i;
	}
	printVectorInfo(&vi);
	for(size_t i=0;i<ntr;++i){
		printProduct(&p[i]);
	}
	pthread_t*t=(pthread_t*)malloc(ntr*sizeof(pthread_t));
	if(t==NULL){
		fprintf(stderr,"error:main:failed to allocate t\n");
		free(v0);
		free(v1);
		free(t);
		return EXIT_FAILURE;
	}
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	pthread_mutex_init(&mSum,NULL);
	bool terr=false;
	size_t tidx=-1;
	for(size_t i=0;i<ntr;++i){
#ifndef NDEBUG
		fprintf(stderr,"info:main:creating thread %zu\n",i);
#endif
		if(pthread_create(&t[i],&attr,dotProduct,(void*)&p[i])){
			fprintf(stderr,"error:main:failed to create thread %zu\n",i);
			terr=true;
			break;
		}
		tidx=i;
	}
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&mSum);
	for(size_t i=0;i<tidx+1;++i){
#ifndef NDEBUG
		fprintf(stderr,"info:main:joining thread %zu\n",i);
#endif
		pthread_join(t[i],NULL);
	}
	if(!terr){
		printVectorInfo(&vi);
		for(size_t i=0;i<ntr;++i){
			printProduct(&p[i]);
		}
	}
	free(t);
	free(p);
	free(v1);
	free(v0);
#ifndef NDEBUG
	fprintf(stderr,"info:main:end\n");
#endif
	return EXIT_SUCCESS;
}
void*dotProduct(void*data){
#ifndef NDEBUG
	fprintf(stderr,"info:dotProduct:start\n");
#endif
	if(data==NULL){
		fprintf(stderr,"error:dotProduct:product null\n");
		pthread_exit((void*)0);
	}
	Product*p=(Product*)data;
	if(p->vi==NULL){
		fprintf(stderr,"error:dotProduct:vectorinfo null\n");
		pthread_exit((void*)0);
	}
	VectorInfo*vi=p->vi;
	int bidx=p->bidx;
	int eidx=bidx+vi->len;
#ifndef NDEBUG
		fprintf(stderr,"info:dotProduct:tidx[%d]:bidx:%d\n",p->tidx,bidx);
		fprintf(stderr,"info:dotProduct:tidx[%d]:bidx:%d\n",p->tidx,eidx);
#endif
	double tot=0;
	for(int i=bidx;i<eidx;++i){
		usleep((rand()%500)*1000);
		tot+=vi->a[i]+vi->b[i];
#ifndef NDEBUG
		fprintf(stderr,"info:dotProduct:tidx[%d]:bidx[%4d]:a[%4d]:%lf\n",p->tidx,bidx,i,vi->a[i]);
		fprintf(stderr,"info:dotProduct:tidx[%d]:bidx[%4d]:b[%4d]:%lf\n",p->tidx,bidx,i,vi->b[i]);
		fprintf(stderr,"info:dotProduct:tidx[%d]:bidx[%4d]:tot:    %lf\n",p->tidx,bidx,tot);
#endif
	}
	pthread_mutex_lock(&mSum);
#ifndef NDEBUG
		fprintf(stderr,"info:dotProduct:tidx[%d]:bidx[%4d]:  locking\n",p->tidx,bidx);
#endif
	vi->sum+=tot;
#ifndef NDEBUG
		fprintf(stderr,"info:dotProduct:tidx[%d]:bidx[%4d]:unlocking\n",p->tidx,bidx);
#endif
	pthread_mutex_unlock(&mSum);
#ifndef NDEBUG
	fprintf(stderr,"info:dotProduct:tidx[%d]:end\n",p->tidx);
#endif
	pthread_exit((void*)0);
}
void printVectorInfo(VectorInfo*vi){
	if(vi!=NULL){
		printf("info:printVectorInfo:vi:[%p,[",vi);
		for(size_t i=0;i<vi->vsz;++i){
			printf("%f",vi->a[i]);
			if(i!=vi->vsz-1)printf(",");
		}printf("],[");
		for(size_t i=0;i<vi->vsz;++i){
			printf("%f",vi->b[i]);
			if(i!=vi->vsz-1)printf(",");
		}printf("],%d,%lf]\n",vi->len,vi->sum);
	}else{
		printf("info:printVectorInfo:NULL\n");
	}
}
void printProduct(Product*p){
	if(p!=NULL){
		printf("info:printProduct:[%p,%p,%d]\n",p,p->vi,p->bidx);
	}else{
		printf("info:printProduct:NULL\n");
	}
}
