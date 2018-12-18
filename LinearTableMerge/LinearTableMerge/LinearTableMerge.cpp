// LinearTableMerge.cpp : �������̨Ӧ�ó������ڵ㡣
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <string>
using namespace std;
#include <iostream>
#define MAX 100

typedef struct{
	int *elem;
	int length;
}SqList;

int InitSqList(SqList &L){
	L.elem = new int[MAX];
	if (!L.elem){
		return 0;//��ʼ��ʧ��
	}
	else {
		return 1;//��ʼ���ɹ�
	}
}
//���
int ListLength(SqList L){
	return L.length;

}
//����
void TraveList(SqList &L){
	for (int i = 0; i < L.length; i++){
		printf("%d", L.elem[i]);
	}
	printf("\n");

}
//�������Ա�
void CreateList(SqList &L){
	printf("���������Ա�ĳ���");
	int n;
	scanf("%d", &n);
	printf("������Ԫ�أ�\n");
	int e;
	for (int i = 0; i < n; i++){
		scanf("%d", &e);
		L.elem[i] = e;
		L.length = i + 1;
	}

}

void Combine(SqList &A, SqList &B){
	for (int i = 0; i < B.length; i++){
		int count = 0;
		for (int j = 0; j < A.length; j++){
			if (A.elem[j] == B.elem[i]){
				count += 1;
			}
		}
		if (count == 0){
			A.elem[A.length++] = B.elem[i];
		}

	}
}

int main(){
	SqList A, B;
	if (InitSqList(A)){
		printf("���Ա�A��ʼ���ɹ�\n");
	}
	else{
		printf("���Ա�A��ʼ��ʧ��\n");
	}
	if (InitSqList(B)){
		printf("���Ա�B��ʼ���ɹ�\n");
	}
	else{
		printf("���Ա�B��ʼ��ʧ��\n");
	}

	CreateList(A);
	printf("����%d\n", A.length);
	TraveList(A);
	CreateList(B);
	printf("�ϲ�������Ա�:\n");
	Combine(A, B);
	TraveList(A);

	system("pause");

}

