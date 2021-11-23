#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 50
#include<stdio.h>
#include<stdbool.h>
typedef struct
{
	int data[MaxSize];
	int length;
}SqList;
void InitList(SqList* L)
{
	L->length = 0;
}
void print(SqList L)
{
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.data[i]);
	printf("\n");
}
//��֪һ��˳���L�����е�Ԫ�ص������У�����һ��x���Ա��ֵ�������
bool insert(SqList* L, int x)
{
	int i = 0;
	while (L->data[i] <= x && i < L->length)
		i++;
	for (int j = L->length; j > i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = x;
	L->length++;
	return true;
}
//���һ����Ч�㷨����˳��������Ԫ�����ã�Ҫ��ռ临�Ӷ�O��1��
bool reverse(SqList* L)
{
	if (L->length == 0)
		return false;
	int i = 0;
	int j = L->length - 1;
	while (i < j) {
		int tmp = L->data[i];
		L->data[i] = L->data[j];
		L->data[j] = tmp;
		i++;
		j--;
	}
	return true;
}
//���һ����Ч�㷨����˳�����ɾ������Ԫ��ֵΪx��Ԫ�أ�Ҫ��ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��1��
//�ⷨ1��
// ����˳���L��������ֵΪx��k+1����һ��������Ϊxʱ�������Ԫ��ǰ��k��λ��
//bool Delete(SqList* L, int x)
//{
//	if (L->length == 0)
//		return false;
//	int i = 0;
//	int k = 0;//��¼�����˼���x
//	for (i = 0; i < L->length; i++) {
//		if (L->data[i] == x)//iָ��Ϊx��Ԫ��
//			k++;
//		else 
//			L->data[i - k] = L->data[i];//��Ϊx��Ԫ��ǰ��k��λ��
//	}
//	L->length = L->length - k;//������k
//	return true;
//}
//�ⷨ��
//k��ʾ�±���L��Ԫ�ظ���������L����������x��������data[k]�У�k+1������x������
//bool Delete(SqList* L, int x)
//{
//	if (L->length == 0)
//		return false;
//	int i = 0;
//	int k = 0;//��ʾ�±���Ԫ�ظ���
//	for (i = 0; i < L->length; i++) {
//		if (L->data[i] != x) {
//			L->data[k] = L->data[i];
//			k++;
//		}
//	}
//	L->length = k;
//	return true;
//}
//�ⷨ������L��������a=(a0,a1,...an-1)������ֵ��Ϊx��Ԫ�ػ���Ϊһ��i���䣬Ԫ�ظ���Ϊi+1����ʼi-1��
//������ֵΪx��Ԫ�ػ���Ϊһ��j���䣬��a[i+1,j-1]����ʼҲΪ�գ���j=0������L
//��Ϊx��������ֱ��ִ��j+1������Ϊx���浽i���䣬i++������i��j����
//ͨ�׽��ͣ���ǰ��������x��ʱ��ֱ�������ˣ�������һ����x��Ԫ�ص�ʱ����i��¼��λ�ã�j���������ߣ��ٴ���������x��Ԫ��
//Ȼ�����Ԫ�غ�i����λ��
bool Delete(SqList* L, int x)
{
	if (L->length == 0)
		return false;
	int i = -1;
	int j = 0;
	while (j < L->length) {
		if (L->data[j] != x) {//�ҵ���Ϊx��Ԫ��
			i++;//����Ϊx�����䳤��
			if (i != j) {//��a[j]��������Ϊx�������ĩβ
				int tmp = L->data[i];
				L->data[i] = L->data[j];
				L->data[j] = tmp;
			}
		}
		j++;
	}
	L->length = i + 1;
	return true;
}
void test1()
{
	SqList L;
	InitList(&L);
	for (int i = 0; i < 10; i = i++) {
		L.data[i] = i;
		L.length++;
	}
	print(L);
	insert(&L, 5);
	print(L);
	reverse(&L);
	print(L);
	Delete(&L, 5);
	print(L);
}
int main()
{
	test1();
	return 0;
}