#include <stdio.h>

#define MAXSIZE 100

typedef int QElemType;

typedef struct 
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

bool InitQueue(SqQueue *Q)
{
	Q->base = (QElemType *)malloc(sizeof(QElemType)*MAXSIZE);
	if(!Q->base)
		return false;
	Q->front = Q->rear = 0;
	return true;
}

bool QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
}

bool EnQueue(SqQueue *Q,QElemType e)
{
	if((Q->rear+1)%MAXSIZE == Q->front)
		return false;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear+1)%MAXSIZE;
	return true;
}

bool DeQueue(SqQueue *Q,QElemType *e)
{
	if(Q->front == Q->rear)
		return false;
	*e = Q->base[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return true;
}