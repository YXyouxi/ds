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
	*x = S->data[S->top];
	S->top = S->top - 1;
	return true;
}
//打印
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
//例题3-2-16：设计一个算法，利用栈的基本运算返回指定栈中的栈底元素，要求仍保持栈中元素不变
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
//例题3-2-17：设计一个算法，采用一个顺序栈逆向输出单链表L中的所有元素
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
//例题3-2-18：设计一个算法，采用一个顺序栈判断单链表L中所有元素的正反序是否相同
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
//例题3-2-19:假设表达式中允许包含圆括号，方括号和大括号3种括号，设计一个算法采用顺序栈判断表达式中的括号是否正确匹配
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
//例题3-2-20：给定一个字符串str，设计一个算法采用顺序栈判断str是否为形如"序列1@序列2"的合法字符串
//其中序列2是序列1的逆序，str中恰好只有一个@字符
//bool Judge(char str[])
//{
//	SqStack S;
//	InitStack(&S);
//	int i = 0;
//	while (str[i] != '\0' && str[i] != '@') {
//		Push(&S, str[i]);//@前的字符全部入栈
//	}
//	if (str[i] == '\0') {
//		return false;//没有@
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
//		return false;//后边的长前边的短
//	}
//	if (!StackEmpty(S)) {
//		return false;//后边的短前边的长
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