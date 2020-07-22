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
extern void deleteList(LinkedList*);
extern void deleteNode(LinkedList*,int(*)(void*,void*),void*);
extern Node*getNode(LinkedList*,int(*)(void*,void*),void*);
extern void printLinkedList(LinkedList*,void(*)(void*));
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
	printLinkedList(&l,printData);
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
			printf("info:main:not found ");
			printData(&ndl);
		}
	}
	for(int i=8;i<10;++i){
		Data ndl=(Data){i,0,0,0};
		Node*res=NULL;
		res=getNode(&l,compareData,&ndl);
		if(res!=NULL){
			deleteNode(&l,compareData,res->data);
		}else{
		}
	}
	printLinkedList(&l,printData);
	deleteList(&l);
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
	printf("D[id,x,y,z,addr]: %4zu%4d%4d%4d%16p\n",s->id,s->x,s->y,s->z,s);
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
void deleteList(LinkedList*l){
#ifndef NDEBUG
	fprintf(stderr,"info:deleteList:start\n");
#endif
	if(l!=NULL){
		Node*cur=l->head;
		while(cur!=NULL){
			Node*next=cur->next;
			if(cur->data!=NULL){
#ifndef NDEBUG
				fprintf(stderr,"info:deleteList:deallocating data [%p]\n",cur->data);
#endif
				free(cur->data);
			}
#ifndef NDEBUG
			fprintf(stderr,"info:deleteList:deallocating node [%p]\n",cur);
#endif
			free(cur);
			cur=next;
		}
	}
#ifndef NDEBUG
	fprintf(stderr,"info:deleteList:end\n");
#endif
}
extern void deleteNode(LinkedList*l,int(*fptr)(void*,void*),void*d){
#ifndef NDEBUG
	fprintf(stderr,"info:deleteNode:start\n");
#endif
	if(l!=NULL&&fptr!=NULL&&d!=NULL){
		Node*cur=l->head;
		Node*prv=NULL;
		while(cur!=NULL){
			if(fptr(cur->data,d)){
				if(prv!=NULL){
					prv->next=cur->next;
				}
				break;
			}
			prv=cur;
			cur=cur->next;
		}
		if(cur!=NULL){
			if(cur==l->head){
				l->head=cur->next;
			}else if(cur==l->tail){
				l->tail=prv;
			}
			free(cur);
			if(prv!=NULL){
#ifndef NDEBUG
				fprintf(stderr,"info:deleteNode:reattaching %p > %p\n",cur,cur->next);
#endif
				prv->next=cur->next;
			}
#ifndef NDEBUG
			else{
				fprintf(stderr,"info:deleteNode:deleting\n");
			}
#endif
			free(d);
		}
	}else{
		fprintf(stderr,"error:deleteNode:invalid arguments\n");
	}
#ifndef NDEBUG
	fprintf(stderr,"info:deleteNode:end\n");
#endif
}
Node*getNode(LinkedList*l,int(*fptr)(void*,void*),void*d){
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
void printLinkedList(LinkedList*l,void(*fptr)(void*)){
#ifndef NDEBUG
	fprintf(stderr,"info:printLinkedList:start\n");
#endif
	if(l!=NULL){
		l->cur=l->head;
		while(l->cur!=NULL){
			if(l->cur->data!=NULL){
				fptr((void*)(l->cur->data));
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
