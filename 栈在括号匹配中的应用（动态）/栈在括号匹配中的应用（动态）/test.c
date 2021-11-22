#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//定义链栈
typedef struct LiStack
{
	char data;
	struct LiStack* next;
}LStack,*LiStack;
//初始化
void InitStack(LiStack* S)
{
	(*S) = (LiStack)malloc(sizeof(LStack));
	(*S)->next = NULL;
}
//判空
bool StackEmpty(LiStack S)
{
	if (S->next == NULL)
		return true;
	else
		return false;
}
//进栈
bool Push(LiStack* S, char x)
{
	LiStack p = (LiStack)malloc(sizeof(LStack));
	if (p == NULL)
		return false;//内存分配失败
	p->data = x;
	p->next = (*S)->next;
	(*S)->next = p;
	return true;
}
//出栈
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
			Push(&S, str[i]);//扫描到左括号，入栈
		else {
			if (StackEmpty(S))
				return false;//栈中为空，说明右括号不匹配
			char topElem = 0;
			char* top = &topElem;
			Pop(&S, top);//栈顶元素出栈
			if ((topElem != '(' && str[i] == ')') || (topElem != '[' && str[i] == ']') || (topElem != '{' && str[i] == '}'))
				return false;
		}
	}
	return StackEmpty(S);//若不为空说明有左括号匹配不成功，栈空说明成功
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