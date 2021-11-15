#define _CRT_SECURE_NO_WARNINGS 1
#define InitSize 10		//˳���ĳ�ʼ���ȣ���̬��

#include<stdio.h>
#include<stdlib.h>

//��̬˳���Ķ���
typedef struct
{
	int* data;	//ָ��̬���������ָ��
	int MaxSize;//˳�����������
	int length; //˳���ĵ�ǰ����
}SeqList;

//��̬˳���ĳ�ʼ��
void InitList(SeqList* L)
{
	L->MaxSize = InitSize;
	L->length = 0;
	L->data = (int*)malloc(sizeof(int) * InitSize);//����һƬ�����Ŀռ�
}

//��̬˳�������ӳ���
void IncreaseList(SeqList* L, int len)
{
	int* p = L->data;
	L->data = (int*)malloc(sizeof(int) * (L->MaxSize + len));//����len���ȣ�����������
	//�����ݸ��Ƶ�������
	for (int i = 0; i < L->length; i++) {
		L->data[i] = p[i];
	}
	L->MaxSize = L->MaxSize + len;//˳������󳤶�����len
	free(p);
	p = NULL;
}

//��̬˳���İ�λ���ң�λ��
int GetElem(SeqList L, int i)
{
	return L.data[i - 1];//ע���±��λ��Ĳ��
}

//��̬˳���İ�ֵ���ң�����λ��
int LocateElem(SeqList L, int e)
{
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;//�±�Ϊi��������λ��i+1
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