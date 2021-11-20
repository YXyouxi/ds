#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//定义，规定所有操作都是在单链表的表头进行的
typedef struct Linknode
{
	int data;
	struct Linknode* next;
}LiStack;
//初始化
void InitLinknode(LiStack* S)
{
	S = (LiStack*)malloc(sizeof(LiStack));
	S->next = NULL;
}
//判空
bool Empty(LiStack S)
{
	if (S.next == NULL)
		return true;
	else
		return false;
}
//进栈
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
//出栈
bool Pop(LiStack* S, int* x)
{
	if (S->next == NULL)//栈空
		return false;
	x = S->data;
	LiStack* p = S->next;
	S->next = S->next->next;
	free(p);
	return true;
}
//取栈顶元素
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