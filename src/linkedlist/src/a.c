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
/* list */
extern void initializeList(LinkedList*);
extern void addHead(LinkedList*,void*);
extern void addTail(LinkedList*,void*);
extern void deleteList(LinkedList*);
extern void deleteNode(LinkedList*,int(*)(void*,void*),void*);
extern Node*getNode(LinkedList*,int(*)(void*,void*),void*);
extern void printLinkedList(LinkedList*,void(*)(void*));
void testLinkedList(void);
/* queue */
typedef LinkedList Queue;
extern void initializeQueue(Queue*);
extern void enqueue(Queue*,void*);
extern void*dequeue(Queue*);
extern void deleteQueue(Queue*);
extern void printQueue(Queue*,void(*)(void*));
void testQueue(void);
/* stack */
typedef LinkedList Stack;
extern void initializeStack(Stack*);
extern void deleteStack(Stack*);
extern void printStack(Stack*,void(*)(void*));
void testStack(void);
int main(void){
#ifndef NDEBUG
	fprintf(stderr,"info:main:start\n");
#endif
	testLinkedList();
	testQueue();
	testStack();
#ifndef NDEBUG
	fprintf(stderr,"info:main:end\n");
#endif
	return EXIT_SUCCESS;
}
/* data */
int compareData(Data*s0,Data*s1){
	int ret=s0->id==s1->id;
	return ret;
}
void printData(Data*s){
	printf("D%16p: %4zu%4d%4d%4d\n",s,s->id,s->x,s->y,s->z);
}
/* list */
void initializeList(LinkedList*l){
	if(l!=NULL){
		l->head=NULL;
		l->tail=NULL;
		l->cur=NULL;
	}
}
void addHead(LinkedList*l,void*d){
	if(l!=NULL&&d!=NULL){
		Node*n=(Node*)malloc(sizeof(Node));
		if(n!=NULL){
			n->data=d;
			if(l->head!=NULL){
#ifndef NDEBUG
				fprintf(stderr,"info:addHead:adjusting head %16p > %16p\n",l->head,n);
#endif
				n->next=l->head;
			}
			else{
				n->next=NULL;
#ifndef NDEBUG
				fprintf(stderr,"info:addHead:adding head     %16p\n",n);
#endif
			}
			l->head=n;
			if(l->tail==NULL){
#ifndef NDEBUG
				fprintf(stderr,"info:addHead:adjusting tail %16p > %16p\n",l->tail,n);
#endif
				l->tail=n;
			}
		}else{
			fprintf(stderr,"error:addHead:failed to allocate node\n");
		}
	}else{
		fprintf(stderr,"error:addHead:invalid arguments\n");
	}
}
void addTail(LinkedList*l,void*d){
	if(l!=NULL&&d!=NULL){
		Node*n=(Node*)malloc(sizeof(Node));
		if(n!=NULL){
			n->data=d;
			n->next=NULL;
			if(l->tail!=NULL){
#ifndef NDEBUG
				fprintf(stderr,"info:addTail:adjusting tail %16p > %16p\n",l->tail,n);
#endif
				l->tail->next=n;
			}
			l->tail=n;
			if(l->head==NULL){
#ifndef NDEBUG
				fprintf(stderr,"info:addTail:adjusting head %16p > %16p\n",l->head,n);
#endif
				l->head=n;
			}
		}else{
			fprintf(stderr,"error:addTail:failed to allocate node\n");
		}
	}
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
#ifndef NDEBUG
				fprintf(stderr,"info:deleteNode:adjusting head        %p > %p\n",l->head,cur->next);
#endif
				l->head=cur->next;
			}else if(cur==l->tail){
#ifndef NDEBUG
				fprintf(stderr,"info:deleteNode:adjusting tail        %p > %p\n",l->head,cur->next);
#endif
				l->tail=prv;
			}
			free(cur);
			if(prv!=NULL){
#ifndef NDEBUG
				fprintf(stderr,"info:deleteNode:adjusting previous node %p > %p\n",cur,cur->next);
#endif
				prv->next=cur->next;
			}
			free(d);
		}
	}else{
		fprintf(stderr,"error:deleteNode:invalid arguments\n");
	}
}
Node*getNode(LinkedList*l,int(*fptr)(void*,void*),void*d){
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
void testLinkedList(void){
#ifndef NDEBUG
	fprintf(stderr,"info:testLinkedList:start\n");
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
	fprintf(stderr,"info:testLinkedList:end\n");
#endif
}
/* queue */
void initializeQueue(Queue*q){
	initializeList(q);
}
void enqueue(Queue*q,void*d){
	addHead(q,d);
}
void*dequeue(Queue*q){
	void*d=NULL;
	if(q!=NULL){
		if(q->head==NULL){
			d=NULL;
		}else if(q->head==q->tail){
			d=q->head->data;
			free(q->head);
			q->head=NULL;
			q->tail=NULL;
		}else{
			d=q->head->data;
			Node*n=q->head->next;;
			free(q->head);
			q->head=n;
		}
	}
}
void deleteQueue(Queue*q){
	deleteList(q);
}
void printQueue(Queue*q,void(*fptr)(void*)){
#ifndef NDEBUG
	fprintf(stderr,"info:printQueue:start\n");
#endif
	printLinkedList(q,fptr);
#ifndef NDEBUG
	fprintf(stderr,"info:printQueue:end\n");
#endif
}
void testQueue(void){
#ifndef NDEBUG
	fprintf(stderr,"info:testQueue:end\n");
#endif
	Queue q;
	initializeQueue(&q);
	for(size_t i=0;i<8;++i){
		Data*d=(Data*)malloc(sizeof(Data));
		memcpy(d,&(Data){i,0,0,0},sizeof(Data));
		enqueue(&q,d);
	}
	Data*d=NULL;
	while((d=dequeue(&q))!=NULL){
		printQueue(&q,printData);
		printf("--------------------------------------------------------------------------------\n");
	}
	deleteQueue(&q);
#ifndef NDEBUG
	fprintf(stderr,"info:testQueue:end\n");
#endif
}
/* stack */
void initializeStack(Stack*s){
}
void deleteStack(Stack*s){
}
void printStack(Stack*s,void(*fptr)(void*)){
}
void testStack(void){
#ifndef NDEBUG
	fprintf(stderr,"info:testStack:end\n");
#endif
#ifndef NDEBUG
	fprintf(stderr,"info:testStacked:end\n");
#endif
}
