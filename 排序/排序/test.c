#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
//ֱ�Ӳ�������
//void InsertSort(int A[], int n)
//{
//	int i, j, tmp;
//	for (i = 1; i < n; i++) {//����Ԫ�ز������ź����������
//		if (A[i] < A[i - 1]){//��A[i]�ؼ���С��ǰ��
//			tmp = A[i];//tmp�ݴ�A[i]
//			for (j = i - 1; j >= 0 && A[j] > tmp; --j) {//���ǰ���������ź����Ԫ��
//				A[j + 1] = A[j];//���д���tmp������Ų
//			}
//			A[j + 1] = tmp;//���Ƶ�����λ��
//		}
//	}
//}
//ֱ�Ӳ��������۰�����Ż��棩
//void InsertSort(int A[], int n)
//{
//	int i, j, tmp;
//	int low, high, mid;
//	for (i = 1; i < n; i++) {//����Ԫ�ز������ź����������
//		if (A[i] < A[i - 1]) {//��A[i]�ؼ���С��ǰ��
//			tmp = A[i];//tmp�ݴ�A[i]
//			low = 0;
//			high = i - 1;
//			while (low <= high) {//�۰���ң�Ĭ�ϵ�������
//				mid = (low + high) / 2;
//				if (A[mid] <= tmp) {//�������Ӱ��
//					low = mid + 1;
//				}
//				else {
//					high = mid - 1;//�������Ӱ��
//				}
//			}
//			for (j = i - 1; j >= high + 1; --j) {//���ǰ���������ź����Ԫ��
//				A[j + 1] = A[j];//���д���tmp������Ų
//			}
//			A[low] = tmp;//���Ƶ�����λ��
//		}
//	}
//}
//ϣ������
//void ShellSort(int A[], int n)
//{
//	int i, j;
//	int d;
//	//A[0]ֻ���ݴ浥Ԫ�������ڱ�
//	for (d = n / 2; d >= 1; d = d / 2) {//�����仯
//		for (i = d + 1; i <= n; ++i) {
//			if (A[i] < A[i - d]) {//��A[i]��������������
//				A[0] = A[i];//�ݴ�
//				for (j = i - d; j > 0 && A[0] < A[j]; j -= d) {
//					A[j + d] = A[j];//����
//				}
//				A[j + d] = A[0];//����
//			}//if
//		}
//	}
//}
//ð������
//void swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void BubbleSort(int A[], int n)
//{
//	int i, j;
//	bool flag;//��ʾð�������Ƿ�������
//	for (i = 0; i < n; i++) {
//		flag = false;
//		for (j = n - 1; j > i; j--) {//һ��ð�ݹ���
//			if (A[j - 1] > A[j]) {//��Ϊ����
//				swap(&A[j - 1], &A[j]);//����
//				flag = true;
//			}
//		}
//		if (flag == false) {
//			return;//���˱�����û�з���������˵���������
//		}
//	}
//}
void print(int A[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}
//���Բ�������
//void test1()
//{
//	int A[10] = { 1,2,5,9,3,4,77,88,99,15 };
//	InsertSort(A, 10);
//	print(A, 10);
//}
//����ϣ������
//void test2()
//{
//	int A[10] = { 0,17,28,56,44,13,27,88,13 };
//	ShellSort(A, 8);
//	print(A, 8);
//}
//����ð������
//void test3()
//{
//	int A[10] = { 27,36,54,12,17,89,99,15,74,33 };
//	BubbleSort(A, 10);
//	print(A, 10);
//}
int main()
{
	//test1();
	//test2();
	//test3();
	return 0;
}