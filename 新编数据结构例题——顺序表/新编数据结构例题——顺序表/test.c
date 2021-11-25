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
//例题2-2-18：已知一个顺序表L，其中的元素递增排列，插入一个x后仍保持递增排列
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
//例题2-2-19：设计一个高效算法，将顺序表的所有元素逆置，要求空间复杂度O（1）
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
//例题2-2-20：设计一个高效算法，从顺序表中删除所有元素值为x的元素，要求时间复杂度O（n），空间复杂度O（1）
//解法1：
// 遍历顺序表L，若遇到值为x，k+1，下一次遇到不为x时，将这个元素前移k个位置
//bool Delete(SqList* L, int x)
//{
//	if (L->length == 0)
//		return false;
//	int i = 0;
//	int k = 0;//记录遇到了几个x
//	for (i = 0; i < L->length; i++) {
//		if (L->data[i] == x)//i指向为x的元素
//			k++;
//		else 
//			L->data[i - k] = L->data[i];//不为x的元素前移k个位置
//	}
//	L->length = L->length - k;//表长减少k
//	return true;
//}
//解法二
//k表示新表中L的元素个数，遍历L，若不等于x，则存放在data[k]中，k+1，等于x则跳过
//bool Delete(SqList* L, int x)
//{
//	if (L->length == 0)
//		return false;
//	int i = 0;
//	int k = 0;//表示新表中元素个数
//	for (i = 0; i < L->length; i++) {
//		if (L->data[i] != x) {
//			L->data[k] = L->data[i];
//			k++;
//		}
//	}
//	L->length = k;
//	return true;
//}
//解法三：将L看成数组a=(a0,a1,...an-1)将其中值不为x的元素划分为一个i区间，元素个数为i+1，初始i-1，
//将其中值为x的元素划分为一个j区间，即a[i+1,j-1]，初始也为空，即j=0，遍历L
//若为x，跳过，直接执行j+1，若不为x，存到i区间，i++，交换i和j区间
//通俗解释：当前几个不是x的时候直接跳过了，遇到第一个是x的元素的时候，用i记录了位置，j继续往后走，再次遇到不是x的元素
//然后将这个元素和i调换位置
//bool Delete(SqList* L, int x)
//{
//	if (L->length == 0)
//		return false;
//	int i = -1;
//	int j = 0;
//	while (j < L->length) {
//		if (L->data[j] != x) {//找到不为x的元素
//			i++;//扩大不为x的区间长度
//			if (i != j) {//将a[j]交换到不为x的区间的末尾
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
//例题2-2-21：从一给定的顺序表L中删除元素值在x到y（x<=y)的所有元素，要求时间复杂度为O(n)，空间复杂度为O(1)
//解法一：对应上一题解法一，只是判断条件改变
//bool Delete(SqList* L, int x, int y)
//{
//	if(x>y)
//		return false;
//	if (L->length == 0)
//		return false;
//	int i = 0;
//	int k = 0;//统计在x-y范围内的元素个数
//	for (i = 0; i < L->length; i++) {
//		if (L->data[i] >= x && L->data[i] <= y)
//			k++;
//		else
//			L->data[i - k] = L->data[i];
//	}
//	L->length = L->length - k;
//	return true;
//}
//解法二：对应上一题解法二
//bool Delete(SqList* L, int x, int y)
//{
//	if(x>y)
//		return false;
//	if (L->length == 0)
//		return false;
//	int i = 0;
//	int k = 0;//记录不属于x-y的元素的个数
//	for (i = 0; i < L->length; i++) {
//		if (L->data[i]<x || L->data[i]>y) {
//			L->data[k] = L->data[i];
//			k++;
//		}
//	}
//	L->length = k;
//	return true;
//}
//解法三：对应上一题解法三
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
//	int i = -1;//表示符合要求的区间长度
//	int j = 0;//用来遍历
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
//例题2-2-22：给定一个增序的整数顺序表L，从中删除元素值在x到y（x<=y)的所有元素，要求时间复杂度为O(n),空间复杂度为O(1)
//解：
//bool Delete(SqList* L, int x, int y)
//{
//	if (L->length == 0)
//		return false;
//	if (x > y)
//		return false;
//	int i = 0;//记录第一个大于等于x的位置
//	int j = 0;//记录第一个大于y的位置
//	int k = 0;//用于遍历
//	while (i < L->length && L->data[i] < x)//查找第一个大于等于x的元素的位置
//		i++;
//	if (i >= L->length)//所有的元素都比x小
//		return false;
//	j = i;
//	while (j < L->length && L->data[j] <= y)//查找第一个大于y的元素的位置
//		j++;
//	while (j < L->length)
//		L->data[i++] = L->data[j++];
//	L->length = i + 1;
//	return true;
//}
//例题2-2-23：有一个顺序表L，其元素为整型，设计一个算法将L中所有小于0的整数部分放在前半部分，大于或等于0的整数放在后半部分
//解法一：参考2-2-20解法三，分为正数区间和负数区间，负数区间用i表示长度
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
//	int i = -1;//用于记录出现正数的位置
//	int j = 0;//用于遍历
//	while (j < L->length) {
//		if (L->data[j] < 0) {
//			i++;
//			if (i != j) {//说明两个负数之间有正数
//				swap(&(L->data[i]), &(L->data[j]));//在负数区间尾部将正负数交换
//			}
//		}
//		j++;
//	}
//	return true;
//}
//解法二：从L的两端查找，前端找大于等于0的元素（位置为i），后端找小于0的元素（位置为j），找到后将这两位置的元素交换
//bool move(SqList* L)
//{
//	if (L->length == 0) {
//		return false;
//	}
//	int i = 0;//从头找
//	int j = L->length - 1;//从后找
//	while (i < j) {
//		while (i < j && L->data[i] < 0) {
//			i++;//从前向后找大于等于0的元素位置
//		}
//		while (i < j && L->data[j] >= 0) {
//			j--;//从后往前找小于0的元素的位置
//		}
//		if (i < j) {//交换
//			int tmp = L->data[i];
//			L->data[i] = L->data[j];
//			L->data[j] = tmp;
//		}
//	}
//	return true;
//}
//例题2-2-25：设计一个算法从有序顺序表中删除重复的元素，并使剩余元素间的相对次序保持不变
//解：用i从1开始遍历，设L->data[0....j]中没有重复元素，扫描元素时若L->data[i]和j中每个元素都不相同则添加到尾部
//bool DelSame(SqList* L, int x)
//{
//	if (L->length == 0)
//		return false;
//	int i = 1, j = 0, k = 0;
//	for (i = 1; i < L->length; i++) {
//		k = 0;
//		while (k <= j && L->data[i] != L->data[k]) {
//			k++;//遍历到j的元素
//		}
//		if (k > j) {//说明没有和j中元素相同的
//			j++;//j区间长度加一
//			L->data[j] = L->data[i];
//		}
//	}
//	L->length = j + 1;
//	return true;
//}
//例题2-2-25：设计一个算法从有序顺序表中删除重复的元素，并使剩余元素间的相对次序保持不变
//解：
//bool DelSame(SqList* L, int x)
//{
//	if (L->length == 0) {
//		return false;
//	}
//	int i = 1, j = 0;//j用来保存不重复的元素个数
//	for (i = 1; i < L->length; i++) {
//		if (L->data[i] != L->data[j]) {//每次只需要比较最后一个元素和新查找的元素是否相同
//			j++;//不相同则数量增加1
//			L->data[j] = L->data[i];
//		}
//	}
//	L->length = j + 1;
//	return true;
//}
//例题2-2-26：用顺序表表示集合，设计一个算法实现两个集合的求交集运算
//解：
//bool Intersection(SqList A, SqList B, SqList* L)
//{
//	if (A.length == 0 || B.length == 0) {
//		return false;
//	}
//	int i = 0;//用于遍历A
//	int j = 0;//用于遍历B
//	int k = 0;//记录L中元素个数
//	for (i = 0; i < A.length; i++) {
//		j = 0;
//		while (j<B.length&&A.data[i] != B.data[j]) {
//			j++;
//		}
//		if (j < B.length) {//表示A.data[i]在B中有相同元素，将其放到L中
//			L->data[k] = A.data[i];
//			k++;
//		}
//	}
//	L->length = k;//修改长度
//	return true;
//}
//例题2-2-27：假设表示集合的顺序表是一个有序顺序表，设计一个高效算法实现两个集合的求交集运算
//bool Intersection(SqList A, SqList B, SqList* L)
//{
//	if (A.length == 0 || B.length == 0) {
//		return false;
//	}
//	int i = 0;//遍历A
//	int j = 0;//遍历B
//	int k = 0;//记录L中元素个数
//	while (i < A.length && j < B.length) {
//		if (A.data[i] == B.data[j]) {//AB元素相同，放入L，ijk分别加一
//			L->data[k] = A.data[i];
//			i++;
//			j++;
//			k++;
//		}
//		else if (A.data[i] < B.data[j]) {
//			i++;//A向后找
//		}
//		else {
//			j++;//B向后找
//		}
//	}
//	L->length = k;
//}
//例题2-2-28：用顺序表表示集合，设计一个算法实现两个集合的求并集运算
//bool Union(SqList A, SqList B, SqList* L)
//{
//	if (A.length == 0 || B.length == 0) {
//		return false;
//	}
//	int i = 0;//遍历A，存入L
//	for (i = 0; i < A.length; i++) {
//		L->data[i] = A.data[i];//将A中元素复制到L中
//	}
//	int j = 0;//遍历B，找和L中不一样的存入L
//	int k = A.length;//L中有几个元素
//	for (i = 0; i < B.length; i++) {//遍历B
//		j = 0;
//		while (j < A.length && A.data[j] != B.data[i]) {
//			j++;
//		}
//		if (j == A.length) {//表示B.data[i]不在A中，将其放到L中
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