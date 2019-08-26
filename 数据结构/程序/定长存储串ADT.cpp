#include <stdio.h>

#define MAXSTRLEN 255

typedef unsigned char sstring[MAXSTRLEN + 1];// 首字符用来存放长度

void Concat(sstring *T,sstring s1,sstring s2)
{
	// 这个分成三个情况进行讨论
	/*
		1. s1[0] + s2[0] <= maxsize 正常拼接
		2. s1[0] + s2[0] > maxsize
		   s1[0] < maxsize s2截断
		3. s1[0] = maxsize T = s2
	*/
	if(s1[0] + s2[0] <= MAXSTRLEN)
	{
		for(int i = 1;i<=s1[0];i++)
			(*T)[i] = s1[i];
		for(int i = 1;i<=s2[0];i++)
			(*T)[i+s1[0]] = s2[i];
		(*T)[0] = s1[0] + s2[0];
	}
	else if(s1[0] < maxsize)
	{
		for(int i = 1;i<=s1[0];i++)
			(*T)[i] = s1[i];
		for(int i = 1;i<=MAXSTRLEN-s1[0];i++)
			(*T)[i+s1[0]] = s2[i];
		(*T)[0] = MAXSTRLEN;
	}
	else
	{
		for(int i = 0;i<=MAXSTRLEN;i++)
			(*T)[i] = s1[i];
	}
}

bool Substring(sstring *sub,sstring s,int pos,int len)
{
	// 注意pos的取值范围是[1,s[0]] len的取值范围为[1,s[0]-pos+1]
	if(pos<1 || pos > s[0] || len < 0 || len > s[0]-pos+1)
		return false;
	for(int i = 1;i<=len;i++)
		(*sub)[i] = s[pos+i-1];
	(*sub)[0] = len;
	return true;
}