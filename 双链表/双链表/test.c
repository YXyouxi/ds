#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct DNode
{
	int data;
	struct DNode* prior, * next;
}DNode,*DLinkList;
//初始化带头结点的双链表
bool InitDLinkList(DLinkList* L)
{
	(*L) = (DNode*)malloc(sizeof(DNode));
	if (*L == NULL)
		return false;
	(*L)->next = NULL;
	(*L)->prior = NULL;
	return true;
}
//在p结点之后插入s结点
bool InsertNextDNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	if (p->next != NULL)	//如果p结点之后有结点
		p->next->prior = s;
	p->next = s;
	s->prior = p;
	return true;
}
//删除p结点的后继结点q
bool DeleteNextDNode(DNode* p)
{
	if (p == NULL)
		return false;
	DNode* q = p->next;//找到p的后继
	if (q == NULL)		//没有后继
		return false;
	p->next = q->next;
	if (p->next != NULL)	//q结点不是最后一个结点
		q->next->prior = p;
	free(q);
	return true;
}
//删除双链表
void DestroyList(DLinkList* L)
{
	//循环删除各个节点
	while ((*L)->next != NULL) {
		DeleteNextDNode(L);
	}
	free(L);
	L = NULL;
}
int main()
{
	DLinkList L;
	InitDLinkList(&L);
	return 0;
}