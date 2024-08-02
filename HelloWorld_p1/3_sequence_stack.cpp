#include<iostream>
using namespace std;

// Last In First Out 的线性表，简称LIFO结构。
// 顺序栈只能在数组的尾部进行操作，链栈只能在链表的头部进行操作。

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
* 顺序栈的初始化
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
* 顺序栈的入栈
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
* 顺序栈的出栈
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