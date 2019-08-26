#include <iostream>
using namespace std;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct
{
	ElemType * elem;
	int length;
	int listsize;
}SqList;

// 初始化顺序表
bool InitList(SqList *L)
{
	L->elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if(L->elem == NULL)
		return false;
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return true;
}

// 插入
bool ListInsert(SqList *L,int i,ElemType e)
{
	// 上面的意思表示在第i个元素位置变成e 原来的元素统一向后移 i>=1 && i <= L->length +1
	if(i > L->length+1 || i<0)
		return false;
	if(L->length >= L->listsize)
	{
		L->elem = (ElemType *)realloc(L->elem,sizeof(ElemType)*(L->listsize + LISTINCREMENT));
		if(L->elem == NULL)
			return false;
		L->listsize += LISTINCREMENT;
	}
	for(int j = L->length;j>i-1;j--)
		L->elem[j] = L->elem[j-1];
	L->elem[i-1] = e;
	++L->length;
	return true;
}

// 删除
bool ListDelete(SqList *L,int i,ElemType *e)
{
	// i>= 1 && i<=L->length
	if(i<0 || i > L->length)
		return false;
	*e = L->elem[i-1];
	for(int j = i-1;j<L->length-1;j++)
		L->elem[j] = L->elem[j+1];
	--L->length;
	return true;
}