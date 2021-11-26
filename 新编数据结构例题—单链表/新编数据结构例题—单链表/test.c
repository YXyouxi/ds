#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;
bool InitList(LinkList* L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if ((*L) == NULL)
		return false;
	(*L)->next = NULL;
	return true;
}
//β�巨
bool InsertNextList(LinkList* L)
{
	int x = 0;
	LNode* s, * r = *L;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		if (s == NULL) {
			return false;
		}
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return true;
}
//��ӡ
void print(LinkList L)
{
	LNode* p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//����2-3-24�����һ���㷨ɾ��������L�е�һ��ֵΪx�Ľ��
//�⣺
//bool DelFirst(LinkList* L, int x)
//{
//	if ((*L)->next == NULL) {
//		return false;
//	}
//	LNode* p = (*L);//p��Ҫɾ���Ľ���ǰ�����
//	while (p->next!=NULL&&p->next->data != x) {
//		p = p->next;//�ҵ�p->next->data==x�Ľ��
//	}
//	if (p->next == NULL) {//�Ҳ���
//		return false;
//	}
//	else {//ɾ��
//		LNode* r = p->next;
//		p->next = r->next;
//		free(r);
//		r = NULL;
//	}
//	return true;
//}
//����2-3-25�����һ���㷨ɾ��������L�����������������ϵ����ݽ�㣩�е�һ��ֵΪx�Ľ���ǰ�����
//��:
//bool DelFirst(LinkList* L, int x)
//{
//	LNode* prepre = *L;//ָ��ֵΪx�Ľ���ǰ������ǰ�����
//	LNode* pre=(*L)->next;//ָ��ֵΪx�Ľ���ǰ�����
//	LNode* p=pre->next;//���ڲ���ֵΪx�Ľ��
//	if (pre->data == x) {//��һ��ֵ����x,����ɾ��ͷ���
//		return false;
//	}
//	while (p->data != x && p != NULL) {//����ֵΪx�Ľ��
//		prepre = pre;
//		pre = p;
//		p = p->next;//prepre��pre��pͬ�������
//	}
//	if (p == NULL) {//�Ҳ���
//		return false;
//	}
//	prepre->next = p;
//	free(pre);
//	pre = NULL;
//	return true;
//}
//����2-3-26�����һ���㷨�ж�������L�Ƿ��ǵ��������
//�⣺
//bool isIncrease(LinkList L)
//{
//	if (L->next == NULL) {
//		return false;
//	}
//	LNode* pre = L->next;//p����ǰ�����
//	LNode* p = pre->next;//�ȽϺ�ǰ��������ݵĴ�С
//	while (p != NULL) {
//		if (p->data >= pre->data) {//��������������
//			pre = p;
//			p = p->next;
//		}
//		else {
//			return false;
//		}
//	}
//		return true;
//}
//����2-3-27�����һ���ڴ�ͷ���ĵ�����L��ɾ����һ����Сֵ�����㷨(û��˵����������int)
//�⣺
//bool DelMin(LinkList* L)
//{
//	if ((*L)->next == NULL) {
//		return false;
//	}
//	LNode* pre = *L;//ָ����ҵĽ���ǰ�����
//	LNode* p = pre->next;//���ڲ�����Сֵ���
//	LNode* minpre = pre;//ָ����Сֵ����ǰ�����
//	LNode* minp = p;//������Сֵ�Ľ���ָ��
//	while (p != NULL) {
//		if (p->data < minp->data) {
//			minp = p;//����С�Ľڵ�p����minp��
//			minpre = pre;//����С�Ľ���ǰ�����pre����minpre��
//		}
//		pre = p;
//		p = p->next;
//	}
//	minpre->next = minp->next;
//	free(minp);
//	minp = NULL;
//	return true;
//}
//����2-3-28�����һ���㷨ɾ�����ͷ���LΪ��ͷָ��ĵ���������н��
//�⣺
//bool DelLink(LinkList* L)
//{
//	if ((*L)->next == NULL) {
//		return false;
//	}
//	LNode* pre = *L;//ָ��p����ǰ�����
//	LNode* p = pre->next;//ָ�����ڱ����Ľ��
//	while (p != NULL) {
//		free(pre);
//		pre = p;
//		p = p->next;
//	}
//	free(pre);//��pָ��NULLʱ��preָ��β��㣬����ɾ��һ��
//	pre = NULL;
//	return true;
//}
//����2-3-29����һ�����Ա�(a1��a2,...an)��n>=2�����ô�ͷ���ĵ�����L�洢�����һ���㷨����͵����ã���ν���͵ء���ָ�����ռ�ΪO(1)
//�⣺
//bool Reverse(LinkList* L)
//{
//	if ((*L)->next == NULL) {
//		return false;
//	}
//	LNode* p = (*L)->next;//p�ӵڶ�����㿪ʼͷ��
//	LNode* q = p;//������ʱ����p֮��Ľ��
//	(*L)->next = NULL;//����LΪ�ձ�Ȼ����p����������ͷ��
//	while (p != NULL) {
//		q = p->next;//��q��ʱ����p�ĺ�̽��
//		p->next = (*L)->next;//��p����L���ײ�
//		(*L)->next = p;
//		p = q;//p����ȥ����ʣ�µĽ��
//	}
//	return true;
//}
//����2-3-30����һ������Ԫ�ؽ����ĵ�����A�����һ���㷨��������Ϊ����������A��B
//A�������к�������ż����㣬B�������к�������������㣬�ұ���ԭ������Դ���
//�⣺
bool SplitLink(LinkList* A, LinkList* B)
{
	if ((*A)->next == NULL) {
		return false;
	}
	LNode* p = (*A)->next;//��������
	LNode* ra = *A;//A��β���
	LNode* rb = *B;//B��β���
	while (p != NULL) {
		if (p->data % 2 == 0) {//ż�����
			ra->next = p;//��p���뵽A�ı�β
			ra = p;
			p = p->next;//p����
		}
		else {
			rb->next = p;//��p���뵽B�ı�β
			rb = p;
			p = p->next;
		}
	}
	ra->next = rb->next = NULL;
	return true;
}
void test1()
{
	LinkList A;
	LinkList B;
	InitList(&A);
	InitList(&B);
	InsertNextList(&A);
	print(A);
	//DelFirst(&L, 8);
	//isIncrease(L);
	//DelMin(&L);
	//DelLink(&L);
	//Reverse(&L);
	SplitLink(&A, &B);
	print(A);
	print(B);
}
int main()
{
	test1();
	return 0;
}