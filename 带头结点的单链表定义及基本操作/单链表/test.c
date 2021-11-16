#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct LNode	//定义单链表结点类型
{
	int data;			//每个节点存放一个数据元素
	struct LNode* next;	//指针指向下一个结点
}LNode,*LinkList;

//初始化一个单链表（带头结点）
bool InitList(LinkList* L)
{
	*L = (LNode*)malloc(sizeof(LNode));//分配一个头结点
	if (*L == NULL)						  //内存不足，分配失败
		return false;
	(*L)->next = NULL;					  //头结点之后暂时还没有结点
	return true;
}

//按位查找，返回第i个结点
LNode* GetElem(LinkList* L, int i)
{
	if (i < 0)
		return NULL;
	LNode* p;	//p指向当前扫描到的结点
	int j = 0;	//j记录当前指向第几个结点
	p = *L;		//p指向头结点
	while (p != NULL || j < i ) {	//找到第i个结点
		p = p->next;
		j++;
	}
	return p;
}

//按值查找，找到数据域等于e的结点
LNode* LocateElem(LinkList* L, int e)
{
	LNode* p = (*L)->next;//从第一个节点开始查找
	while (p != NULL && p->data != e) 
		p = p->next;
	return p;//找到后返回该指针，否则返回NULL
}

//求链表长度
int length(LinkList* L)
{
	int len = 0;
	LNode* p = *L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

//后插操作：在p节点之后插入元素e
bool InsertNextNode(LNode* p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)//内存分配失败
		return false;
	s->data = e;	//保存数据e
	s->next = p->next;
	p->next = s;	//将节点s连到p之后
	return true;
}

//前插操作：在p节点之前插入元素e，因为无法找到前驱结点（从头指针找时间复杂度太高），所以直接后插，然后改数据
bool InsertPriorNode(LNode* p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->next = p->next;
	p->next = s;		//新节点s连到p之后
	s->data = p->data;	//p中元素复制到s中
	p->data = e;		//p中元素覆盖为e
	return true;
}

//删除操作：按位序删除，删除第i个位置的结点，并把删除的数据带回来
bool ListDelete(LinkList* L, int i, int* e)
{
	if (i < 1)
		return false;
	//LNode* p;
	//int j = 0;//记录当前指向第几个结点
	//LNode* p = L;//指向头结点
	//while (p != NULL || j < i - 1) {	//循环找到第i-1个结点
	//	p = p->next;
	//	j++;
	//}
	
	//有了按位查找函数可以直接调用函数
	LNode* p = GetElem(L, i - 1);

	if (p == NULL)	//i值不合法
		return false;
	if (p->next == NULL)//p之后已经无结点
		return false;
	LNode* q = p->next;//令q指向被删除的结点
	*e = q->data;		//用e返回被删除的元素
	p->next = q->next;	//将*q结点从链表中断开，即将p结点的next指针指向原本的第i+1个结点
	free(q);			//释放结点的存储空间
	q = NULL;
	return true;
}

//删除指定的结点p(同前插操作思想，偷天换日)
bool DeleteNode(LNode* p)
{
	if (p == NULL)
		return false;
	LNode* q = p->next;	//令q指向p的后继结点
	p->data = q->data;	//和后继结点交换数据域
	p->next = q->next;	//将q结点断开（即将p结点的next指向原本p+1结点的位置）
	free(q);			//释放q的内存
	q = NULL;
	return true;
	//但是这段代码有bug，当要删除的结点是最后一个时，q就会指向一个空指针，
	//那么在交换数据域的时候就会出现对空指针的操作，所以其实只能用从表头开始依次寻找p的前驱结点的方法
}

//带头结点的单链表的数据插入,在第i个位置插入元素e
bool ListInsert(LinkList* L, int i, int e)
{
	if (i < 1)
		return false;
	//LNode* p;//指针p指向当前扫描到的结点
	//p = *L;//L指向头结点
	//int j = 0;//当前p指针指向第几个结点
	//while (p != NULL && j < i - 1) {	//循环找到第i-1个结点（因为要插入第i个，所以找前一个）
	//	p = p->next;
	//	j++;
	//}
	//有了按位查找函数可以直接调用函数

	LNode* p = GetElem(L, i - 1);//找到第i-1个结点

	//if (p == NULL)	//i值不合法
	//	return false;
	//LNode* s = (LNode*)malloc(sizeof(LNode));
	//s->data = e;
	//s->next = p->next;
	//p->next = s;//将结点s连到p之后
	//return true;
	return InsertNextNode(p, e);//有了后插操作之后可以直接用函数，就不用上边的一串代码了
}

int main()
{
	LinkList L;		//声明一个指向单链表的指针
	InitList(&L);	//初始化一个空表
	ListInsert(&L, 2, 3);	//在位序为2的位置插入 元素3
}