#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 10
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//˳��ջ
typedef struct
{
	int data[MaxSize];//��̬�����д��ջ��Ԫ��
	int top;//ջ��ָ�룬һ����˵��������±�
}SqStack;
//����ջ
typedef struct
{
	int data[MaxSize];
	int top0;//0��ջջ��ָ��
	int top1;//1��ջջ��ָ��
}ShStack;
//��ʼ��������ջ��
void InitStack(ShStack* S)
{
	S->top0 = 0;		//0��ջ�������ϴ�
	S->top1 = MaxSize;	//1��ջ�������´�
}
//��ʼ��(˳��ջ��
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
	x = S->data[S->top];
	S->top = S->top - 1;
	return true;
}
//��ջ��Ԫ��
bool GetTop(SqStack S, int* x)
{
	if (S.top == -1)//ջ��
		return false;
	x = S.data[S.top];
	return true;
}
int main()
{
	SqStack S;
	return 0;
}
