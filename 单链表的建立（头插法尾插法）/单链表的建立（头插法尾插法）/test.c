#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;
//β�巨������������
LinkList List_TailInsert(LinkList* L)
{
	int x = 0;
	*L = (LinkList)malloc(sizeof(LNode));//����ͷ���
	(*L)->next = NULL;
	LNode* s, * r = *L;//rΪ��βָ��
	(void)scanf("%d", &x);
	while (x != 9999) {	//ȡһ���Ƚ������ֵ��Ϊ������־
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;	//rָ���µı�β���
		(void)scanf("%d", &x);
	}
	r->next = NULL;	//β���ָ���ָ��
	return *L;
}
////ͷ�巨������������
//LinkList List_HeadInsert(LinkList* L)
//{
//	int x = 0;
//	*L = (LinkList)malloc(sizeof(LNode));//����ͷ���
//	(*L)->next = NULL;	//��ʼΪ������
//	LNode* s;	
//	scanf("%d", &x);
//	while (x != 9999) {	//����9999��ʾ����
//		s = (LNode*)malloc(sizeof(LNode));//�����½ڵ�
//		s->data = x;
//		s->next = (*L)->next;
//		(*L)->next = s;	//���½ڵ���뵽������
//		scanf("%d", &x);
//	}
//	return *L;
//}
void print(LinkList L)
{
	LinkList tmp = L->next;
	while (L != NULL) {
		printf("%d", tmp->data);
		tmp = tmp->next;
	}
}
bool InitList(LinkList* L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if ((*L) == NULL)
		return false;
	(*L)->next = NULL;
	return true;
}
int main()
{
	LinkList L;
	InitList(&L);//��ʼ��������
	L = List_TailInsert(&L);
	//L = List_HeadInsert(&L);
	print(L);
	return 0;
}