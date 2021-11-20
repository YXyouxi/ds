#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 10
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//顺序栈
typedef struct
{
	int data[MaxSize];//静态数组中存放栈中元素
	int top;//栈顶指针，一般来说是数组的下标
}SqStack;
//共享栈
typedef struct
{
	int data[MaxSize];
	int top0;//0号栈栈顶指针
	int top1;//1号栈栈顶指针
}ShStack;
//初始化（共享栈）
void InitStack(ShStack* S)
{
	S->top0 = 0;		//0号栈从下往上存
	S->top1 = MaxSize;	//1号栈从上往下存
}
//初始化(顺序栈）
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
//新元素入栈
bool Push(SqStack* S, int x)
{
	if (S->top == MaxSize - 1)//栈满
		return false;
	S->top = S->top + 1;
	S->data[S->top] = x;
	return true;
}
//出栈操作
bool Pop(SqStack* S, int* x)
{
	if (S->top == -1)//栈空
		return false;
	x = S->data[S->top];
	S->top = S->top - 1;
	return true;
}
//读栈顶元素
bool GetTop(SqStack S, int* x)
{
	if (S.top == -1)//栈空
		return false;
	x = S.data[S.top];
	return true;
}
int main()
{
	SqStack S;
	return 0;
}
