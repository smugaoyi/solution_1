#include<iostream>
using namespace std;

// Last In First Out �����Ա����LIFO�ṹ��
// ˳��ջֻ���������β�����в�������ջֻ���������ͷ�����в�����

#define MAXSIZE 10
typedef struct {
	int data;
}SElemType;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
} SqStack;

/*
* ˳��ջ�ĳ�ʼ��
*/
int initStack(SqStack& S) {
	S.base = new SElemType[MAXSIZE];
	if (S.base == NULL) {
		return -1;
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;

	return 0;
}

/*
* ˳��ջ����ջ
*/
int push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize) {
		return -1;
	}
	*S.top = e;
	S.top++;

	return 0;
}

/*
* ˳��ջ�ĳ�ջ
*/
int pop(SqStack& S, SElemType& e) {
	if (S.top == S.base) {
		return -1;
	}
	S.top--;
	e = *S.top;

	return 0;
}

// 434