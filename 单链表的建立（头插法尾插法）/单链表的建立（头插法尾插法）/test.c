#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;
//尾插法正向建立单链表
LinkList List_TailInsert(LinkList* L)
{
	int x = 0;
	*L = (LinkList)malloc(sizeof(LNode));//建立头结点
	(*L)->next = NULL;
	LNode* s, * r = *L;//r为表尾指针
	(void)scanf("%d", &x);
	while (x != 9999) {	//取一个比较特殊的值作为结束标志
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;	//r指向新的表尾结点
		(void)scanf("%d", &x);
	}
	r->next = NULL;	//尾结点指向空指针
	return *L;
}
////头插法反向建立单链表
//LinkList List_HeadInsert(LinkList* L)
//{
//	int x = 0;
//	*L = (LinkList)malloc(sizeof(LNode));//建立头结点
//	(*L)->next = NULL;	//初始为空链表
//	LNode* s;	
//	scanf("%d", &x);
//	while (x != 9999) {	//输入9999表示结束
//		s = (LNode*)malloc(sizeof(LNode));//创建新节点
//		s->data = x;
//		s->next = (*L)->next;
//		(*L)->next = s;	//将新节点插入到链表中
//		scanf("%d", &x);
//	}
//	return *L;
//}
void print(LinkList L)
{
	LinkList tmp = L->next;
	while (L != NULL) {
		printf("%d", tmp->data);
		tmp = tmp->next;
	}
}
bool InitList(LinkList* L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if ((*L) == NULL)
		return false;
	(*L)->next = NULL;
	return true;
}
int main()
{
	LinkList L;
	InitList(&L);//初始化单链表
	L = List_TailInsert(&L);
	//L = List_HeadInsert(&L);
	print(L);
	return 0;
}