#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//���壬�涨���в��������ڵ�����ı�ͷ���е�
typedef struct Linknode
{
	int data;
	struct Linknode* next;
}LiStack;
//��ʼ��
void InitLinknode(LiStack* S)
{
	S = (LiStack*)malloc(sizeof(LiStack));
	S->next = NULL;
}
//�п�
bool Empty(LiStack S)
{
	if (S.next == NULL)
		return true;
	else
		return false;
}
//��ջ
bool Push(LiStack* S, int x)
{
	LiStack* p = (LiStack*)malloc(sizeof(LiStack));
	if (p == NULL)
		return false;
	p->data = x;
	p->next = S->next;
	S->next = p;
	return true;
}
//��ջ
bool Pop(LiStack* S, int* x)
{
	if (S->next == NULL)//ջ��
		return false;
	x = S->data;
	LiStack* p = S->next;
	S->next = S->next->next;
	free(p);
	return true;
}
//ȡջ��Ԫ��
bool GetTop(LiStack S,int* x)
{
	if (S.next == NULL)
		return false;
	x = S.next->data;
	return true;
}
int main()
{
	LiStack S;
	return 0;
}