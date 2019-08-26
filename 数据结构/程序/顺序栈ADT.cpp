#include <stdio.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;

typedef struct 
{
	SElemType *top;
	SElemType *base;
	int stacksize;
}SqStack;

bool InitStack(SqStack *S)
{
	S->base = (SElemType *)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
	if(!S->base);
		return false;
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return true;
}

bool GetTop(SqStack S,SElemType *e)
{
	if(S.top == S.base)
		return false;
	*e = *(S.top-1);
	return true;
}

bool Push(SqStack *S,SElemType e)
{
	if((S->top - S->base) >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base,sizeof(SElemType)*(S->stacksize + S->STACKINCREMENT));
		if(!S->base)
			return false;
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top++) = e;
	return true;
}

bool Pop(SqStack *S,SElemType *e)
{
	if(S->top == S->base)
		return false;
	*e = *(--S->top);
	return true;
}