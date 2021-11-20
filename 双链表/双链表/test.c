#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct DNode
{
	int data;
	struct DNode* prior, * next;
}DNode,*DLinkList;
//��ʼ����ͷ����˫����
bool InitDLinkList(DLinkList* L)
{
	(*L) = (DNode*)malloc(sizeof(DNode));
	if (*L == NULL)
		return false;
	(*L)->next = NULL;
	(*L)->prior = NULL;
	return true;
}
//��p���֮�����s���
bool InsertNextDNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	if (p->next != NULL)	//���p���֮���н��
		p->next->prior = s;
	p->next = s;
	s->prior = p;
	return true;
}
//ɾ��p���ĺ�̽��q
bool DeleteNextDNode(DNode* p)
{
	if (p == NULL)
		return false;
	DNode* q = p->next;//�ҵ�p�ĺ��
	if (q == NULL)		//û�к��
		return false;
	p->next = q->next;
	if (p->next != NULL)	//q��㲻�����һ�����
		q->next->prior = p;
	free(q);
	return true;
}
//ɾ��˫����
void DestroyList(DLinkList* L)
{
	//ѭ��ɾ�������ڵ�
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