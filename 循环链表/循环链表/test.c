#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
////����ѭ��������
//typedef struct LNode
//{
//	int data;
//	struct LNode* next;
//}LNode,*LinkList;
////��ʼ��һ��ѭ��������
//bool InitList(LinkList* L)
//{
//	(*L) = (LNode*)malloc(sizeof(LNode));
//	if (*L == NULL)
//		return false;
//	(*L)->next = *L;//ͷ���nextָ��ͷ���
//	return true;
//}
////�п�
//bool Emptey(LinkList L)
//{
//	if (L->next == L)
//		return true;
//	return false;
//}
////�жϽ��p�ǲ������һ�����
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

//����ѭ��˫����
typedef struct DNode
{
	int data;
	struct DNode* prior, * next;
}DNode,*DLinkList;
//��ʼ��ѭ��˫����
bool InitDLinkList(DLinkList* L)
{
	(*L) = (DNode*)malloc(sizeof(DNode));
	if (*L == NULL)
		return false;
	(*L)->next = *L;
	(*L)->prior = *L;
	return true;
}
//�п�
bool Emptey(DLinkList L)
{
	if (L->next == L)
		return true;
	return false;
}
//�жϽ��p�ǲ������һ�����
bool isTail(DLinkList L, DNode* p)
{
	if (p->next == L)
		return true;
	return false;
}
//��p�ڵ�֮�����s���
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