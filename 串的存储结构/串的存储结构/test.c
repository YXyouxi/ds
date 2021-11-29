#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxLen 255
//顺序存储
typedef struct
{
	char ch[MaxLen];
	int length;
}SString;
//链式存储
//typedef struct StringNode
//{
//	char ch[4];
//	struct StringNode* next;
//}StringNode,*String;
//bool InitString(String* S)
//{
//	(*S) = (String)malloc(sizeof(StringNode));
//	if ((*S) == NULL) {
//		return false;
//	}
//	(*S)->next = NULL;
//	return true;
//}
bool SubString(SString* Sub, SString S, int pos, int len)
{
	if (pos + len - 1 > S.length) {
		return false;
	}
	for (int i = pos; i < pos+len; i++) {
		(*Sub).ch[i - pos + 1] = S.ch[i];
	}
	(*Sub).length = len;
	return true;
}
int StrCompare(SString S, SString T)
{
	for (int i = 0; i <= S.length && i <= T.length; i++) {
		if (S.ch[i] != T.ch[i]) {
			return S.ch[i] - T.ch[i];
		}
	}
	return S.length - T.length;
}
int StrLength(SString S)
{
	return S.length;
}
//int Index(SString S, SString T)
//{
//	int i = 0;
//	int n = StrLength(S);
//	int m = StrLength(T);
//	SString sub;
//	while (i <= n - m + 1) {
//		SubString(&sub, S, i, m);
//		if (StrCompare(sub, T) != 0) {
//			i++;
//		}
//		else {
//			return i;
//		}
//	}
//	return 0;
//}
int Index(SString S, SString T)
{
	int i = 0;//用来遍历S，每次匹配失败变为i-j+2
	int j = 0;//用来遍历T，每次失败变为1
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length) {
		return i - T.length;
	}
	else {
		return 0;
	}
}
int Index_KMP(SString S, SString T,int next[])
{
	int i = 1;//遍历S
	int j = 1;//遍历T
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j > T.length) {
		return i - T.length;
	}
	else {
		return 0;
	}
}
void print(SString S)
{
	for (int i = 1; i <= S.length; i++) {
		printf("%c ", S.ch[i]);
	}
	printf("\n");
}
int main()
{
	SString S;
	SString T;
	int next[7] = { 0 };
	for (int i = 1; i <= 15; i++) {
		scanf("%c", &S.ch[i]);
	}
	S.length = 15;
	for (int j = 0; j <= 6; j++) {
		scanf("%c", &T.ch[j]);
	}
	T.length = 6;
	for (int k = 1; k <= 6; k++) {
		scanf("%d", &next[k]);
	}
	print(S);
	print(T);
	//int s = Index(S, T);
	printf("%d", Index_KMP(S,T,next));
	//InitString(&S);
	return 0;
}

