#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//#define InitSize 10
//#define MaxSize 10
//typedef struct
//{
//	int data[MaxSize];
//	int length;
//}SqList;
//
//void InitList(SqList* L)
//{
//	(*L).length = 0;
//}
//
//typedef struct
//{
//	int* data;
//	int MaxSize;
//	int length;
//}SeqList;
//
//void InitList(SeqList* L)
//{
//	L->data = (SeqList*)malloc(sizeof(SeqList)* InitSize);
//	L->MaxSize = InitSize;
//	L->length = 0;
//}
//
//bool IncreaseList(SeqList* L,int len)
//{
//	int* p = L->data;
//	L->data=(int*)malloc(sizeof(int) * (L->MaxSize + len));
//	if (L->data == NULL)
//		return false;
//	for (int i = 0; i < L->length; i++) {
//		L->data[i] = p[i];
//	}
//	L->MaxSize = L->MaxSize + len;
//	free(p);
//	return true;
//}
//
//bool ListInsert(SqList* L, int i, int e)
//{
//	if (i < 1 ||i>L->length+1|| L->length >= MaxSize)
//		return false;
//	for (int j = L->length; j >= i; j--) {
//		L->data[j] = L->data[j - 1];
//	}
//	L->data[i - 1] = e;
//	L->length++;
//	return true;
//}
//
//bool ListDelete(SqList* L, int i, int* e)
//{
//	if (i<1 || i>L->length || L->length == 0)
//		return false;
//	*e = L->data[i - 1];
//	for (int j = i; j < L->length; j++) {
//		L->data[j - 1] = L->data[j];
//	}
//	L->length--;
//	return true;
//}
//
//bool ListInsert(SeqList* L, int i, int e)
//{
//	if (i<1 || i>L->length + 1)
//		return false;
//	if (L->length == L->MaxSize)
//		IncreaseList(&L, 5);
//	for (int j = L->length; j >= i; j++)
//		L->data[j] = L->data[j - 1];
//	L->data[i - 1] = e;
//	L->length++;
//	return true;
//}
//
//int GetElem(SqList L, int i)
//{
//	if (i<1 || i>L.length)
//		return -1;
//	return L.data[i - 1];
//}
//
//int GetElem(SeqList L, int i)
//{
//	return L.data[i - 1];
//}
//
//int LocateElem(SqList L, int e)
//{
//	for (int i = 0; i < L.length; i++) {
//		if (L.data[i] == e)
//			return i + 1;
//	}
//	return -1;
//}
//
//int main()
//{
//	SqList L;
//	SeqList L;
//	InitList(&L);
//	IncreaseList(&L,5);
//	ListInsert(&L, 3 ,5 );
//	int x = -1;
//	ListDelete(&L, 3, &x);
//	GetElem(L, 3);
//	return 0;
//}

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;

bool InitList(LinkList* L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if (*L == NULL)
		return false;
	(*L)->next = NULL;
	return true;
}

LNode* GetElem(LinkList* L, int i)
{
	if (i < 0)
		return NULL;
	LNode* p;
	int j = 0;
	p = *L;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return NULL;
	return p;
}

LNode* LocateElem(LinkList* L, int e)
{
	if ((*L)->next == NULL)
		return NULL;
	LNode* p = (*L)->next;
	while (p!=NULL&&p->data!=e) {
		p = p->next;
	}
	return p;
}

int length(LinkList* L)
{
	LNode* p = *L;
	int len = 0;
	while (p->next!= NULL) {
		p = p->next;
		len++;
	}
	return len;
}

//int length(LinkList* L)
//{
//	LNode* p = *L;
//	int len = 1;
//	while (p->next != NULL) {
//		p = p->next;
//		len++;
//	}
//}

bool ListDelete(LinkList* L, int i, int* e)
{
	/*if (i < 1)
		return false;
	LNode* p;
	int j = 0;
	p = (*L);
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}*/
	LNode* p = GetElem(L, i - 1);
	if (p == NULL)
		return false;
	if (p->next == NULL)
		return false;
	LNode* s = p->next;
	*e = s->data;
	p->next = s->next;
	free(s);
	s = NULL;
	return true;
}

//bool ListDelete(LinkList* L, int i, int* e)
//{
//	if (i < 1)
//		return false;
//	if (i == 1) {
//		LNode* p = (*L);
//		*e = p->data;
//		(*L) = (*L)->next;
//		p->next = NULL;
//		free(p);
//		p = NULL;
//		return true;
//	}
//}

bool DeleteNode(LNode* p)
{
	if (p == NULL)
		return false;
	LNode* s = p->next;
	p->data = p->next->data;
	p->next = s->next;
	free(s);
	s = NULL;
	return true;
}



bool InsertPriorNode(LNode* p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->data = p->data;
	s->next = p->next;
	p->next = s;
	p->data = e;
	return true;
}

bool InsertNextNode(LNode* p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool ListInsert(LinkList* L, int i, int e)
{
	/*if (i < 1)
		return false;
	LNode* p = *L;
	int j = 0;
	while (j < i - 1 && p != NULL) {
		p = p->next;
		j++;
	}*/
	LNode* p = GetElem(L, i - 1);
	/*if (p == NULL)
		return false;
	p->data = e;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;*/
	return InsertNextNode(p, e);
}

//bool ListInsert(LinkList* L, int i, int e)
//{
//	if (i < 1)
//		return false;
//	if (i == 1) {
//		LNode* s = (LNode*)malloc(sizeof(LNode));
//		if (s == NULL)
//			return false;
//		s->data = e;
//		s->next = *L;
//		(*L) = s;
//		return true;
//	}
//
//}

LinkList List_TailInsert(LinkList* L)
{
	int x = 0;
	LNode* p;
	LNode* r = *L;//±íÎ²Ö¸Õë
	scanf("%d", &x);
	while (x != 9999) {
		p = (LNode*)malloc(sizeof(LNode));
		p->data = x;
		r->next=p;
		r = p;
		scanf("%d", &x);
	}
	r->next = NULL;
	return *L;
}

LinkList List_HeadInsert(LinkList* L)
{
	LNode* s;
	int x = 0;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		scanf("%d", &x);
	}
	return *L;
}

//LinkList List_HeadInsert(LinkList* L)
//{
//	LNode* s;
//	int x = 0;
//	scanf("%d", &x);
//	while (x != 9999) {
//		s = (LNode*)malloc(sizeof(LNode));
//		s->data = x;
//		s->next = *L;
//		*L = s;
//		scanf("%d", &x);
//	}
//	return *L;
//}

int main()
{
	LinkList L;
	InitList(&L);
	ListInsert(&L, 3, 5);
	int x = -1;
	return 0;
}