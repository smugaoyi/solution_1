#include<iostream>
using namespace std;

// Last In First Out 的线性表，简称LIFO结构。
// 顺序栈只能在数组的尾部进行操作，链栈只能在链表的头部进行操作。

#define MAXSIZE 10
typedef struct {
	int data;
	//...
}SElemType;

typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

