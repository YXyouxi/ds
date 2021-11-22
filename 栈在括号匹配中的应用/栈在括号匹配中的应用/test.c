#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 10
#include<stdio.h>
#include<stdbool.h>
//����һ��ջ
typedef struct
{
	char data[MaxSize];
	int top;//ջ��ָ��
}SqStack;
//��ʼ��
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
//��ջ
bool Push(SqStack* S,char x)
{
	if (S->top == MaxSize-1)//ջ��
		return false;
	S->top = S->top + 1;
	S->data[S->top] = x;
	return true;
}
//��ջ
bool Pop(SqStack* S, char* x)
{
	if (S->top == -1)//ջ��
		return false;
	(*x) = S->data[S->top];
	S->top = S->top - 1;
	return true;
}
//�ж�����ƥ��Ϸ���
bool bracketCheck(char str[],int length)
{
	SqStack S;
	InitStack(&S);
	int i = 0;
	for (i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			Push(&S, str[i]);//ɨ�赽�����ţ���ջ
		else {
			if (StackEmpty(S))
				return false;//ջ�գ����������Ų�ƥ��
			char topElem;
			char* p = &topElem;
			Pop(&S, p);//ջ��Ԫ�س�ջ
			if ((str[i] == ')' && topElem != '(') || (str[i] == ']' && topElem != '[') || (str[i] == '}' && topElem != '{'))
				return false;
		}
	}
	return StackEmpty(S);//������������ջ����˵��ƥ��ɹ����������������Ų�ƥ��
}
int main()
{
	char str[10] = "(())[]{}";
	if (bracketCheck(str, 8))
		printf("yes");
	else
		printf("no");
	return 0;
}

