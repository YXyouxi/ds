#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//������ջ
typedef struct LiStack
{
	char data;
	struct LiStack* next;
}LStack,*LiStack;
//��ʼ��
void InitStack(LiStack* S)
{
	(*S) = (LiStack)malloc(sizeof(LStack));
	(*S)->next = NULL;
}
//�п�
bool StackEmpty(LiStack S)
{
	if (S->next == NULL)
		return true;
	else
		return false;
}
//��ջ
bool Push(LiStack* S, char x)
{
	LiStack p = (LiStack)malloc(sizeof(LStack));
	if (p == NULL)
		return false;//�ڴ����ʧ��
	p->data = x;
	p->next = (*S)->next;
	(*S)->next = p;
	return true;
}
//��ջ
bool Pop(LiStack* S, char* x)
{
	LiStack p;
	if ((*S)->next == NULL)
		return false;
	p = (*S)->next;
	*x = p->data;
	(*S)->next = p->next;
	free(p);
	p = NULL;
	return true;
}
bool bracketCheck(char* str, int length)
{
	LiStack S;
	InitStack(&S);
	int i = 0;
	for (i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') 
			Push(&S, str[i]);//ɨ�赽�����ţ���ջ
		else {
			if (StackEmpty(S))
				return false;//ջ��Ϊ�գ�˵�������Ų�ƥ��
			char topElem = 0;
			char* top = &topElem;
			Pop(&S, top);//ջ��Ԫ�س�ջ
			if ((topElem != '(' && str[i] == ')') || (topElem != '[' && str[i] == ']') || (topElem != '{' && str[i] == '}'))
				return false;
		}
	}
	return StackEmpty(S);//����Ϊ��˵����������ƥ�䲻�ɹ���ջ��˵���ɹ�
}
int main()
{
	char str[10] = "(()[]{}";
	if (bracketCheck(str, 7))
		printf("yes");
	else
		printf("no");
	return 0;
}