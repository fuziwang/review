#include <stdio.h>

#define LIST_INITSIZE 100
#define ElemType int
#define Status int
#define OK     1
#define ERROR  0

typedef struct
{
	ElemType elem[LIST_INITSIZE];
	int length;
}SqList;

Status InitList(SqList *L); 
Status ListInsert(SqList *L, int i,ElemType e);
Status ListDelete(SqList *L,int i,ElemType *e);
void ListPrint(SqList L);
void DisCreat(SqList A,SqList *B,SqList *C);

/*

	初始化：Status InitList(SqList *L); 
	插入：Status ListInsert(SqList *L, int i,ElemType e);
	删除：Status ListDelete(SqList *L,int i,ElemType *e);
	输出打印：void ListPrint(SqList L);
	拆分：void DisCreat(SqList A,SqList *B,SqList *C);

*/

Status InitList(SqList *L)
{
	L->length = 0;
	return OK;
}

Status ListInsert(SqList *L, int i,ElemType e)
{
	if(i<0 || i>L->length+1)
		return ERROR;
	if(L->length >= LIST_INITSIZE)
		return ERROR;
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

void DisCreat(SqList A,SqList *B,SqList *C)
{
	int i = 1,j = 1;
	for(int k = 1;k<=A.length;k++)
	{
		if(A.elem[k-1] < 0)
		{
			ListInsert(B,i,A.elem[k-1]);
			i++;
		} else {
			ListInsert(C,j,A.elem[k-1]);
			j++;
		}
	}
}


int main(void)
{
	SqList L;
	SqList B, C;
	int i;
	ElemType e;
	ElemType data[9] = {11,-22,33,-3,-88,21,77,0,-9}; 
	InitList(&L);
	InitList(&B);
	InitList(&C);
	
	for (i = 1; i <= 9; i++)
	{
		ListInsert(&L,i,data[i-1]);
	}
	printf("插入完成后L = : ");
	ListPrint(L);
	ListDelete(&L,1,&e);
	printf("删除第1个后L = : ");
	ListPrint(L);
	DisCreat(L , &B, &C);
	printf("拆分L后B = : ");
	ListPrint(B);
	printf("拆分L后C = : ");
	ListPrint(C);
	printf("拆分L后L = : ");
	ListPrint(L);

	return 0;
}