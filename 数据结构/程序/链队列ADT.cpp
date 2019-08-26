#include <stdio.h>

typedef int QElemType;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct 
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

bool InitQueue(LinkQueue *Q)
{
	Q->front = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		return false;
	Q->rear = Q->front;
	Q->front->next = NULL;
	return true;
}

bool DestoryQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return true;
}

bool EnQueue(LinkQueue *Q,QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
		return false;
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return true;
}

bool DeQueue(LinkQueue *Q,QElemType *e)
{
	if(Q->front == Q->rear)
		return false;
	QueuePtr p = Q->front->next;
	*e = p->data;
	if(p == Q->rear)
		Q->rear = Q->front;
	Q->front->next = p->next;
	free(p);
	return true;
}