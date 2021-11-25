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
//����2-2-18����֪һ��˳���L�����е�Ԫ�ص������У�����һ��x���Ա��ֵ�������
//bool insert(SqList* L, int x)
//{
//	int i = 0;
//	while (L->data[i] <= x && i < L->length)
//		i++;
//	for (int j = L->length; j > i; j--) {
//		L->data[j] = L->data[j - 1];
//	}
//	L->data[i] = x;
//	L->length++;
//	return true;
//}
//����2-2-19�����һ����Ч�㷨����˳��������Ԫ�����ã�Ҫ��ռ临�Ӷ�O��1��
//bool reverse(SqList* L)
//{
//	if (L->length == 0)
//		return false;
//	int i = 0;
//	int j = L->length - 1;
//	while (i < j) {
//		int tmp = L->data[i];
//		L->data[i] = L->data[j];
//		L->data[j] = tmp;
//		i++;
//		j--;
//	}
//	return true;
//}
//����2-2-20�����һ����Ч�㷨����˳�����ɾ������Ԫ��ֵΪx��Ԫ�أ�Ҫ��ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��1��
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
//bool Delete(SqList* L, int x)
//{
//	if (L->length == 0)
//		return false;
//	int i = -1;
//	int j = 0;
//	while (j < L->length) {
//		if (L->data[j] != x) {//�ҵ���Ϊx��Ԫ��
//			i++;//����Ϊx�����䳤��
//			if (i != j) {//��a[j]��������Ϊx�������ĩβ
//				int tmp = L->data[i];
//				L->data[i] = L->data[j];
//				L->data[j] = tmp;
//			}
//		}
//		j++;
//	}
//	L->length = i + 1;
//	return true;
//}
//����2-2-21����һ������˳���L��ɾ��Ԫ��ֵ��x��y��x<=y)������Ԫ�أ�Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
//�ⷨһ����Ӧ��һ��ⷨһ��ֻ���ж������ı�
//bool Delete(SqList* L, int x, int y)
//{
//	if(x>y)
//		return false;
//	if (L->length == 0)
//		return false;
//	int i = 0;
//	int k = 0;//ͳ����x-y��Χ�ڵ�Ԫ�ظ���
//	for (i = 0; i < L->length; i++) {
//		if (L->data[i] >= x && L->data[i] <= y)
//			k++;
//		else
//			L->data[i - k] = L->data[i];
//	}
//	L->length = L->length - k;
//	return true;
//}
//�ⷨ������Ӧ��һ��ⷨ��
//bool Delete(SqList* L, int x, int y)
//{
//	if(x>y)
//		return false;
//	if (L->length == 0)
//		return false;
//	int i = 0;
//	int k = 0;//��¼������x-y��Ԫ�صĸ���
//	for (i = 0; i < L->length; i++) {
//		if (L->data[i]<x || L->data[i]>y) {
//			L->data[k] = L->data[i];
//			k++;
//		}
//	}
//	L->length = k;
//	return true;
//}
//�ⷨ������Ӧ��һ��ⷨ��
//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//bool Delete(SqList* L, int x, int y)
//{
//	if (x > y)
//		return false;
//	if (L->length == 0)
//		return false;
//	int i = -1;//��ʾ����Ҫ������䳤��
//	int j = 0;//��������
//	for (j = 0; j < L->length; j++) {
//		if (L->data[j]<x || L->data[j]>y) {
//			i++;
//			if (i != j) {
//				swap(&(L->data[i]), &(L->data[j]));
//			}
//		}
//	}
//	L->length = i + 1;
//	return true;
//}
//����2-2-22������һ�����������˳���L������ɾ��Ԫ��ֵ��x��y��x<=y)������Ԫ�أ�Ҫ��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)
//�⣺
//bool Delete(SqList* L, int x, int y)
//{
//	if (L->length == 0)
//		return false;
//	if (x > y)
//		return false;
//	int i = 0;//��¼��һ�����ڵ���x��λ��
//	int j = 0;//��¼��һ������y��λ��
//	int k = 0;//���ڱ���
//	while (i < L->length && L->data[i] < x)//���ҵ�һ�����ڵ���x��Ԫ�ص�λ��
//		i++;
//	if (i >= L->length)//���е�Ԫ�ض���xС
//		return false;
//	j = i;
//	while (j < L->length && L->data[j] <= y)//���ҵ�һ������y��Ԫ�ص�λ��
//		j++;
//	while (j < L->length)
//		L->data[i++] = L->data[j++];
//	L->length = i + 1;
//	return true;
//}
//����2-2-23����һ��˳���L����Ԫ��Ϊ���ͣ����һ���㷨��L������С��0���������ַ���ǰ�벿�֣����ڻ����0���������ں�벿��
//�ⷨһ���ο�2-2-20�ⷨ������Ϊ��������͸������䣬����������i��ʾ����
//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//bool move(SqList* L)
//{
//	if (L->length == 0) {
//		return false;
//	}
//	int i = -1;//���ڼ�¼����������λ��
//	int j = 0;//���ڱ���
//	while (j < L->length) {
//		if (L->data[j] < 0) {
//			i++;
//			if (i != j) {//˵����������֮��������
//				swap(&(L->data[i]), &(L->data[j]));//�ڸ�������β��������������
//			}
//		}
//		j++;
//	}
//	return true;
//}
//�ⷨ������L�����˲��ң�ǰ���Ҵ��ڵ���0��Ԫ�أ�λ��Ϊi���������С��0��Ԫ�أ�λ��Ϊj�����ҵ�������λ�õ�Ԫ�ؽ���
//bool move(SqList* L)
//{
//	if (L->length == 0) {
//		return false;
//	}
//	int i = 0;//��ͷ��
//	int j = L->length - 1;//�Ӻ���
//	while (i < j) {
//		while (i < j && L->data[i] < 0) {
//			i++;//��ǰ����Ҵ��ڵ���0��Ԫ��λ��
//		}
//		while (i < j && L->data[j] >= 0) {
//			j--;//�Ӻ���ǰ��С��0��Ԫ�ص�λ��
//		}
//		if (i < j) {//����
//			int tmp = L->data[i];
//			L->data[i] = L->data[j];
//			L->data[j] = tmp;
//		}
//	}
//	return true;
//}
//����2-2-25�����һ���㷨������˳�����ɾ���ظ���Ԫ�أ���ʹʣ��Ԫ�ؼ����Դ��򱣳ֲ���
//�⣺��i��1��ʼ��������L->data[0....j]��û���ظ�Ԫ�أ�ɨ��Ԫ��ʱ��L->data[i]��j��ÿ��Ԫ�ض�����ͬ����ӵ�β��
//bool DelSame(SqList* L, int x)
//{
//	if (L->length == 0)
//		return false;
//	int i = 1, j = 0, k = 0;
//	for (i = 1; i < L->length; i++) {
//		k = 0;
//		while (k <= j && L->data[i] != L->data[k]) {
//			k++;//������j��Ԫ��
//		}
//		if (k > j) {//˵��û�к�j��Ԫ����ͬ��
//			j++;//j���䳤�ȼ�һ
//			L->data[j] = L->data[i];
//		}
//	}
//	L->length = j + 1;
//	return true;
//}
//����2-2-25�����һ���㷨������˳�����ɾ���ظ���Ԫ�أ���ʹʣ��Ԫ�ؼ����Դ��򱣳ֲ���
//�⣺
//bool DelSame(SqList* L, int x)
//{
//	if (L->length == 0) {
//		return false;
//	}
//	int i = 1, j = 0;//j�������治�ظ���Ԫ�ظ���
//	for (i = 1; i < L->length; i++) {
//		if (L->data[i] != L->data[j]) {//ÿ��ֻ��Ҫ�Ƚ����һ��Ԫ�غ��²��ҵ�Ԫ���Ƿ���ͬ
//			j++;//����ͬ����������1
//			L->data[j] = L->data[i];
//		}
//	}
//	L->length = j + 1;
//	return true;
//}
//����2-2-26����˳����ʾ���ϣ����һ���㷨ʵ���������ϵ��󽻼�����
//�⣺
//bool Intersection(SqList A, SqList B, SqList* L)
//{
//	if (A.length == 0 || B.length == 0) {
//		return false;
//	}
//	int i = 0;//���ڱ���A
//	int j = 0;//���ڱ���B
//	int k = 0;//��¼L��Ԫ�ظ���
//	for (i = 0; i < A.length; i++) {
//		j = 0;
//		while (j<B.length&&A.data[i] != B.data[j]) {
//			j++;
//		}
//		if (j < B.length) {//��ʾA.data[i]��B������ͬԪ�أ�����ŵ�L��
//			L->data[k] = A.data[i];
//			k++;
//		}
//	}
//	L->length = k;//�޸ĳ���
//	return true;
//}
//����2-2-27�������ʾ���ϵ�˳�����һ������˳������һ����Ч�㷨ʵ���������ϵ��󽻼�����
//bool Intersection(SqList A, SqList B, SqList* L)
//{
//	if (A.length == 0 || B.length == 0) {
//		return false;
//	}
//	int i = 0;//����A
//	int j = 0;//����B
//	int k = 0;//��¼L��Ԫ�ظ���
//	while (i < A.length && j < B.length) {
//		if (A.data[i] == B.data[j]) {//ABԪ����ͬ������L��ijk�ֱ��һ
//			L->data[k] = A.data[i];
//			i++;
//			j++;
//			k++;
//		}
//		else if (A.data[i] < B.data[j]) {
//			i++;//A�����
//		}
//		else {
//			j++;//B�����
//		}
//	}
//	L->length = k;
//}
//����2-2-28����˳����ʾ���ϣ����һ���㷨ʵ���������ϵ��󲢼�����
//bool Union(SqList A, SqList B, SqList* L)
//{
//	if (A.length == 0 || B.length == 0) {
//		return false;
//	}
//	int i = 0;//����A������L
//	for (i = 0; i < A.length; i++) {
//		L->data[i] = A.data[i];//��A��Ԫ�ظ��Ƶ�L��
//	}
//	int j = 0;//����B���Һ�L�в�һ���Ĵ���L
//	int k = A.length;//L���м���Ԫ��
//	for (i = 0; i < B.length; i++) {//����B
//		j = 0;
//		while (j < A.length && A.data[j] != B.data[i]) {
//			j++;
//		}
//		if (j == A.length) {//��ʾB.data[i]����A�У�����ŵ�L��
//			L->data[k++] = B.data[i];
//		}
//	}
//	L->length = k;
//	return true;
//}
void test1()
{
	SqList L;
	SqList A;
	SqList B;
	InitList(&L);
	InitList(&A);
	InitList(&B);
	int i = 0;
	/*for (i = 0; i < 10; i++) {
		L.data[i] = i;
		L.length++;
	}*/
	for ( i = 0; i < 10; i++) {
		A.data[i] = i;
		A.length++;
	}
	int j = 20;
	for ( i = 0; i < 10; i++) {
		B.data[i] = j;
		j-=2;
		B.length++;
	}
	print(A);
	print(B);
	//insert(&L, 5);
	//insert(&L, 8);
	//print(L);
	//reverse(&L);
	//print(L);
	//Delete(&L, 3,5);
	//move(&L);
	//DelSame(&L, 5);
	//Intersection(A, B, &L);
	//Union(A, B, &L);
	print(L);
}
int main()
{
	test1();
	return 0;
}