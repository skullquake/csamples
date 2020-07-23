#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#define NITR 32
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
extern void deleteLinkedList(LinkedList*);
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
extern void pushStack(Stack*,void*);
extern void*popStack(Stack*);
extern void printStack(Stack*,void(*)(void*));
extern void testStack(void);
/* tree */
typedef struct TreeNode{
	void*data;
	struct TreeNode*left;
	struct TreeNode*right;
}TreeNode;
extern void initializeTree(TreeNode**,void*);
extern void insertTreeNode(TreeNode**,int(*)(void*,void*),void*);
extern void deleteTreeNode(TreeNode*,TreeNode*);
extern void*findNode(TreeNode*,int(*)(void*,void*),void*);
extern void deleteTree(TreeNode*);
extern void testTree(void);
extern void traverseTreeInOrder(TreeNode*,int(*)(void*,void*),void(*)(void*));
extern void traverseTreePreOrder(TreeNode*,int(*)(void*,void*),void(*)(void*));
extern void traverseTreePostOrder(TreeNode*,int(*)(void*,void*),void(*)(void*));
int main(void){
#ifndef NDEBUG
	fprintf(stderr,"info:main:start\n");
#endif
	srand(time(0));
	testLinkedList();
	testQueue();
	testStack();
	testTree();
#ifndef NDEBUG
	fprintf(stderr,"info:main:end\n");
#endif
	return EXIT_SUCCESS;
}
/* data */
int compareData(Data*s0,Data*s1){
	int ret=-1;
	if(s0!=NULL&&s1!=NULL){
		ret=s0->id==s1->id;
	}else{
		fprintf(stderr,"info:compareData:invalid arguments\n");
	}
	return ret;
}
void printData(Data*s){
	if(s!=NULL){
		printf("D%16p: %4zu%4d%4d%4d\n",s,s->id,s->x,s->y,s->z);
	}else{
		printf("D%16p!\n",s);
	}
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
				fprintf(stderr,"info:addHead:adding head    %16p\n",n);
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
void deleteLinkedList(LinkedList*l){
#ifndef NDEBUG
	fprintf(stderr,"info:deleteLinkedList:start\n");
#endif
	if(l!=NULL){
		Node*cur=l->head;
		while(cur!=NULL){
			Node*next=cur->next;
#ifndef NDEBUG
				fprintf(stderr,"info:deleteLinkedList:deallocating [%p:%p]\n",cur,cur->data);
#endif
			if(cur->data!=NULL)free(cur->data);
			free(cur);
			cur=next;
		}
	}
#ifndef NDEBUG
	fprintf(stderr,"info:deleteLinkedList:end\n");
#endif
}
extern void deleteNode(LinkedList*l,int(*cmp)(void*,void*),void*d){
	if(l!=NULL&&cmp!=NULL&&d!=NULL){
		Node*cur=l->head;
		Node*prv=NULL;
		while(cur!=NULL){
			if(cmp(cur->data,d)){
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
Node*getNode(LinkedList*l,int(*cmp)(void*,void*),void*d){
	Node*ret=NULL;
	if(l!=NULL&&cmp!=NULL&&d!=NULL){
		Node*cur=l->head;
		while(cur!=NULL){
			if(cmp(cur->data,d)){
				ret=cur;
				break;
			}
			cur=cur->next;
		}
	}
	return ret;
}
void printLinkedList(LinkedList*l,void(*cmp)(void*)){
#ifndef NDEBUG
	fprintf(stderr,"info:printLinkedList:start\n");
#endif
	if(l!=NULL){
		l->cur=l->head;
		while(l->cur!=NULL){
			if(l->cur->data!=NULL){
				printf("L %16p > %16p ",l->cur,l->cur->next);
				cmp((void*)(l->cur->data));
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
	const int nitr=NITR;
	LinkedList l;
	initializeList(&l);
	for(size_t i=0;i<nitr;++i){
		Data*d=(Data*)malloc(sizeof(Data));
		memcpy(d,&(Data){i,rand()%100,rand()%100,rand()%100},sizeof(Data));
		addHead(&l,d);
	}
	for(size_t i=nitr+1;i<nitr+nitr;++i){
		Data*d=(Data*)malloc(sizeof(Data));
		memcpy(d,&(Data){i,rand()%100,rand()%100,rand()%100},sizeof(Data));
		addTail(&l,d);
	}
	printLinkedList(&l,(void(*)(void*))printData);
	for(int i=0-nitr-nitr/2;i<nitr/2;++i){
		Data ndl=(Data){i,0,0,0};
		Node*res=NULL;
		res=getNode(&l,(int(*)(void*,void*))compareData,&ndl);
		if(res!=NULL){
			printf("info:main:found:    ");
			printData(res->data);
		}else{
			printf("info:main:not found ");
			printData(&ndl);
		}
	}
	for(int i=nitr/2;i<(nitr+nitr/2);++i){
		Data ndl=(Data){i,0,0,0};
		Node*res=NULL;
		res=getNode(&l,(int(*)(void*,void*))compareData,&ndl);
		if(res!=NULL){
			printf("info:main:found:    ");
			printData(res->data);
		}else{
			printf("info:main:not found ");
			printData(&ndl);
		}
	}
	for(int i=nitr;i<nitr+nitr/2;++i){
		Data ndl=(Data){i,0,0,0};
		Node*res=NULL;
		res=getNode(&l,(int(*)(void*,void*))compareData,&ndl);
		if(res!=NULL){
			deleteNode(&l,(int(*)(void*,void*))compareData,res->data);
		}else{
		}
	}
	printLinkedList(&l,(void(*)(void*))printData);
	deleteLinkedList(&l);
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
	void*ret=NULL;
	if(q!=NULL){
		if(q->tail!=NULL){
			if(q->tail==q->head){
#ifndef NDEBUG
				fprintf(stderr,"info:dequeue:adjusting tail %16p > %16p\n",q->tail,NULL);
#endif
				ret=q->head->data;
				free(q->head);
				q->head=NULL;
				q->tail=NULL;
			}else if(q->tail!=NULL){
				ret=q->tail->data;
				Node*pos=q->head;
				while(pos->next!=q->tail){
					pos=pos->next;
				}
				free(pos->next);
				pos->next=NULL;
#ifndef NDEBUG
				fprintf(stderr,"info:dequeue:adjusting tail %16p > %16p\n",q->tail,pos);
#endif
				q->tail=pos;
			}
		}else{
			ret=NULL;
		}
	}else{
		fprintf(stderr,"error:dequeue:stack NULL\n");
	}
	return ret;
}
void deleteQueue(Queue*q){
#ifndef NDEBUG
	fprintf(stderr,"info:deleteQueue:start\n");
#endif
	deleteLinkedList(q);
#ifndef NDEBUG
	fprintf(stderr,"info:deleteQueue:end\n");
#endif
}
void printQueue(Queue*q,void(*cmp)(void*)){
#ifndef NDEBUG
	fprintf(stderr,"info:printQueue:start\n");
#endif
	printLinkedList(q,cmp);
#ifndef NDEBUG
	fprintf(stderr,"info:printQueue:end\n");
#endif
}
void testQueue(void){
#ifndef NDEBUG
	fprintf(stderr,"info:testQueue:start\n");
#endif
	const int nitr=NITR;
	{
		Queue q;
		initializeQueue(&q);
		for(size_t i=0;i<nitr;++i){
			Data*d=(Data*)malloc(sizeof(Data));
			memcpy(d,&(Data){i,rand()%100,rand()%100,rand()%100},sizeof(Data));
			enqueue(&q,d);
		}
		deleteQueue(&q);
	}
	{
		Queue q;
		initializeQueue(&q);
		for(size_t i=0;i<nitr;++i){
			Data*d=(Data*)malloc(sizeof(Data));
			memcpy(d,&(Data){i,rand()%100,rand()%100,rand()%100},sizeof(Data));
			enqueue(&q,d);
		}
		Data*d=NULL;
		while((d=dequeue(&q))!=NULL){
			printf("info:testQueue:dequeued:              ");
			printData(d);
			printQueue(&q,(void(*)(void*))printData);
			printf("--------------------------------------------------------------------------------\n");
			free(d);
		}
		deleteQueue(&q);
	}
#ifndef NDEBUG
	fprintf(stderr,"info:testQueue:end\n");
#endif
}
/* stack */
void initializeStack(Stack*s){
	initializeList(s);
}
void deleteStack(Stack*s){
#ifndef NDEBUG
	fprintf(stderr,"info:deleteStack:start\n");
#endif
	deleteLinkedList(s);
#ifndef NDEBUG
	fprintf(stderr,"info:deleteStack:end\n");
#endif
}
void pushStack(Stack*s,void*d){
	if(s!=NULL&&d!=NULL){
		addHead(s,d);
	}else{
#ifndef NDEBUG
		fprintf(stderr,"info:pushStack:invalid arguents\n");
#endif
	}
}
void*popStack(Stack*s){
	void*ret=NULL;
	if(s!=NULL){
		if(s->head==NULL){
			ret=NULL;
		}else if(s->head==s->tail){
#ifndef NDEBUG
				fprintf(stderr,"info:popStack:adjusting head %16p > %16p\n",s->head,NULL);
#endif
			ret=s->head->data;
			free(s->head);
			s->head=NULL;
			s->tail=NULL;
		}else{
			ret=s->head->data;
			Node*n=s->head->next;;
			free(s->head);
#ifndef NDEBUG
				fprintf(stderr,"info:popStack:adjusting head %16p > %16p\n",s->head,n);
#endif
			s->head=n;
		}
	}
	return ret;
}
void printStack(Stack*s,void(*cmp)(void*)){
	printLinkedList(s,cmp);
}
void testStack(void){
#ifndef NDEBUG
	fprintf(stderr,"info:testStack:start\n");
#endif
	const int nitr=NITR;
	{
		Stack s;
		initializeStack(&s);
		for(size_t i=0;i<nitr;++i){
			Data*d=(Data*)malloc(sizeof(Data));
			memcpy(d,&(Data){i,rand()%100,rand()%100,rand()%100},sizeof(Data));
			pushStack(&s,d);
		}
		printStack(&s,(void(*)(void*))printData);
		deleteStack(&s);
	}
	{
		Stack s;
		initializeStack(&s);
		for(size_t i=0;i<nitr;++i){
			Data*d=(Data*)malloc(sizeof(Data));
			memcpy(d,&(Data){i,rand()%100,rand()%100,rand()%100},sizeof(Data));
			pushStack(&s,d);
		}
		printStack(&s,(void(*)(void*))printData);
		Data*d=NULL;
		while((d=popStack(&s))!=NULL){
			printf("info:testStack:popped:                ");
			printData(d);
			printStack(&s,(void(*)(void*))printData);
			printf("--------------------------------------------------------------------------------\n");
			free(d);
		}
		deleteStack(&s);
	}
#ifndef NDEBUG
	fprintf(stderr,"info:testStacked:end\n");
#endif
}
/* Tree */
void initializeTree(TreeNode**t,void*d){
	if(t!=NULL){
		if(*t==NULL)*t=(TreeNode*)malloc(sizeof(TreeNode));
		if(*t!=NULL){
			(*t)->data=d;
			(*t)->left=NULL;
			(*t)->right=NULL;
		}
	}
}
void insertTreeNode(TreeNode**root,int(*cmp)(void*,void*),void*d){
	if(root!=NULL&&*root!=NULL&&d!=NULL){
		TreeNode*n=(TreeNode*)malloc(sizeof(TreeNode));
		n->data=d;
		n->left=NULL;
		n->right=NULL;
		if(*root==NULL){
			*root=n;
			return;
		}else{
			while(true){
				if(cmp((*root)->data,d)>0){
					if((*root)->left!=NULL){
						*root=(*root)->left;
					}else{
#ifndef NDEBUG
					fprintf(stderr,"info:insertTreeNode:inserting left  %16p > %16p\n",(*root),n);
#endif
						(*root)->left=n;
						break;
					}
				}else{
					if((*root)->right!=NULL){
						*root=(*root)->right;
					}else{
#ifndef NDEBUG
					fprintf(stderr,"info:insertTreeNode:inserting right %16p > %16p\n",(*root),n);
#endif
						(*root)->right=n;
						break;
					}
				}
			}
		}
	}else{
		fprintf(stderr,"error:insertNode:invalid arguments\n");
	}
}
void deleteTreeNode(TreeNode*t,TreeNode*n){
}
void*findTreeNode(TreeNode*t,int(*cmp)(void*,void*),void*d){
	return NULL;
}
void deleteTree(TreeNode*root){
	if(root!=NULL){
#ifndef NDEBUG
		fprintf(stderr,"info:deleteTree:deallocating [%p:%p]\n",root,root->data);
#endif
		if(root->data!=NULL)free(root->data);
		deleteTree(root->left);
		deleteTree(root->right);
		free(root);
	}
}
void traverseTreeInOrder(TreeNode*root,int(*cmp)(void*,void*),void(*work)(void*)){
	if(root!=NULL&&cmp!=NULL&&work!=NULL){
		traverseTreeInOrder(root->left,cmp,work);
		work(root->data);
		traverseTreeInOrder(root->right,cmp,work);
	}
}
void traverseTreePreOrder(TreeNode*t,int(*cmp)(void*,void*),void(*work)(void*)){
#ifndef NDEBUG
	fprintf(stderr,"info:traverseTreePreOrder:start\n");
#endif
	if(t!=NULL&&cmp!=NULL&&work!=NULL){
	}else{
#ifndef NDEBUG
		fprintf(stderr,"error::invalid arguments\n");
#endif
	}
#ifndef NDEBUG
	fprintf(stderr,"info:traverseTreePreOrder:end\n");
#endif
}
void traverseTreePostOrder(TreeNode*t,int(*cmp)(void*,void*),void(*work)(void*)){
#ifndef NDEBUG
	fprintf(stderr,"info:traverseTreePostOrder:start\n");
#endif
	if(t!=NULL&&cmp!=NULL&&work!=NULL){
	}else{
#ifndef NDEBUG
		fprintf(stderr,"error::invalid arguments\n");
#endif
	}
#ifndef NDEBUG
	fprintf(stderr,"info:traverseTreePostOrder:end\n");
#endif
}
void testTree(void){
#ifndef NDEBUG
	fprintf(stderr,"info:testTree:start\n");
#endif
	const int minVal=0;
	const int maxVal=100;
	TreeNode*root=NULL;
	TreeNode*root_=root;
	
	initializeTree(&root,memcpy((Data*)malloc(sizeof(Data)),&(Data){0,minVal+rand()%(maxVal-minVal),0,0},sizeof(Data)));
	for(size_t i=0;i<128;++i){
		root_=root;
		Data*d=(Data*)malloc(sizeof(Data));
		memcpy(d,&(Data){i+1,minVal+rand()%(maxVal-minVal),0,0},sizeof(Data));
		insertTreeNode(&root_,(int(*)(void*,void*))compareData,d);
	}
	traverseTreeInOrder(root,(int(*)(void*,void*))compareData,(void(*)(void*))printData);
	deleteTree(root);
#ifndef NDEBUG
	fprintf(stderr,"info:testTree:end\n");
#endif
}
