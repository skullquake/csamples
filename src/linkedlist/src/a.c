#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
typedef struct Data{
	size_t id;
	int x;
	int y;
	int z;
}Data;
extern int compareData(Data*,Data*);
extern void printData(Data*);
typedef struct Node{
	void*data;
	struct Node*next;
}Node;
typedef struct LinkedList{
	Node*head;
	Node*tail;
	Node*cur;
}LinkedList;
extern void initializeList(LinkedList*);
extern void addHead(LinkedList*,void*);
extern void addTail(LinkedList*,void*);
extern void delete(LinkedList*);
extern Node*getNode(LinkedList*,int(*)(Data*,Data*),void*);
extern void printLinkedList(LinkedList*);
int main(void){
#ifndef NDEBUG
	fprintf(stderr,"info:main:start\n");
#endif
	LinkedList l;
	initializeList(&l);
	for(size_t i=0;i<8;++i){
		Data*n=(Data*)malloc(sizeof(Data));
		n=memcpy(n,&(Data){i,0,0,0},sizeof(Data));
		addHead(&l,n);
	}
	for(size_t i=9;i<16;++i){
		Data*n=(Data*)malloc(sizeof(Data));
		n=memcpy(n,&(Data){i,0,0,0},sizeof(Data));
		addTail(&l,n);
	}
	printLinkedList(&l);
	for(int i=-4;i<4;++i){
		Data ndl=(Data){i,0,0,0};
		Node*res=NULL;
		res=getNode(&l,compareData,&ndl);
		if(res!=NULL){
			printf("info:main:found:    ");
			printData(res->data);
		}else{
			printf("info:main:not found\n");
		}
	}
	for(int i=14;i<20;++i){
		Data ndl=(Data){i,0,0,0};
		Node*res=NULL;
		res=getNode(&l,compareData,&ndl);
		if(res!=NULL){
			printf("info:main:found:    ");
			printData(res->data);
		}else{
			printf("info:main:not found\n");
		}
	}
	delete(&l);
#ifndef NDEBUG
	fprintf(stderr,"info:main:end\n");
#endif
	return EXIT_SUCCESS;
}
int compareData(Data*s0,Data*s1){
#ifndef NDEBUG
	fprintf(stderr,"info:compareData:start\n");
#endif
	int ret=s0->id==s1->id;
#ifndef NDEBUG
	fprintf(stderr,"info:compareData:end\n");
#endif
	return ret;
}
void printData(Data*s){
#ifndef NDEBUG
	fprintf(stderr,"info:printData:start\n");
#endif
	printf("D[addr,id,x,y,z]: %16p%4zu%4d%4d%4d\n",s,s->id,s->x,s->y,s->z);
#ifndef NDEBUG
	fprintf(stderr,"info:printData:end\n");
#endif
}
void initializeList(LinkedList*l){
#ifndef NDEBUG
	fprintf(stderr,"info:initializeList:start\n");
#endif
	if(l!=NULL){
		l->head=NULL;
		l->tail=NULL;
		l->cur=NULL;
	}
#ifndef NDEBUG
	fprintf(stderr,"info:initializeList:end\n");
#endif
}
void addHead(LinkedList*l,void*d){
#ifndef NDEBUG
	fprintf(stderr,"info:addHead:start\n");
#endif
	if(l!=NULL&&d!=NULL){
		Node*n=(Node*)malloc(sizeof(Node));
		if(n!=NULL){
#ifndef NDEBUG
			fprintf(stderr,"info:addHead:node allocated\n");
#endif
			n->data=d;
			if(l->head!=NULL){
#ifndef NDEBUG
				fprintf(stderr,"info:addHead:head adjusted\n");
#endif
				n->next=l->head;
			}
#ifndef NDEBUG
			else{
				fprintf(stderr,"info:addHead:new head added\n");
			}
#endif
			l->head=n;
			if(l->tail==NULL){
#ifndef NDEBUG
				fprintf(stderr,"info:addHead:tail adjusted\n");
#endif
				l->tail=n;
			}
#ifndef NDEBUG
			else{
				fprintf(stderr,"info:addHead:new tail added\n");
			}
#endif

		}else{
			fprintf(stderr,"error:addHead:failed to allocate node\n");
		}
	}else{
		fprintf(stderr,"error:addHead:invalid arguments\n");
	}
#ifndef NDEBUG
	fprintf(stderr,"info:addHead:end\n");
#endif
}
void addTail(LinkedList*l,void*d){
#ifndef NDEBUG
	fprintf(stderr,"info:addTail:start\n");
#endif
	if(l!=NULL&&d!=NULL){
		Node*n=(Node*)malloc(sizeof(Node));
		if(n!=NULL){
#ifndef NDEBUG
			fprintf(stderr,"info:addTail:node allocated\n");
#endif
			n->data=d;
			n->next=NULL;
			if(l->tail!=NULL){
#ifndef NDEBUG
				fprintf(stderr,"info:addTail:tail adjusted\n");
#endif
				l->tail->next=n;
			}
#ifndef NDEBUG
			else{
				fprintf(stderr,"info:addTail:new tail added\n");
			}
#endif
			l->tail=n;
			if(l->head==NULL){
#ifndef NDEBUG
				fprintf(stderr,"info:addTail:head adjusted\n");
#endif
				l->head=n;
			}
#ifndef NDEBUG
			else{
				fprintf(stderr,"info:addTail:new head added\n");
			}
#endif

		}else{
			fprintf(stderr,"error:addTail:failed to allocate node\n");
		}
	}
#ifndef NDEBUG
	fprintf(stderr,"info:addTail:end\n");
#endif
}
void delete(LinkedList*l){
#ifndef NDEBUG
	fprintf(stderr,"info:delete:start\n");
#endif
	if(l!=NULL){
		Node*cur=l->head;
		while(cur!=NULL){
			Node*next=cur->next;
			if(cur->data!=NULL){
#ifndef NDEBUG
				fprintf(stderr,"info:deleteLinkedList:deallocating data [%p]\n",cur->data);
#endif
				free(cur->data);
			}
#ifndef NDEBUG
			fprintf(stderr,"info:deleteLinkedList:deallocating node [%p]\n",cur);
#endif
			free(cur);
			cur=next;
		}
	}
#ifndef NDEBUG
	fprintf(stderr,"info:delete:end\n");
#endif
}
Node*getNode(LinkedList*l,int(*fptr)(Data*,Data*),void*d){
#ifndef NDEBUG
	fprintf(stderr,"info:getNode:start\n");
#endif
	Node*ret=NULL;
	if(l!=NULL&&fptr!=NULL&&d!=NULL){
		Node*cur=l->head;
		while(cur!=NULL){
			if(fptr(cur->data,d)){
				ret=cur;
				break;
			}
			cur=cur->next;
		}
	}
#ifndef NDEBUG
	if(ret!=NULL){
		fprintf(stderr,"info:getNode:node found [%p]\n",ret);
	}else{
		fprintf(stderr,"info:getNode:node not found \n");
	}
#endif
#ifndef NDEBUG
	fprintf(stderr,"info:getNode:end\n");
#endif
	return ret;
}
void printLinkedList(LinkedList*l){
#ifndef NDEBUG
	fprintf(stderr,"info:printLinkedList:start\n");
#endif
	if(l!=NULL){
		l->cur=l->head;
		while(l->cur!=NULL){
			if(l->cur->data!=NULL){
				printData(l->cur->data);
			}
			l->cur=l->cur->next;
		}
	}else{
		fprintf(stderr,"error:printLinkedList:LinkedList NULL\n");
	}
#ifndef NDEBUG
	fprintf(stderr,"info:printLinkedList:end\n");
#endif
}
