#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 10
#include<stdio.h>
#include<stdbool.h>
//定义一个栈
typedef struct
{
	char data[MaxSize];
	int top;//栈顶指针
}SqStack;
//初始化
void InitStack(SqStack* S)
{
	S->top = -1;
}
//判空
bool StackEmpty(SqStack S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}
//入栈
bool Push(SqStack* S,char x)
{
	if (S->top == MaxSize-1)//栈满
		return false;
	S->top = S->top + 1;
	S->data[S->top] = x;
	return true;
}
//出栈
bool Pop(SqStack* S, char* x)
{
	if (S->top == -1)//栈空
		return false;
	(*x) = S->data[S->top];
	S->top = S->top - 1;
	return true;
}
//判断括号匹配合法性
bool bracketCheck(char str[],int length)
{
	SqStack S;
	InitStack(&S);
	int i = 0;
	for (i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			Push(&S, str[i]);//扫描到左括号，入栈
		else {
			if (StackEmpty(S))
				return false;//栈空，出现右括号不匹配
			char topElem;
			char* p = &topElem;
			Pop(&S, p);//栈顶元素出栈
			if ((str[i] == ')' && topElem != '(') || (str[i] == ']' && topElem != '[') || (str[i] == '}' && topElem != '{'))
				return false;
		}
	}
	return StackEmpty(S);//遍历结束后，若栈空则说明匹配成功，不空则有左括号不匹配
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

