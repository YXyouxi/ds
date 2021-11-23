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
//已知一个顺序表L，其中的元素递增排列，插入一个x后仍保持递增排列
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
//设计一个高效算法，将顺序表的所有元素逆置，要求空间复杂度O（1）
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
//设计一个高效算法，从顺序表中删除所有元素值为x的元素，要求时间复杂度O（n），空间复杂度O（1）
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
bool Delete(SqList* L, int x)
{
	if (L->length == 0)
		return false;
	int i = -1;
	int j = 0;
	while (j < L->length) {
		if (L->data[j] != x) {//找到不为x的元素
			i++;//扩大不为x的区间长度
			if (i != j) {//将a[j]交换到不为x的区间的末尾
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