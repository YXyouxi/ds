#define _CRT_SECURE_NO_WARNINGS 1
//#define MaxSize 10
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
//����4-2-25������a[MaxSize]����һ��ѭ�����У�frontָ��ѭ�������ж�ͷԪ�ص�ǰһ��λ�ã�rearָ���βԪ�ص�λ�ã�
//���ö��еĹ���������¸�С�⡣
//��1��д����front��rear��MaxSize��ʾ������Ԫ�ظ����Ĺ�ʽ
//(2)���ɾ�������е�k��Ԫ�ص��㷨
//(3)����ڶ����е�k��Ԫ��֮�����item���㷨
//(4)ָ������������ʱ�临�Ӷ�
//�⣨1��:(rear+MaxSize-front)%MaxSize;
//�⣨2����
//#define ElemType int
//bool DeleteK(ElemType a[], int k, int* front, int* rear)
//{
//	int count = (*rear + MaxSize - *front) % MaxSize;
//	int i = 0;
//	ElemType tmp;
//	if (k<0 || k>count) {
//		return false;
//	}
//	for (i = 1; i <= count; i++) {
//		*front = ((*front) + 1) % MaxSize;
//		tmp = a[*front];
//		if (i != k) {
//			*rear = (*rear + 1) % MaxSize;
//			a[*rear] = tmp;
//		}
//	}
//	return true;
//}
////�⣨3����
//bool EnItem(ElemType a[], int k, int* front, int* rear,ElemType item)
//{
//	ElemType tmp;
//	int i = 0;
//	int count = (*rear - *front + MaxSize) % MaxSize;
//	if (k <= 0 || k > count) {
//		return false;
//	}
//	for (i = 1; i <= count; i++) {
//		*front = (*front + 1) % MaxSize;
//		tmp = a[*front];
//		if (i == k+1) {
//			*rear = (*rear + 1) % MaxSize;
//			a[*rear] = item;
//		}
//		*rear = (*rear + 1) % MaxSize;
//		a[*rear] = tmp;
//	}
//	return true;
//}
////�⣨4����DeleteK��ʱ�临�Ӷ���O��n����EnItem��ʱ�临�Ӷ���O��n��������n��a�е�Ԫ�ظ���
//void print(ElemType a[],int front,int rear)
//{
//	int count = (rear + MaxSize - front) % MaxSize;
//	for (int i = 1; i < count; i++) {
//		front = (front + 1) % MaxSize;
//		printf("%d ", a[front]);
//	}
//	printf("\n");
//}
//int main()
//{
//	//SqQueue Q;
//	//InitQueue(&Q);
//	ElemType a[MaxSize];
//	int front = 0;
//	int rear = MaxSize-1;
//	for (int i = 1; i < MaxSize-1; i++) {
//		a[i] = i;
//	}
//	print(a, front, rear);
//	DeleteK(a, 3, &front, &rear);
//	print(a, front, rear);
//	EnItem(a, 3, &front, &rear, 10);
//	print(a, front, rear);
//	return 0;
//}
#define MaxSize 100
#define M 4
#define N 4
int mg[M + 2][N + 2] = {
	{1,1,1,1,1,1},{1,0,0,0,1,1},{1,0,1,0,0,1},
	{1,0,0,0,1,1},{1,0,0,0,0,1},{1,1,1,1,1,1}
};
int count = 1;
int minpathlen = 0;
int getminpathlen(int x1, int y1, int x2, int y2)
{
	int i, j, k, di;
	struct {
		int i, j;
		int pre;
	}Qu[MaxSize];
	int front = -1, rear = -1;
	rear++;
	Qu[rear].i = x1; Qu[rear].j = y1; Qu[rear].pre = -1;
	mg[x1][y1] = -1;
	while (front != rear) {
		front++;
		i = Qu[front].i; j = Qu[front].j;
		if (i == x2 && j == y2) {
			k = front;
			while (k != -1) {
				k = Qu[k].pre;
				minpathlen++;
			}
			return 1;
		}
		for (di = 0; di < 4; di++) {
			switch (di) {
			case 0:i = Qu[front].i - 1; j = Qu[front].j; break;
			case 1:i = Qu[front].i; j = Qu[front].j + 1; break;
			case 2:i = Qu[front].i + 1; j = Qu[front].j; break;
			case 3:i = Qu[front].i; j = Qu[front].j - 1; break;
			}
			if (mg[i][j] == 0) {
				rear++;
				Qu[rear].i = i; Qu[rear].j = j;
				Qu[rear].pre = front;
				mg[i][i] = -1;
			}
		}
	}
	return 0;
}
struct
{
	int x;
	int y;
}path[MaxSize];
void mgpath(int x1, int y1, int x2, int y2, int d)
{
	int di, i, j, k;
	if (x1 == x2 && y1 == y2) {
		path[d].x = x1;
		path[d].y = y1;
		d++;
		if (d == minpathlen) {
			printf("����Թ�·��%d: ", count++);
			for (k = 0; k < d; k++) {
				printf("(%d,%d) ", path[k].x, path[k].y);
			}
			printf("\n");
		}
	}
	else {
		if (mg[x1][y1] == 0) {
			di = 0;
			while (di < 4) {
				switch (di) {
				case 0:i = x1 - 1; j = y1; break;
				case 1:i = x1; j = y1 + 1; break;
				case 2:i = x1 + 1; j = y1; break;
				case 3:i = x1; j = y1 - 1; break;
				}
				path[d].x = x1;
				path[d].y = y1;
				d++;
				mg[x1][y1] = -1;
				mgpath(i, j, x2, y2, d);
				d--;
				mg[x1][y1] = 0;
				di++;
			}
		}
	}
}
int main()
{
	int i, j;
	printf("�Թ��������·�����£�\n");
	if (getminpathlen(1, 1, M, N)) {
		for (i = 1; i <= M; i++)
			for (j = 1; j <= N; j++)
				if (mg[i][j] == -1)
					mg[i][j] = 0;
		mgpath(1, 1, M, N, 0);
		printf("����Թ�·�����ȣ�%d\n", minpathlen);
	}
	else {
		printf("�������κ��Թ�·��\n");
	}
}