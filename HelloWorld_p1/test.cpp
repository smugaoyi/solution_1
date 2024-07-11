#include<iostream>
using namespace std;

/*
* 定义ElemType为结构体类型
*/
typedef struct {
	string name;
	int age;
	int score;
} ElemType;

/*
* 类型定义
*/
typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}Lnode, * LinkList;


LinkList L;

/* 
* 1、初始化单链表，带有头结点
*/
int initList_L(LinkList& L) {
	// 生成新的结点作为头结点，并用头指针指向头结点
	L = new Lnode;
	// 将头结点的指针域置空
	L->next = NULL;

	return 0;
}

/*
* 2、判断链表是否空链表
*/
int isEmptyList(LinkList L) {
	if (L->next) {
		return 0;
	}
	else {
		return 1;
	}
}

/*
* 3、销毁单链表
*/
int destroyList(LinkList& L) {
	// 指向要销毁的结点
	Lnode* p;

	while (L != NULL)
	{
		p = L;
		L = L->next;
		delete p;

	}
	return 0;
}


int main() {

	initList_L(L);

	int flag = isEmptyList(L);

	if (flag == 0) {
		std::cout << "链表非空";
	}
	else
	{
		std::cout << "链表为空";
	}


}

