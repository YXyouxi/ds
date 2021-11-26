#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;
bool InitList(LinkList* L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if ((*L) == NULL)
		return false;
	(*L)->next = NULL;
	return true;
}
//尾插法
bool InsertNextList(LinkList* L)
{
	int x = 0;
	LNode* s, * r = *L;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		if (s == NULL) {
			return false;
		}
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return true;
}
//打印
void print(LinkList L)
{
	LNode* p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//例题2-3-24：设计一个算法删除单链表L中第一个值为x的结点
//解：
//bool DelFirst(LinkList* L, int x)
//{
//	if ((*L)->next == NULL) {
//		return false;
//	}
//	LNode* p = (*L);//p是要删除的结点的前驱结点
//	while (p->next!=NULL&&p->next->data != x) {
//		p = p->next;//找到p->next->data==x的结点
//	}
//	if (p->next == NULL) {//找不到
//		return false;
//	}
//	else {//删除
//		LNode* r = p->next;
//		p->next = r->next;
//		free(r);
//		r = NULL;
//	}
//	return true;
//}
//例题2-3-25：设计一个算法删除单链表L（含两个或两个以上的数据结点）中第一个值为x的结点的前驱结点
//解:
//bool DelFirst(LinkList* L, int x)
//{
//	LNode* prepre = *L;//指向值为x的结点的前驱结点的前驱结点
//	LNode* pre=(*L)->next;//指向值为x的结点的前驱结点
//	LNode* p=pre->next;//用于查找值为x的结点
//	if (pre->data == x) {//第一个值就是x,不能删除头结点
//		return false;
//	}
//	while (p->data != x && p != NULL) {//查找值为x的结点
//		prepre = pre;
//		pre = p;
//		p = p->next;//prepre，pre，p同步向后移
//	}
//	if (p == NULL) {//找不到
//		return false;
//	}
//	prepre->next = p;
//	free(pre);
//	pre = NULL;
//	return true;
//}
//例题2-3-26：设计一个算法判定单链表L是否是递增有序的
//解：
//bool isIncrease(LinkList L)
//{
//	if (L->next == NULL) {
//		return false;
//	}
//	LNode* pre = L->next;//p结点的前驱结点
//	LNode* p = pre->next;//比较和前驱结点数据的大小
//	while (p != NULL) {
//		if (p->data >= pre->data) {//保持增序，往后找
//			pre = p;
//			p = p->next;
//		}
//		else {
//			return false;
//		}
//	}
//		return true;
//}
//例题2-3-27：设计一个在带头结点的单链表L中删除第一个最小值结点的算法(没有说变量类型是int)
//解：
//bool DelMin(LinkList* L)
//{
//	if ((*L)->next == NULL) {
//		return false;
//	}
//	LNode* pre = *L;//指向查找的结点的前驱结点
//	LNode* p = pre->next;//用于查找最小值结点
//	LNode* minpre = pre;//指向最小值结点的前驱结点
//	LNode* minp = p;//保存最小值的结点的指针
//	while (p != NULL) {
//		if (p->data < minp->data) {
//			minp = p;//将较小的节点p存入minp中
//			minpre = pre;//将较小的结点的前驱结点pre存入minpre中
//		}
//		pre = p;
//		p = p->next;
//	}
//	minpre->next = minp->next;
//	free(minp);
//	minp = NULL;
//	return true;
//}
//例题2-3-28：设计一个算法删除并释放以L为表头指针的单链表的所有结点
//解：
//bool DelLink(LinkList* L)
//{
//	if ((*L)->next == NULL) {
//		return false;
//	}
//	LNode* pre = *L;//指向p结点的前驱结点
//	LNode* p = pre->next;//指向正在遍历的结点
//	while (p != NULL) {
//		free(pre);
//		pre = p;
//		p = p->next;
//	}
//	free(pre);//当p指向NULL时，pre指向尾结点，需再删除一次
//	pre = NULL;
//	return true;
//}
//例题2-3-29：有一个线性表(a1，a2,...an)，n>=2，采用带头结点的单链表L存储，设计一个算法将其就地逆置，所谓“就地”是指辅助空间为O(1)
//解：
//bool Reverse(LinkList* L)
//{
//	if ((*L)->next == NULL) {
//		return false;
//	}
//	LNode* p = (*L)->next;//p从第二个结点开始头插
//	LNode* q = p;//用来临时保存p之后的结点
//	(*L)->next = NULL;//先置L为空表，然后用p遍历，进行头插
//	while (p != NULL) {
//		q = p->next;//用q临时保存p的后继结点
//		p->next = (*L)->next;//将p插入L的首部
//		(*L)->next = p;
//		p = q;//p继续去遍历剩下的结点
//	}
//	return true;
//}
//例题2-3-30：有一个整数元素建立的单链表A，设计一个算法，将其拆分为两个单链表A和B
//A单链表中含有所有偶数结点，B单链表中含有所有奇数结点，且保持原来的相对次序
//解：
bool SplitLink(LinkList* A, LinkList* B)
{
	if ((*A)->next == NULL) {
		return false;
	}
	LNode* p = (*A)->next;//用来遍历
	LNode* ra = *A;//A的尾结点
	LNode* rb = *B;//B的尾结点
	while (p != NULL) {
		if (p->data % 2 == 0) {//偶数结点
			ra->next = p;//将p插入到A的表尾
			ra = p;
			p = p->next;//p后移
		}
		else {
			rb->next = p;//将p插入到B的表尾
			rb = p;
			p = p->next;
		}
	}
	ra->next = rb->next = NULL;
	return true;
}
void test1()
{
	LinkList A;
	LinkList B;
	InitList(&A);
	InitList(&B);
	InsertNextList(&A);
	print(A);
	//DelFirst(&L, 8);
	//isIncrease(L);
	//DelMin(&L);
	//DelLink(&L);
	//Reverse(&L);
	SplitLink(&A, &B);
	print(A);
	print(B);
}
int main()
{
	test1();
	return 0;
}