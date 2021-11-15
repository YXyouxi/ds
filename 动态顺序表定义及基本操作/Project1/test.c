#define _CRT_SECURE_NO_WARNINGS 1
#define InitSize 10		//顺序表的初始长度（动态）

#include<stdio.h>
#include<stdlib.h>

//动态顺序表的定义
typedef struct
{
	int* data;	//指向动态分配数组的指针
	int MaxSize;//顺序表的最大容量
	int length; //顺序表的当前容量
}SeqList;

//动态顺序表的初始化
void InitList(SeqList* L)
{
	L->MaxSize = InitSize;
	L->length = 0;
	L->data = (int*)malloc(sizeof(int) * InitSize);//申请一片连续的空间
}

//动态顺序表的增加长度
void IncreaseList(SeqList* L, int len)
{
	int* p = L->data;
	L->data = (int*)malloc(sizeof(int) * (L->MaxSize + len));//增加len长度，开辟新区域
	//将数据复制到新区域
	for (int i = 0; i < L->length; i++) {
		L->data[i] = p[i];
	}
	L->MaxSize = L->MaxSize + len;//顺序表的最大长度增加len
	free(p);
	p = NULL;
}

//动态顺序表的按位查找（位序）
int GetElem(SeqList L, int i)
{
	return L.data[i - 1];//注意下标和位序的差别
}

//动态顺序表的按值查找，返回位序
int LocateElem(SeqList L, int e)
{
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;//下标为i，返回其位序i+1
	return 0;
}

int main()
{
	SeqList L;
	InitList(&L);
	IncreaseList(&L, 5);
	int ret = GetElem(L, 3);
	int cc = LocateElem(L, 3);
	return 0;
}