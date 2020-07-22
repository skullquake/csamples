#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<time.h>
typedef struct S{
	int x;
	int y;
	int z;
	char buf0[4096];
	char buf1[4096];
	char buf2[4096];
	char buf3[4096];
}S;
int bufsz;
S**gs=NULL;
S*getS(void);
void putS(S*);
void printS(S*);
void cleanup(void);
int main(int argc,char**argv){
	int ret=EXIT_SUCCESS;
	if(argc!=4){
		fprintf(stderr,"error:main:invalid arguments\n");
		ret=EXIT_FAILURE;
	}else{
		bufsz=atoi(argv[1]);
		size_t wbufsz=atoi(argv[2]);
		size_t nitr=atol(argv[3]);
		gs=(S**)malloc(sizeof(S*)*bufsz);
		if(gs!=NULL){
#ifndef NDEBUG
			fprintf(stderr,"info:main:start\n");
#endif
			atexit(cleanup);
			S**buf=(S**)malloc(sizeof(S*)*wbufsz);
			if(buf!=NULL){
				S**beg=buf;
				S**end=buf+wbufsz;
				clock_t tic=clock();//time in clock
				for(size_t i=0;i<nitr;++i){
					{
						int idx=0;
						for(S**pos=beg;pos!=end;++pos){
#ifndef NDEBUG
							printf("----get:%4d----\n",idx);
#endif
							S*s=NULL;
							s=getS();
							s->x=idx;
							s->y=idx*2;
							s->z=idx*3;
#ifndef NDEBUG
							printS(s);
#endif
							*pos=s;
							*pos=s;
							++idx;
						}
					}
					{
						int idx=0;
						for(S**pos=beg;pos!=end;++pos){
#ifndef NDEBUG
							printf("----put:%4d----\n",idx);
#endif
							putS(*pos);
							++idx;
						}
					}
					{
						int idx=0;
						for(S**pos=beg;pos!=end;++pos){
#ifndef NDEBUG
							printf("----get:%4d----\n",idx);
#endif
							S*s=NULL;
							s=getS();
							s->x=idx;
							s->y=idx*2;
							s->z=idx*3;
#ifndef NDEBUG
							printS(s);
#endif
							*pos=s;
							*pos=s;
							++idx;
						}
					}
					{
						int idx=0;
						for(S**pos=beg;pos!=end;++pos){
#ifndef NDEBUG
							printf("----put:%4d----\n",idx);
#endif
							putS(*pos);
							++idx;
						}
					}
				}
				clock_t toc=clock();//time out clock
				double dur=(double)(toc-tic)/CLOCKS_PER_SEC;
				fprintf(stderr,"info:main:dur:%lf\n",dur);
				free(buf);
			}else{
				fprintf(stderr,"error:main:failed to allocate working buffer\n");
				ret=EXIT_FAILURE;
			}
			free(gs);
		}else{
			fprintf(stderr,"error:main:failed to allocate pool buffer\n");
			ret=EXIT_FAILURE;
		}
#ifndef NDEBUG
		fprintf(stderr,"info:main:end\n");
#endif
	}
	return ret;
}
S*getS(void){
#ifndef NDEBUG
	fprintf(stderr,"info:getS:begin\n");
#endif
	S**beg=gs;
	S**end=beg+bufsz;
#ifndef NDEBUG
	fprintf(stderr,"info:getS:buffer status:\n");
	for(S**pos=beg;pos!=end;++pos){
		fprintf(stderr,"[%s]",*pos==NULL?"N":"F");
	}
	fprintf(stderr,"\n");
#endif
	for(S**pos=beg;pos!=end;++pos){
		if(*pos!=NULL){
#ifndef NDEBUG
	fprintf(stderr," ^\n");
#endif
#ifndef NDEBUG
	fprintf(stderr,"info:getS:using pooled %p\n",*pos);
#endif
#ifndef NDEBUG
	fprintf(stderr,"info:getS:end\n");
#endif
			S*s=*pos;
			*pos=NULL;
			return s;
		}
#ifndef NDEBUG
	fprintf(stderr,"   ");
#endif
	}
#ifndef NDEBUG
	fprintf(stderr," x\n");
#endif
	S*s=(S*)malloc(sizeof(S));
#ifndef NDEBUG
	fprintf(stderr,"info:getS:created pooled %p\n",s);
#endif
#ifndef NDEBUG
	fprintf(stderr,"info:getS:end\n");
#endif
	return s;
}
void putS(S*s){
#ifndef NDEBUG
	fprintf(stderr,"info:putS:begin\n");
#endif
	S**beg=gs;
	S**end=beg+bufsz;
#ifndef NDEBUG
	fprintf(stderr,"info:putS:buffer status:\n");
	for(S**pos=beg;pos!=end;++pos){
		fprintf(stderr,"[%s]",*pos==NULL?"N":"F");
	}
	fprintf(stderr,"\n");
#endif
	for(S**pos=beg;pos!=end;++pos){
		if(*pos==NULL){
#ifndef NDEBUG
	fprintf(stderr," ^\n");
#endif
			*pos=s;
#ifndef NDEBUG
	fprintf(stderr,"info:putS:pooling %p\n",s);
#endif
#ifndef NDEBUG
	fprintf(stderr,"info:putS:end\n");
#endif
			return;
		}
#ifndef NDEBUG
	fprintf(stderr,"   ");
#endif
	}
#ifndef NDEBUG
	fprintf(stderr," x\n");
#endif
#ifndef NDEBUG
	fprintf(stderr,"info:putS:not pooling %p\n",s);
#endif
	free(s);
#ifndef NDEBUG
	fprintf(stderr,"info:putS:end\n");
#endif
}
void printS(S*s){
#ifndef NDEBUG
	fprintf(stderr,"info:printS:begin\n");
#endif
	printf("S[x]: %d\n",s->x);
	printf(" [y]: %d\n",s->y);
	printf(" [z]: %d\n",s->z);
#ifndef NDEBUG
	fprintf(stderr,"info:printS:end\n");
#endif
}
void cleanup(void){
#ifndef NDEBUG
	fprintf(stderr,"info:cleanup:begin\n");
#endif
	S**beg=gs;
	S**end=beg+bufsz;
	for(S**pos=beg;pos!=end;++pos){
		if(*pos!=NULL){
#ifndef NDEBUG
	fprintf(stderr,"info:cleanup:freeing %p\n",*pos);
#endif
			free(*pos);
		}
	}
#ifndef NDEBUG
	fprintf(stderr,"info:cleanup:end\n");
#endif
}
