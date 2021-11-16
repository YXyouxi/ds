#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//定义一个不带头结点的单链表
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;

//初始化一个单链表（不带头结点）
bool InitList(LinkList* L)
{
	(*L)->next = NULL;
	return true;
}

//按位序插入（不带头节点）
bool LinkInsert(LinkList* L, int i, int e)
{
	if (i < 1)
		return false;
	if (i == 1) {	//插入第一个节点的操作与其他节点不同
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = *L;
		*L = s;		//头指针指向当前的新节点
		return true;
	}
	LNode* p;//指针p指向当前扫描到的结点
	p = *L;//L指向头结点
	int j = 1;//当前p指针指向第几个结点
	while (p != NULL && j < i - 1) {	//循环找到第i-1个结点（因为要插入第i个，所以找前一个）
		p = p->next;
		j++;
	}
	if (p == NULL)	//i值不合法
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;//将结点s连到p之后
	return true;
}

int main()
{
	LinkList L;//创建一个头指针
	InitList(&L);//初始化一个空表
	LinkInsert(&L, 2, 3);//插入节点
	return 0;
}