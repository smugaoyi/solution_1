#include<iostream>
using namespace std;

// Last In First Out 的线性表，简称LIFO结构。

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