#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct LinkNode
{
	char data;
	struct LinkNode* next;
}*LiStack;
//��ʼ��
void InitStack(LiStack* S)
{
	(*S) = (LiStack)malloc(sizeof(struct LinkNode));
	(*S)->next = NULL;
}
//�п�
bool Empty(LiStack S)
{
	if (S->next == NULL)
		return true;
	else
		return false;
}
//��ջ
bool Push(LiStack* S, char x)
{
	LiStack p = (LiStack)malloc(sizeof(struct LinkNode));
	if (p == NULL)
		return false;
	p->data = x;
	p->next = (*S)->next;
	(*S)->next = p;
	return true;
}
//��ջ
bool Pop(LiStack* S, char* x)
{
	if ((*S)->next == NULL)//ջ��
		return false;
	*x = (*S)->data;
	LiStack p = (*S)->next;
	(*S)->next = (*S)->next->next;
	free(p);
	return true;
}
//ȡջ��Ԫ��
bool GetTop(LiStack S, int* x)
{
	if ((*S).next == NULL)
		return false;
	*x = S->next->data;
	return true;
}
//����3-3-11��д��һ���㷨�ж������Ĳ��������Ƿ�Ϸ��������豻�ж��Ĳ��������Ѵ���һά�ַ�����A�У���I��ʾ��O��ʾ����
//bool Judge(char A[], int length)
//{
//	LiStack S;
//	S = (LiStack)malloc(sizeof(struct LinkNode));
//	if (S == NULL) {
//		return false;
//	}
//	S->next = NULL;
//	int i = 0;
//	char x = 0;
//	for (i = 0; i < length; i++) {
//		if (A[i] == 'I') {
//			Push(&S, A[i]);//I���ջ����Ϊ�����Ƚ����г���
//		}
//		else if (A[i] == 'O') {
//			if (Empty(S)) {
//				return false;//ƥ��ʧ�ܣ���Oû��I
//			}
//			Pop(&S, &x);
//		}
//		else {
//			return false;
//		}
//	}
//	return Empty(S);
//}
//����3-3-12���Բ���ͷ�ڵ�ĵ�����洢��ջ����Ƴ�ʼ��ջ���ж�ջ�Ƿ�Ϊ�գ���ջ�ͳ�ջ����Ӧ���㷨
//typedef struct LinkNode
//{
//	int data;
//	struct LinkNode* next;
//}*LiStack;
////��ʼ��
//bool InitStack(LiStack* S)
//{
//	(*S) = NULL;
//}
////�п�
//bool StackEmpty(LiStack S)
//{
//	return S == NULL;
//}
////��ջ
//bool Push(LiStack* S, int x)
//{
//	LiStack p = (LiStack)malloc(sizeof(struct LinkNode));
//	if (p == NULL) {
//		return false;
//	}
//	p->data = x;
//	p->next = (*S);
//	(*S) = p;
//	return true;
//}
////��ջ
//bool Pop(LiStack* S, int* x)
//{
//	LiStack p;
//	if ((*S) == NULL) {
//		return false;
//	}
//	p = *S;
//	*x = p->data;
//	(*S) = p->next;
//	free(p);
//	p = NULL;
//	return true;
//}
//����3-3-13����һ����ͷ���ĵ�����L�����һ���㷨����һ����ջ�������н������
//typedef struct Linknode
//{
//	int data;
//	struct Linknode* next;
//}LNode,*LinkList;
//void InitList(LinkList* L)
//{
//	(*L) = (LinkList)malloc(sizeof(LNode));
//	(*L)->next == NULL;
//}
//bool Reverse(LinkList* L)
//{
//	LiStack S;
//	S == NULL;//����һ������ͷ�ڵ����ջ
//	LinkList q;
//	LinkList p = (*L)->next;//��p��ָ����ջ
//	while (p != NULL) {
//		q = p->next;
//		p->next = S;//p����ջ
//		S = p;
//		p = q;
//	}
//	q = L;//qָ���½������β���
//	while (S != NULL) {//��ջ���н��
//		q->next = S;
//		q = S;
//		S = S->next;
//	}
//	q->next = NULL;//β����next����ΪNULL
//	return true;
//}
int main()
{
	/*char A[10] = "IOIIOIOO";
	char B[10] = "IOOIOIIO";*/

	return 0;
}