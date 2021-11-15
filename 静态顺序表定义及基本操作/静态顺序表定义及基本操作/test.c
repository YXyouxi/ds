#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 10	//������󳤶ȣ���̬��

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//��̬
typedef struct
{
	int data[MaxSize];//�þ�̬�ġ����顱�������Ԫ��
	int length;//���ݱ�ĵ�ǰ����
}SqList;

//��̬˳���ĳ�ʼ��
void InitList(SqList* L)
{
	L->length = 0;
}

//��̬˳���Ĳ������
bool IncreaseList(SqList* L,int i,int e)//��L��λ��i������Ԫ��e
{
	if (i<1 || i>L->length + 1)//�ж�i�ķ�Χ�Ƿ�Ϸ�
		return false;
	if (L->length >= MaxSize)//�ж�˳����Ƿ�����
		return false;
	for (int j = L->length; j >=i; j--)
		L->data[j] = L->data[j - 1];//����i��Ԫ�ؼ�֮���Ԫ�غ���
	L->data[i - 1] = e;//���±�Ϊi-1��λ��Ϊi����λ���滻Ϊe
	L->length++;//���ȼ�1
	return true;
}

//��̬˳����ɾ������
bool ListDelete(SqList* L, int i, int* e)//��λ��Ϊi��Ԫ��ɾ��
{
	if (i<1 || i>L->length)//�ж�i�ĺϷ���
		return false;
	*e = L->data[i - 1];//��¼ɾ����Ԫ��
	for (int j = i; j < L->length; j++) //��λ��Ϊi��Ԫ�ؼ�֮���Ԫ��ǰ��
		L->data[j - 1] = L->data[j];
	L->length--;//���ȼ�1
	return true;
}

//��̬˳���İ�λ���ң�λ��
int GetElem(SqList L, int i)
{
	return L.data[i - 1];//ע��λ����±�Ĳ��
}

//��̬˳���İ�ֵ���ң�����λ��
int LocateElem(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;//�±�Ϊi��������λ��i+1
	return 0;
}

int main()
{
	SqList L;
	InitList(&L);
	IncreaseList(&L,3,3);
	int e = -1;//�ñ���e��ɾ����Ԫ�ء���������
	if (ListDelete(&L, 3, &e))
		printf("��ɾ����3��Ԫ�أ�ɾ��Ԫ��ֵ=%d\n", e);
	else
		printf("λ��i���Ϸ���ɾ��ʧ��");
	int ret = GetElem(L, 3);
	int cc = LocateElem(L, 3);
	return 0;
}
