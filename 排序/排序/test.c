#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
//直接插入排序
//void InsertSort(int A[], int n)
//{
//	int i, j, tmp;
//	for (i = 1; i < n; i++) {//将各元素插入已排好序的序列中
//		if (A[i] < A[i - 1]){//若A[i]关键字小于前驱
//			tmp = A[i];//tmp暂存A[i]
//			for (j = i - 1; j >= 0 && A[j] > tmp; --j) {//检查前面所有已排好序的元素
//				A[j + 1] = A[j];//所有大于tmp的往后挪
//			}
//			A[j + 1] = tmp;//复制到插入位置
//		}
//	}
//}
//直接插入排序（折半查找优化版）
//void InsertSort(int A[], int n)
//{
//	int i, j, tmp;
//	int low, high, mid;
//	for (i = 1; i < n; i++) {//将各元素插入已排好序的序列中
//		if (A[i] < A[i - 1]) {//若A[i]关键字小于前驱
//			tmp = A[i];//tmp暂存A[i]
//			low = 0;
//			high = i - 1;
//			while (low <= high) {//折半查找，默认递增有序
//				mid = (low + high) / 2;
//				if (A[mid] <= tmp) {//查找右子半表
//					low = mid + 1;
//				}
//				else {
//					high = mid - 1;//查找左子半表
//				}
//			}
//			for (j = i - 1; j >= high + 1; --j) {//检查前面所有已排好序的元素
//				A[j + 1] = A[j];//所有大于tmp的往后挪
//			}
//			A[low] = tmp;//复制到插入位置
//		}
//	}
//}
//希尔排序
//void ShellSort(int A[], int n)
//{
//	int i, j;
//	int d;
//	//A[0]只是暂存单元，不是哨兵
//	for (d = n / 2; d >= 1; d = d / 2) {//步长变化
//		for (i = d + 1; i <= n; ++i) {
//			if (A[i] < A[i - d]) {//将A[i]插入有序增量表
//				A[0] = A[i];//暂存
//				for (j = i - d; j > 0 && A[0] < A[j]; j -= d) {
//					A[j + d] = A[j];//后移
//				}
//				A[j + d] = A[0];//插入
//			}//if
//		}
//	}
//}
//冒泡排序
//void swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void BubbleSort(int A[], int n)
//{
//	int i, j;
//	bool flag;//表示冒泡排序是否发生交换
//	for (i = 0; i < n; i++) {
//		flag = false;
//		for (j = n - 1; j > i; j--) {//一趟冒泡过程
//			if (A[j - 1] > A[j]) {//若为逆序
//				swap(&A[j - 1], &A[j]);//交换
//				flag = true;
//			}
//		}
//		if (flag == false) {
//			return;//本趟遍历后没有发生交换，说明排序完毕
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
//测试插入排序
//void test1()
//{
//	int A[10] = { 1,2,5,9,3,4,77,88,99,15 };
//	InsertSort(A, 10);
//	print(A, 10);
//}
//测试希尔排序
//void test2()
//{
//	int A[10] = { 0,17,28,56,44,13,27,88,13 };
//	ShellSort(A, 8);
//	print(A, 8);
//}
//测试冒泡排序
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