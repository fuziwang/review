#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define Status int
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define ElemType int

typedef struct
{
	ElemType * elem;
	int length;
	int listsize;
}SqList;

Status InitList(SqList *L); 
Status ListInsert(SqList *L, int i,ElemType e);
Status ListDelete(SqList *L,int i,ElemType *e);
void ListPrint(SqList L);
void DeleteMin(SqList *L);

/*
	初始化：Status InitList(SqList *L); 
	插入：Status ListInsert(SqList *L, int i,ElemType e);
	删除：Status ListDelete(SqList *L,int i,ElemType *e);
	输出打印：void ListPrint(SqList L);
	删除最小：void DeleteMin(SqList *L);
*/

Status InitList(SqList *L)
{
	L->elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if(L->elem == NULL)
		return OVERFLOW;
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

Status ListInsert(SqList *L, int i,ElemType e)
{
	if(i<0 || i>L->length+1)
		return ERROR;
	if(L->length >= L->listsize)
	{
		L->elem = (ElemType *)realloc(L->elem,sizeof(ElemType)*(L->listsize + LISTINCREMENT));
		if(!L->elem)
			return OVERFLOW;
		L->listsize += LISTINCREMENT;
	}
	for(int j = L->length;j>i-1;j--)
		L->elem[j] = L->elem[j-1];
	L->elem[i-1] = e;
	++L->length;
	return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e)
{
	if(i <0 || i>L->length)
		return ERROR;
	*e = L->elem[i-1];
	for(int j = i-1;j<L->length-1;j++)
		L->elem[j] = L->elem[j+1];
	--L->length;
	return OK;
}

void ListPrint(SqList L)
{
	for(int i = 0;i<L.length;i++)
	{
		if(i != L.length - 1)
			printf("%d ",L.elem[i]);
		else
			printf("%d\n",L.elem[i]);
	}
}

void DeleteMin(SqList *L)
{
	ElemType min = L->elem[0];
	int j = 1;
	for(int i = 2;i<=L->length;i++)
	{
		if(min > L->elem[i-1])
		{
			min = L->elem[i-1];
			j = i;
		}
	}
	ListDelete(L,j,&min);
}

int main(void)
{
	SqList L;
	int i;
	ElemType e;
	ElemType data[9] = {11,-22,-33,3,-88,21,77,0,-9}; 
	InitList(&L);
	for (i = 1; i <= 9; i++)
	{
		ListInsert(&L,i,data[i-1]);
	}
	printf("插入完成后 L = : ");
	ListPrint(L);
	ListDelete(&L, 2, &e);
	printf("删除第 2 个后L = : ");
	ListPrint(L);
	DeleteMin(&L);
	printf("删除L中最小值后L = : ");
	ListPrint(L);
	DeleteMin(&L);
	printf("删除L中最小值后L = : ");
	ListPrint(L);
	DeleteMin(&L);
	printf("删除L中最小值后L = : ");
	ListPrint(L);

	return 0;
}