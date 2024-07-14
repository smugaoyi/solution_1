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
* 头指针和头结点也被销毁
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

/*
* 4、清空链表
* 头指针和头结点依然存在
* 头结点的指针域为NULL
* 
*/
int clearList(LinkList& L) {

	Lnode* p, * q;
	// 初始时，p指针指向首元结点
	p = L->next;

	while (p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return 0;
}

/*
* 5、求链表的长度
*/
int lenList(LinkList& L) {
	int i = 0;

	Lnode* p;
	p = L->next;

	while (p !=NULL) {
		p = p->next;
		i++;
	}
	return i;
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
	
	// test


}

