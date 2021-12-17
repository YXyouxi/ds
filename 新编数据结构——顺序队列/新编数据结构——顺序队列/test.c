#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 10
#include<stdio.h>
#include<stdbool.h>
//typedef struct
//{
//	int data[MaxSize];
//	int rear, front;
//}SqQueue;
////初始化
//void InitQueue(SqQueue* Q)
//{
//	Q->rear = Q->front = 0;
//}
////判空
//bool QueueEmpty(SqQueue Q)
//{
//	if (Q.rear == Q.front) {
//		return true;
//	}
//	return false;
//}
////进队
//bool EnQueue(SqQueue* Q, int x)
//{
//	if ((Q->rear + 1) % MaxSize == Q->front) {
//		return false;
//	}
//	Q->data[Q->rear] = x;
//	Q->rear = (Q->rear + 1) % MaxSize;
//	return true;
//}
////出队
//bool DeQueue(SqQueue* Q, int* x)
//{
//	if (QueueEmpty(*Q)) {
//		return false;
//	}
//	*x = Q->data[Q->front];
//	Q->front = (Q->front + 1) % MaxSize;
//	return true;
//}
//例题4-2-21：设计一个算法，利用队列的基本运算返回指定队列中的队尾元素
//int Last(SqQueue Q)
//{
//	if (QueueEmpty(Q)) {
//		return 0;
//	}
//	SqQueue tmpQ;
//	int x;
//	InitQueue(&tmpQ);
//	while (!QueueEmpty(Q)) {
//		DeQueue(&Q, &x);
//		EnQueue(&tmpQ, x);
//	}
//	while (!QueueEmpty(tmpQ)) {
//		DeQueue(&tmpQ, &x);
//		EnQueue(&Q, x);
//	}
//	return x;
//}
//例题4-2-22：设计一个算法，利用队列和栈的基本运算将指定队列中的内容进行逆转
//bool Reverse(SqQueue* Q)
//{
//	if (QueueEmpty(*Q)) {
//		return false;
//	}
//	int x;
//	SqStack S;
//	InitStack(&S);
//	while (!QueueEmpty(*Q)) {
//		DeQueue(Q, &x);
//		Push(&S, x);
//	}
//	while (!StackEmpty(S)) {
//		Pop(&S, &x);
//		EnQueue(&Q, x);
//	}
//	return true;
//}
//例题4-2-23：对于顺序队来说，如果知道队头元素的位置和队列中的元素个数，则队尾元素所在位置显然是可以计算的，也就是说
//可以用队列中的元素个数代替队尾指针，设计出这种循环顺序对的初始化、进队、出队、判空算法
//typedef struct
//{
//	int data[MaxSize];
//	int front, count;
//}SqQueue;
//初始化
//void InitQueue(SqQueue* Q)
//{
//	Q->front = Q->count = 0;
//}
//判空
//bool QueueEmpty(SqQueue Q)
//{
//	if (Q.count == 0) {
//		return true;
//	}
//	return false;
//}
//入队
//bool EnQueue(SqQueue* Q, int x)
//{
//	if (Q->count == MaxSize) {
//		return false;
//	}
//	Q->data[(Q->front + Q->count)%MaxSize] = x;
//	Q->count++;
//	return true;
//}
//出队
//bool DeQueue(SqQueue* Q, int* x)
//{
//	if (QueueEmpty(*Q)) {
//		return false;
//	}
//	*x = Q->data[Q->front];
//	Q->front = (Q->front + 1) % MaxSize;
//	Q->count--;
//	return true;
//}
//例题4-2-24：设计一个循环队列，用front和rear 分别作为队头和队尾指针，另外用一个标志tag标识队列可能空(0)或可能满(1)，这样
//加上front==rear可以作为队空或队满的条件，要求设计对列的相关基本运算
//typedef struct
//{
//	int data[MaxSize];
//	int rear, front;
//	int tag;
//}SqQueue;
////初始化
//void InitQueue(SqQueue* Q)
//{
//	Q->front = Q->rear = Q->tag = 0;
//}
////判空
//bool QueueEmpty(SqQueue Q)
//{
//	if (Q.rear == Q.front && Q.tag == 0) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
////插入
//bool EnQueue(SqQueue* Q,int x)
//{
//	if (Q->rear == Q->front && Q->tag == 1) {
//		return false;
//	}
//	Q->data[Q->rear] = x;
//	Q->rear = (Q->rear + 1) % MaxSize;
//	Q->tag = 1;
//	return true;
//}
////删除
//bool DeQueue(SqQueue* Q, int* x)
//{
//	if (QueueEmpty(*Q)) {
//		return false;
//	}
//	*x = Q->data[Q->front];
//	Q->front = (Q->front + 1) % MaxSize;
//	Q->tag = 0;
//	return true;
//}
int main()
{
	SqQueue Q;
	InitQueue(&Q);
	return 0;
}