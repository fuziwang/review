#include <stdio.h>

typedef struct
{
	char *ch;
	int length;
}HString;

bool StrInsert(HString *S,int pos,HString T)
{
	if(pos < 1 || pos > S->length+1)
		return false;
	S->ch = (char *)realloc(S->ch,sizeof(char)*(S->length + T.length));
	if(!S->ch)
		return false;
	// 现在将pos后面的移动到pos + T.length位置
	for(int i = S->length -1;i>=pos-1;i--)
		S->ch[i+T.length] = S->ch[i];
	for(int i = pos-1;i<pos+T.length-1;i++)
		S->ch[i] = T.ch[i-pos+1];// 插入T
	return true;
}

void Contact(HString *T,HString s1,HString s2)
{
	if(T->ch) free(T->ch);// 如果T原来有值 释放原来的空间
	T->ch = (char *)malloc(sizeof(char)*(s1.length + s2.length));
	if(!T->ch)
		return false;
	for(int i = 0;i<s1.length;i++)
		T->ch[i] = s1[i];
	for(int i = 0;i<s2.length;i++)
		T->ch[i+s1.length] = s2[i];
	T->length = s1.length + s2.length;
}

bool SubString(HString *Sub,HString s,int pos,int len)
{
	if(pos < 1 || pos > s.length || len < 0 || len > s.length -pos +1)
		return false;
	if(Sub->ch)
		free(Sub->ch);
	if(!len)
	{
		Sub->ch = NULL;
		Sub->length = 0;// 证明这是空子串
	}
	else
	{
		Sub->ch = (char *)malloc(sizeof(char)*len);
		if(!Sub->ch)
			return false;
		Sub->length = len;
		for(int i = pos-1;i<pos-1+len;i++)
			Sub->ch[i-pos+1] = s.ch[i];
	}
	return true;
}

bool StrCopy(HString *T,HString S)
{
	if(T->ch)
		free(T->ch);
	if(S.length != 0)
	{
		T->ch = (char *)malloc(sizeof(char)*S.length);
		if(!T->ch)
			return false;
		T->length = S.length;
		for(int i = 0;i<S.length;i++)
			T->ch[i] = S.ch[i];
	} else {
		T->ch = NULL;
		T->length = 0;
	}
	return true;
}

bool StrAssign(HString *T,char *chars)
{
	if(T->ch)
		free(T->ch);
	int i = 0;
	for(char c = chars;*c;c++)
		i++;
	if(!i)
	{
		T->ch = NULL;
		T->length = 0;
	}
	else
	{
		T->ch = (char *)malloc(sizeof(char)*i);
		if(!T->ch)
			return false;
		for(int j = 0;j<i;j++)
			T->ch[j] = chars[j];
		T->length = i;
	}
	return true;
}

int StrCompare(HString s,HString t)
{
	for(int i = 0;i<s.length && i < t.length;i++)
		if(s.ch[i] != t.ch[i])	return s.ch[i]-t.ch[i];
	return s.length - t.length;// 证明都一样 那么返回长度之比
}

bool ClearString(HString *S)
{
	if(S->ch)
	{
		free(S->ch);
		S->ch = NULL;
	}
	S->length = 0;
	return true;
}
