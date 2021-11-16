#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//����һ������ͷ���ĵ�����
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;

//��ʼ��һ������������ͷ��㣩
bool InitList(LinkList* L)
{
	(*L)->next = NULL;
	return true;
}

//��λ����루����ͷ�ڵ㣩
bool LinkInsert(LinkList* L, int i, int e)
{
	if (i < 1)
		return false;
	if (i == 1) {	//�����һ���ڵ�Ĳ����������ڵ㲻ͬ
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = *L;
		*L = s;		//ͷָ��ָ��ǰ���½ڵ�
		return true;
	}
	LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
	p = *L;//Lָ��ͷ���
	int j = 1;//��ǰpָ��ָ��ڼ������
	while (p != NULL && j < i - 1) {	//ѭ���ҵ���i-1����㣨��ΪҪ�����i����������ǰһ����
		p = p->next;
		j++;
	}
	if (p == NULL)	//iֵ���Ϸ�
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;//�����s����p֮��
	return true;
}

int main()
{
	LinkList L;//����һ��ͷָ��
	InitList(&L);//��ʼ��һ���ձ�
	LinkInsert(&L, 2, 3);//����ڵ�
	return 0;
}