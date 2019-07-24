#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100 // 线性表存储空间的初识分配量
#define LISTINCREMENT 10 // 线性表存储空间的分配增量

typedef int ElemType;

typedef struct
{
	ElemType *elem;  // 数组指针 指示线性表的基地址 
	int length;     // 当前长度
	int listsize;   // 当前分配的存储容量（以sizeof(ElemType)为单位）
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

// 销毁顺序表
void DestoryList(SqList *L)
{
	free(L->elem);
	L->length = 0;
	L->listsize = 0;
}

// 判断顺序表是否为空
bool ListEmpty(SqList L)
{
	if(L.length == 0)
		return true;
	else
		return false;
}

// 得到顺序表的长度
int ListLength(SqList L)
{
	return L.length;
}

/*
	得到顺序表的第i个元素
	函数参数：SqList L 线性表L		int i 数据元素的位置		ElemType *e	第i个数据元素的值
*/
bool GetElem(SqList L,int i,ElemType *e)
{
	if(i<=L.length && i>=1)
	{
		*e = L.elem[i-1];
		return true;
	}
	else
	{
		return false;
	}
}

//得到顺序表指定元素的位置	函数参数：SqList L	线性表L		ElemType e	数据元素e	int (*fp)()	用于比较相等的函数指针
int LocateElem(SqList L,ElemType e,int (*fp)(ElemType,ElemType))
{
	ElemType a;
	for(int i = 0;i<L.length;i++)
	{
		if(e == L.elem[i])
		{
			a = i;
			break;
		}
	}
	return (*fp)(a,0);
}

// 得到顺序表指定元素的前驱
bool PriorElem(SqList L,ElemType cur_e,ElemType *pre_e)
{
	int i;
	for(i = 0;i<L.length;i++)
	{
		if(L.elem[i] == cur_e)
		{
			if(i != 0)
			{
				// 代表不是第一个元素
				*pre_e = L.elem[i-1];
				return true;
			}
			else
				return false;
		}
	}
	if(i >= L.length)
		return false;
}

bool NextElem(SqList L,ElemType cur_e,ElemType *next_e)
{
	int i;
	for(i = 0;i<L.length;i++)
	{
		if(L.elem[i] == cur_e)
		{
			if(i!=L.length -1)
			{
				*next_e = L.elem[i+1];
				return true;
			}
			else
				return false;
		}
	}
	if(i>=L.length)
		return false;
}

// 遍历顺序表
void ListTraverse(SqList L,void (*fp)(ElemType))
{
	for(int i = 0;i<L.length;i++)
	{
		(*fp)(L.elem[i]);
	}
}

// 清空顺序表
void ClearList(SqList *L)
{
	L->length = 0;
}

// 插入顺序表操作
bool ListInsert(SqList *L, int i, ElemType e)
{
	ElemType *newspace;
	ElemType *p,*q;
	if(i > L->length+1 || i<1)// 注意这个加1
		return false;
	if(L->length >= L->listsize)
	{
		newspace = (ElemType *)realloc(L->elem,sizeof(ElemType)*(LISTINCREMENT+L->listsize));
		if(NULL == newspace)
			return false;
		L->elem = newspace;
		L->listsize+=LISTINCREMENT;
	}
	p = &(L->elem[i-1]);
	for(q = &(L->elem[L->length - 1]);q>=p;--q)
		*(q+1) = *q;
	*p = e;
	++L->length;
	return true;
}

// 删除顺序表操作
bool ListDelete(SqList *L,int i,ElemType *e)
{
	ElemType *p,*q;
	if(i>L->length || i<i)
		return false;
	p = &(L->elem[i-1]);
	*e = *p;
	q = &(L->elem[L->length -1]);
	for(;p<q;p++)
		*p = *(p+1);
	--L->length;
	return true;
}

int compare(ElemType x, ElemType y)
{
	return(x-y);
}

void visit(ElemType e)
{
	printf("%d\n", e);
}

int main()
{
	SqList L;
	if(InitList(&L))
		printf("初始化成功!\n");
	else
		printf("初始化失败!\n");
	ListInsert(&L,1,1);
	ListInsert(&L,1,2);
	ListInsert(&L,1,3);
	ListInsert(&L,1,4);
	ListTraverse(L,visit);
	int a;
	ListDelete(&L,2,&a);
	ListTraverse(L,visit);
	printf("\n");
	printf("删除的元素为 %d \n",a);
	PriorElem(L,2,&a);
	printf("\n");
	printf(" 2 的前驱元素为 %d \n",a);
	NextElem(L,2,&a);
	printf("\n");
	printf(" 2 的后继元素为 %d \n",a);
	return 0;
}