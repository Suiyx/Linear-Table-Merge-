// LinearTableMerge.cpp : 定义控制台应用程序的入口点。
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
		return 0;//初始化失败
	}
	else {
		return 1;//初始化成功
	}
}
//求表长
int ListLength(SqList L){
	return L.length;

}
//遍历
void TraveList(SqList &L){
	for (int i = 0; i < L.length; i++){
		printf("%d", L.elem[i]);
	}
	printf("\n");

}
//创建线性表
void CreateList(SqList &L){
	printf("请输入线性表的长度");
	int n;
	scanf("%d", &n);
	printf("请输入元素：\n");
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
		printf("线性表A初始化成功\n");
	}
	else{
		printf("线性表A初始化失败\n");
	}
	if (InitSqList(B)){
		printf("线性表B初始化成功\n");
	}
	else{
		printf("线性表B初始化失败\n");
	}

	CreateList(A);
	printf("表长：%d\n", A.length);
	TraveList(A);
	CreateList(B);
	printf("合并后的线性表:\n");
	Combine(A, B);
	TraveList(A);

	system("pause");

}

