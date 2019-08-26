#include <stdio.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
	ElemType data;
	int cur;
}SLinkList[MAXSIZE];


// 寻找静态链表中第一个为e的值
int LocateElem(SLinkList S,ElemType e)
{
	int i = S[0].cur;
	while(i!=0)
	{
		if(S[i].data == e)
			break;
		i = S[i].cur;
	}
	return i;
}

// 初始化备用链表
void InitList(SLinkList *S)
{
	for(int i = 0;i<MAXSIZE-1;i++)
		S[i]->cur = i+1;
	S[MAXSIZE-1] = 0;
}

// Malloc函数
int Malloc(SLinkList *S)
{
	int i = S[0]->cur;
	if(S[0]->cur) // 注意判断 如果不为0才有可用结点 结点未满
		S[0]->cur = S[i].cur;
	return i;
}

// Free函数
void Free(SLinkList *S,int k)
{
	S[k]->cur = S[0]->cur;
	S[0]->cur = k;
}