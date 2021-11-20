#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
////定义循环单链表
//typedef struct LNode
//{
//	int data;
//	struct LNode* next;
//}LNode,*LinkList;
////初始化一个循环单链表
//bool InitList(LinkList* L)
//{
//	(*L) = (LNode*)malloc(sizeof(LNode));
//	if (*L == NULL)
//		return false;
//	(*L)->next = *L;//头结点next指向头结点
//	return true;
//}
////判空
//bool Emptey(LinkList L)
//{
//	if (L->next == L)
//		return true;
//	return false;
//}
////判断结点p是不是最后一个结点
//bool isTail(LinkList L, LNode* p)
//{
//	if (p->next == L)
//		return true;
//	return false;
//}
//int main()
//{
//	LinkList L;
//	return 0;
//}

//创建循环双链表
typedef struct DNode
{
	int data;
	struct DNode* prior, * next;
}DNode,*DLinkList;
//初始化循环双链表
bool InitDLinkList(DLinkList* L)
{
	(*L) = (DNode*)malloc(sizeof(DNode));
	if (*L == NULL)
		return false;
	(*L)->next = *L;
	(*L)->prior = *L;
	return true;
}
//判空
bool Emptey(DLinkList L)
{
	if (L->next == L)
		return true;
	return false;
}
//判断结点p是不是最后一个结点
bool isTail(DLinkList L, DNode* p)
{
	if (p->next == L)
		return true;
	return false;
}
//在p节点之后插入s结点
bool InsertNextDNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
	s->prior = p;
	return true;
}
int main()
{
	DLinkList L;
	return 0;
}