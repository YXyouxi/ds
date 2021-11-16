#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct LNode	//���嵥����������
{
	int data;			//ÿ���ڵ���һ������Ԫ��
	struct LNode* next;	//ָ��ָ����һ�����
}LNode,*LinkList;

//��ʼ��һ����������ͷ��㣩
bool InitList(LinkList* L)
{
	*L = (LNode*)malloc(sizeof(LNode));//����һ��ͷ���
	if (*L == NULL)						  //�ڴ治�㣬����ʧ��
		return false;
	(*L)->next = NULL;					  //ͷ���֮����ʱ��û�н��
	return true;
}

//��λ���ң����ص�i�����
LNode* GetElem(LinkList* L, int i)
{
	if (i < 0)
		return NULL;
	LNode* p;	//pָ��ǰɨ�赽�Ľ��
	int j = 0;	//j��¼��ǰָ��ڼ������
	p = *L;		//pָ��ͷ���
	while (p != NULL || j < i ) {	//�ҵ���i�����
		p = p->next;
		j++;
	}
	return p;
}

//��ֵ���ң��ҵ����������e�Ľ��
LNode* LocateElem(LinkList* L, int e)
{
	LNode* p = (*L)->next;//�ӵ�һ���ڵ㿪ʼ����
	while (p != NULL && p->data != e) 
		p = p->next;
	return p;//�ҵ��󷵻ظ�ָ�룬���򷵻�NULL
}

//��������
int length(LinkList* L)
{
	int len = 0;
	LNode* p = *L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

//����������p�ڵ�֮�����Ԫ��e
bool InsertNextNode(LNode* p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)//�ڴ����ʧ��
		return false;
	s->data = e;	//��������e
	s->next = p->next;
	p->next = s;	//���ڵ�s����p֮��
	return true;
}

//ǰ���������p�ڵ�֮ǰ����Ԫ��e����Ϊ�޷��ҵ�ǰ����㣨��ͷָ����ʱ�临�Ӷ�̫�ߣ�������ֱ�Ӻ�壬Ȼ�������
bool InsertPriorNode(LNode* p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->next = p->next;
	p->next = s;		//�½ڵ�s����p֮��
	s->data = p->data;	//p��Ԫ�ظ��Ƶ�s��
	p->data = e;		//p��Ԫ�ظ���Ϊe
	return true;
}

//ɾ����������λ��ɾ����ɾ����i��λ�õĽ�㣬����ɾ�������ݴ�����
bool ListDelete(LinkList* L, int i, int* e)
{
	if (i < 1)
		return false;
	//LNode* p;
	//int j = 0;//��¼��ǰָ��ڼ������
	//LNode* p = L;//ָ��ͷ���
	//while (p != NULL || j < i - 1) {	//ѭ���ҵ���i-1�����
	//	p = p->next;
	//	j++;
	//}
	
	//���˰�λ���Һ�������ֱ�ӵ��ú���
	LNode* p = GetElem(L, i - 1);

	if (p == NULL)	//iֵ���Ϸ�
		return false;
	if (p->next == NULL)//p֮���Ѿ��޽��
		return false;
	LNode* q = p->next;//��qָ��ɾ���Ľ��
	*e = q->data;		//��e���ر�ɾ����Ԫ��
	p->next = q->next;	//��*q���������жϿ�������p����nextָ��ָ��ԭ���ĵ�i+1�����
	free(q);			//�ͷŽ��Ĵ洢�ռ�
	q = NULL;
	return true;
}

//ɾ��ָ���Ľ��p(ͬǰ�����˼�룬͵�컻��)
bool DeleteNode(LNode* p)
{
	if (p == NULL)
		return false;
	LNode* q = p->next;	//��qָ��p�ĺ�̽��
	p->data = q->data;	//�ͺ�̽�㽻��������
	p->next = q->next;	//��q���Ͽ�������p����nextָ��ԭ��p+1����λ�ã�
	free(q);			//�ͷ�q���ڴ�
	q = NULL;
	return true;
	//������δ�����bug����Ҫɾ���Ľ�������һ��ʱ��q�ͻ�ָ��һ����ָ�룬
	//��ô�ڽ����������ʱ��ͻ���ֶԿ�ָ��Ĳ�����������ʵֻ���ôӱ�ͷ��ʼ����Ѱ��p��ǰ�����ķ���
}

//��ͷ���ĵ���������ݲ���,�ڵ�i��λ�ò���Ԫ��e
bool ListInsert(LinkList* L, int i, int e)
{
	if (i < 1)
		return false;
	//LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
	//p = *L;//Lָ��ͷ���
	//int j = 0;//��ǰpָ��ָ��ڼ������
	//while (p != NULL && j < i - 1) {	//ѭ���ҵ���i-1����㣨��ΪҪ�����i����������ǰһ����
	//	p = p->next;
	//	j++;
	//}
	//���˰�λ���Һ�������ֱ�ӵ��ú���

	LNode* p = GetElem(L, i - 1);//�ҵ���i-1�����

	//if (p == NULL)	//iֵ���Ϸ�
	//	return false;
	//LNode* s = (LNode*)malloc(sizeof(LNode));
	//s->data = e;
	//s->next = p->next;
	//p->next = s;//�����s����p֮��
	//return true;
	return InsertNextNode(p, e);//���˺�����֮�����ֱ���ú������Ͳ����ϱߵ�һ��������
}

int main()
{
	LinkList L;		//����һ��ָ�������ָ��
	InitList(&L);	//��ʼ��һ���ձ�
	ListInsert(&L, 2, 3);	//��λ��Ϊ2��λ�ò��� Ԫ��3
}