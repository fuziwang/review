#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct
{
	ElemType * elem;
	int length;
	int listsize;
}SqList;

bool ListInsert_Sort(SqList *L,ElemType e)
{
	if(L->length >= L->listsize)
	{
		L->elem = (ElemType *)realloc(L->elem,sizeof(ElemType)*(L->listsize + LISTINCREMENT));
		if(!L->elem)
			return false;
		L->listsize += LISTINCREMENT;
	}

	int key = 1;

	if(e <= L->elem[0]){
		key = 1;
	} else if(e > L->elem[L->length - 1]){
		key = L->length+1;
	} else {
		for(int i = 0;i<L->length-1;i++)
		{
			if( e > L->elem[i] && e <= L->elem[i+1])
			{
				key = i+2;
				break;
			}
		}
	}

	for(int j = L->length;j>key-1;j--)
		L->elem[j] = L->elem[j-1];

	++L->length;
	return true;
}