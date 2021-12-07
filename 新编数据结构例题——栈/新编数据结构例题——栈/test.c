#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 50
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct
{
	int data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack* S)
{
	S->top = -1;
}
//�п�
bool StackEmpty(SqStack S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}
//��Ԫ����ջ
bool Push(SqStack* S, int x)
{
	if (S->top == MaxSize - 1)//ջ��
		return false;
	S->top = S->top + 1;
	S->data[S->top] = x;
	return true;
}
//��ջ����
bool Pop(SqStack* S, int* x)
{
	if (S->top == -1)//ջ��
		return false;
	*x = S->data[S->top];
	S->top = S->top - 1;
	return true;
}
//��ӡ
void print(SqStack S)
{
	if (S.top == -1) {
		return;
	}
	for (int i = 0; i <= S.top; i++) {
		printf("%d ", S.data[i]);
	}
	printf("\n");
}
//����3-2-16�����һ���㷨������ջ�Ļ������㷵��ָ��ջ�е�ջ��Ԫ�أ�Ҫ���Ա���ջ��Ԫ�ز���
//bool GetBottom(SqStack S, int* x)
//{
//	if (S.top == -1) {
//		return false;
//	}
//	SqStack Q;
//	int tmp;
//	InitStack(&Q);
//	while (!(StackEmpty(S))) {
//		Pop(&S, x);
//		Push(&Q, *x);
//	}
//	while (!(StackEmpty(Q))) {
//		Pop(&Q, &tmp);
//		Push(&S, tmp);
//	}
//	return true;
//}
//����3-2-17�����һ���㷨������һ��˳��ջ�������������L�е�����Ԫ��
typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}LNode,*LinkList;
//bool ReverseDisp(LinkList L)
//{
//	if (L->next == NULL) {
//		return false;
//	}
//	SqStack S;
//	InitStack(&S);
//	LNode* p = L->next;
//	int x;
//	while (p != NULL) {
//		Push(&S, p->data);
//		p = p->next;
//	}
//	while (S.top != -1) {
//		Pop(&S, &x);
//		printf("%d", x);
//	}
//}
//����3-2-18�����һ���㷨������һ��˳��ջ�жϵ�����L������Ԫ�ص��������Ƿ���ͬ
//bool Same(LinkList L)
//{
//	if (L->next == NULL) {
//		return false;
//	}
//	LNode* p = L->next;
//	SqStack S;
//	InitStack(&S);
//	int x;
//	while (p != NULL) {
//		Push(&S, p->data);
//		p = p->next;
//	}
//	p = L->next;
//	while (S.top != -1&&p!=NULL) {
//		Pop(&S, &x);
//		if (x == p->data) {
//			p = p->next;
//		}
//		else {
//			return false;
//		}
//	}
//	return true;
//}
//����3-2-19:������ʽ���������Բ���ţ������źʹ�����3�����ţ����һ���㷨����˳��ջ�жϱ��ʽ�е������Ƿ���ȷƥ��
//bool BracketCheck(char str[], int length)
//{
//	SqStack S;
//	InitStack(&S);
//	int i = 0;
//	for (i = 0; i < length; i++) {
//		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
//			Push(&S, str[i]);
//		}
//		else {
//			if (StackEmpty(S)) {
//				return false;
//			}
//			char topElem;
//			Pop(&S, &topElem);
//			if (str[i] == ')' && topElem != '(') {
//				return false;
//			}
//			if (str[i] == ']' && topElem != '[') {
//				return false;
//			}
//			if (str[i] == '}' && topElem != '{') {
//				return false;
//			}
//		}
//	}
//	return StackEmpty(S);
//}
//����3-2-20������һ���ַ���str�����һ���㷨����˳��ջ�ж�str�Ƿ�Ϊ����"����1@����2"�ĺϷ��ַ���
//��������2������1������str��ǡ��ֻ��һ��@�ַ�
//bool Judge(char str[])
//{
//	SqStack S;
//	InitStack(&S);
//	int i = 0;
//	while (str[i] != '\0' && str[i] != '@') {
//		Push(&S, str[i]);//@ǰ���ַ�ȫ����ջ
//	}
//	if (str[i] == '\0') {
//		return false;//û��@
//	}
//	i++;
//	while (str[i] != '\0' && !StackEmpty(S)) {
//		char x;
//		Pop(&S, &x);
//		if (x != str[i]) {
//			return false;
//		}
//		i++;
//	}
//	if (str[i] != '\0') {
//		return false;//��ߵĳ�ǰ�ߵĶ�
//	}
//	if (!StackEmpty(S)) {
//		return false;//��ߵĶ�ǰ�ߵĳ�
//	}
//	return true;
//}
int main()
{
	SqStack S;
	InitStack(&S);
	for (int i = 0; i < 10; i++) {
		Push(&S, i);
	}
	print(S);
	return 0;
}