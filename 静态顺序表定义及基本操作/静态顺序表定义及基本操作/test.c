#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 10	//定义最大长度（静态）

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//静态
typedef struct
{
	int data[MaxSize];//用静态的“数组”存放数据元素
	int length;//数据表的当前长度
}SqList;

//静态顺序表的初始化
void InitList(SqList* L)
{
	L->length = 0;
}

//静态顺序表的插入操作
bool IncreaseList(SqList* L,int i,int e)//在L的位序i处插入元素e
{
	if (i<1 || i>L->length + 1)//判断i的范围是否合法
		return false;
	if (L->length >= MaxSize)//判断顺序表是否已满
		return false;
	for (int j = L->length; j >=i; j--)
		L->data[j] = L->data[j - 1];//将第i个元素及之后的元素后移
	L->data[i - 1] = e;//将下标为i-1（位序为i）的位置替换为e
	L->length++;//长度加1
	return true;
}

//静态顺序表的删除操作
bool ListDelete(SqList* L, int i, int* e)//将位序为i的元素删除
{
	if (i<1 || i>L->length)//判断i的合法性
		return false;
	*e = L->data[i - 1];//记录删除的元素
	for (int j = i; j < L->length; j++) //将位序为i的元素及之后的元素前移
		L->data[j - 1] = L->data[j];
	L->length--;//长度减1
	return true;
}

//静态顺序表的按位查找（位序）
int GetElem(SqList L, int i)
{
	return L.data[i - 1];//注意位序和下标的差别
}

//静态顺序表的按值查找，返回位序
int LocateElem(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;//下标为i，返回其位序i+1
	return 0;
}

int main()
{
	SqList L;
	InitList(&L);
	IncreaseList(&L,3,3);
	int e = -1;//用变量e把删除的元素“带回来”
	if (ListDelete(&L, 3, &e))
		printf("已删除第3个元素，删除元素值=%d\n", e);
	else
		printf("位序i不合法，删除失败");
	int ret = GetElem(L, 3);
	int cc = LocateElem(L, 3);
	return 0;
}
