#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 10
#include<stdio.h>
#include<stdbool.h>
//typedef struct
//{
//	int data[MaxSize];
//	int rear, front;
//}SqQueue;
////��ʼ��
//void InitQueue(SqQueue* Q)
//{
//	Q->rear = Q->front = 0;
//}
////�п�
//bool QueueEmpty(SqQueue Q)
//{
//	if (Q.rear == Q.front) {
//		return true;
//	}
//	return false;
//}
////����
//bool EnQueue(SqQueue* Q, int x)
//{
//	if ((Q->rear + 1) % MaxSize == Q->front) {
//		return false;
//	}
//	Q->data[Q->rear] = x;
//	Q->rear = (Q->rear + 1) % MaxSize;
//	return true;
//}
////����
//bool DeQueue(SqQueue* Q, int* x)
//{
//	if (QueueEmpty(*Q)) {
//		return false;
//	}
//	*x = Q->data[Q->front];
//	Q->front = (Q->front + 1) % MaxSize;
//	return true;
//}
//����4-2-21�����һ���㷨�����ö��еĻ������㷵��ָ�������еĶ�βԪ��
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
//����4-2-22�����һ���㷨�����ö��к�ջ�Ļ������㽫ָ�������е����ݽ�����ת
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
//����4-2-23������˳�����˵�����֪����ͷԪ�ص�λ�úͶ����е�Ԫ�ظ��������βԪ������λ����Ȼ�ǿ��Լ���ģ�Ҳ����˵
//�����ö����е�Ԫ�ظ��������βָ�룬��Ƴ�����ѭ��˳��Եĳ�ʼ�������ӡ����ӡ��п��㷨
//typedef struct
//{
//	int data[MaxSize];
//	int front, count;
//}SqQueue;
//��ʼ��
//void InitQueue(SqQueue* Q)
//{
//	Q->front = Q->count = 0;
//}
//�п�
//bool QueueEmpty(SqQueue Q)
//{
//	if (Q.count == 0) {
//		return true;
//	}
//	return false;
//}
//���
//bool EnQueue(SqQueue* Q, int x)
//{
//	if (Q->count == MaxSize) {
//		return false;
//	}
//	Q->data[(Q->front + Q->count)%MaxSize] = x;
//	Q->count++;
//	return true;
//}
//����
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
//����4-2-24�����һ��ѭ�����У���front��rear �ֱ���Ϊ��ͷ�Ͷ�βָ�룬������һ����־tag��ʶ���п��ܿ�(0)�������(1)������
//����front==rear������Ϊ�ӿջ������������Ҫ����ƶ��е���ػ�������
//typedef struct
//{
//	int data[MaxSize];
//	int rear, front;
//	int tag;
//}SqQueue;
////��ʼ��
//void InitQueue(SqQueue* Q)
//{
//	Q->front = Q->rear = Q->tag = 0;
//}
////�п�
//bool QueueEmpty(SqQueue Q)
//{
//	if (Q.rear == Q.front && Q.tag == 0) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
////����
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
////ɾ��
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