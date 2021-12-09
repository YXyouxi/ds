#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct LinkNode
{
	char data;
	struct LinkNode* next;
}*LiStack;
//初始化
void InitStack(LiStack* S)
{
	(*S) = (LiStack)malloc(sizeof(struct LinkNode));
	(*S)->next = NULL;
}
//判空
bool Empty(LiStack S)
{
	if (S->next == NULL)
		return true;
	else
		return false;
}
//进栈
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
//出栈
bool Pop(LiStack* S, char* x)
{
	if ((*S)->next == NULL)//栈空
		return false;
	*x = (*S)->data;
	LiStack p = (*S)->next;
	(*S)->next = (*S)->next->next;
	free(p);
	return true;
}
//取栈顶元素
bool GetTop(LiStack S, int* x)
{
	if ((*S).next == NULL)
		return false;
	*x = S->next->data;
	return true;
}
//例题3-3-11：写出一个算法判定所给的操作序列是否合法，（假设被判定的操作序列已存入一维字符数组A中）（I表示进O表示出）
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
//			Push(&S, A[i]);//I则进栈（因为必须先进才有出）
//		}
//		else if (A[i] == 'O') {
//			if (Empty(S)) {
//				return false;//匹配失败，有O没有I
//			}
//			Pop(&S, &x);
//		}
//		else {
//			return false;
//		}
//	}
//	return Empty(S);
//}
//例题3-3-12：以不带头节点的单链表存储链栈，设计初始化栈，判断栈是否为空，进栈和出栈等相应的算法
//typedef struct LinkNode
//{
//	int data;
//	struct LinkNode* next;
//}*LiStack;
////初始化
//bool InitStack(LiStack* S)
//{
//	(*S) = NULL;
//}
////判空
//bool StackEmpty(LiStack S)
//{
//	return S == NULL;
//}
////入栈
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
////出栈
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
//例题3-3-13：有一个带头结点的单链表L，设计一个算法利用一个链栈将其所有结点逆置
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
//	S == NULL;//定义一个不带头节点的链栈
//	LinkList q;
//	LinkList p = (*L)->next;//将p所指结点进栈
//	while (p != NULL) {
//		q = p->next;
//		p->next = S;//p结点进栈
//		S = p;
//		p = q;
//	}
//	q = L;//q指向新建链表的尾结点
//	while (S != NULL) {//出栈所有结点
//		q->next = S;
//		q = S;
//		S = S->next;
//	}
//	q->next = NULL;//尾结点的next域置为NULL
//	return true;
//}
int main()
{
	/*char A[10] = "IOIIOIOO";
	char B[10] = "IOOIOIIO";*/

	return 0;
}