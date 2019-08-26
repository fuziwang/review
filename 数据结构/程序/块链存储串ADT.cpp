#define CHUNKSIZE 80

// 块链存储串意味着每一个节点存放多个字符串 节点之间用指针链接

typedef struct Chunk{
	char ch[CHUNKSIZE];
	struct Chunk *next;
}Chunk;

// 为了方便对串处理 一般设置头指针和尾指针 同时设置串的长度

typedef struct
{
	Chunk * head,*tail;
	int chunklen;// 串的长度
}LString;