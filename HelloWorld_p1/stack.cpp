#include<iostream>
using namespace std;

// Last In First Out �����Ա����LIFO�ṹ��

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