#include <stdio.h>

typedef int SElemType;

typedef struct SNode
{
	SElemType data;
	struct SNode *next;
}SNode,*LinkStack;

bool InitStack(LinkStack *S)
{
	(*S) = NULL;
	return true;
}

bool GetTop(LinkStack S,SElemType *e)
{
	if(S == NULL)
		return false;
	*e = S->data;
	return true;
}

bool Push(LinkStack *S,SElemType e)
{
	LinkStack q = (LinkStack)malloc(sizeof(SNode));
	if(!p)
		return false;
	q->data = e;
	q->next = *S;
	*S = q;
	return true;
}

bool Pop(LinkStack *S,SElemType *e)
{
	if(*S == NULL)
		return false;
	*e = (*S)->data;
	LinkStack p = *S;
	*S = p->next;
	free(p);
	return true;
}