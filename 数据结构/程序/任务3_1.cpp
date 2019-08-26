#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

/*
    初始化：bool InitList(LinkList *L);
    销毁：void DestroyList(LinkList *L);
    遍历：void ListTraverse(LinkList L, void (*fp)(ElemType));
    插入：bool ListInsert(LinkList L, int i, ElemType e);
    删除：bool ListDelete(LinkList L, int i, ElemType *e);
    求长度：int  ListLength(LinkList L);
    逆置：bool Inverse(LinkList L);
    排序链表：bool SortList(LinkList *L);
	删除倒数第K个结点：bool ListDelete_K(LinkList *L,int k,ElemType *e);
*/

bool InitList(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if(!(*L))
		return false;
    (*L)->data = INT_MIN;
	(*L)->next = NULL;
	return true;
}

void DestroyList(LinkList *L)
{
	LinkList p = *L;
	while(p)
	{
		(*L) = p->next;
		free(p);
		p = *L;
	}
}

void ListTraverse(LinkList L)
{
	LinkList p = L->next;
	while(p)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
}

bool ListInsert(LinkList *L,int i,ElemType e)
{
	LinkList s = (LinkList)malloc(sizeof(LNode));
	if(!s)
		return false;
	LinkList p = (*L);
	int j = 0;
	while(p && j<i-1)
	{
		p = p->next;
		j++;
	}
	if(!p || j>i-1)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool ListDelete(LinkList *L,int i,ElemType *e)
{
	LinkList p = (*L)->next;
	if(p == NULL)
		return false;// 空链表
	int j = 0;
	while(p && j < i-1)
	{
		p =p->next;
		j++;
	}
	if(!p || j>i-1)
		return false;
	LinkList s = p->next;
	*e = s->data;
	p->next = s->next;
	free(s);
	return true;
}

int ListLength(LinkList L)
{
	LinkList p = L->next;
	int i = 0;
	while(p)
	{
		p = p->next;
		i++;
	}
	return i;
}

bool Inverse(LinkList *L)
{
	LinkList p = (*L)->next;
	LinkList s = NULL;
	LinkList q = NULL;
	while(p)
	{
		q = p->next;
		p->next = s;
		s = p;
		p = q;
	}
	(*L)->next = s;
	return true;
}

bool ListDelete_K(LinkList *L,int k,ElemType *e)
{
	int length = ListLength(*L);
	printf("length:%d",length);
	LinkList p = (*L)->next;
	int j = 0;
	while(p && j<length - k-1)
	{
		p = p->next;
		j++;
	}
	if(!p || j > length -k-1)
		return false;
	LinkList s = p->next;
	*e = s->data;
	p->next = s->next;
	free(s);
	return true;
}

bool SortList(LinkList *L)
{
	// 从小到大
	LinkList p,s,q,t,pre;
    if(!(*L)->next || !(*L)->next->next)
    	return false;
	else
	{
		p=(*L)->next;
		s=p->next;
		p->next=NULL;
		while(s)
		{
			q=s;
			s=s->next;
			t=*L;
			while(t && q->data > t->data)
			{
				pre=t;
				t=t->next;
			}
			q->next=pre->next;
			pre->next=q;
		}
		return true;
	}
}

int main()
{
    LinkList L;
    InitList(&L);
    ListInsert(&L,1,11);
    ListInsert(&L,2,-22);
    ListInsert(&L,3,33);
    ListInsert(&L,4,-3);
    ListInsert(&L,5,-88);
    ListInsert(&L,6,21);
    ListInsert(&L,7,77);
    ListInsert(&L,8,0);
    ListInsert(&L,9,-9);
    ListTraverse(L);
    printf("长度：%d\n",ListLength(L));
    int a;
    ListDelete_K(&L,3,&a);
    ListTraverse(L);
    printf("a:%d",a);
    Inverse(&L);
    printf("逆置:\n");
    ListTraverse(L);
    SortList(&L);
    ListTraverse(L);
	return 0;
}
