#include<iostream>
using namespace std;

// 单链表的基本操作：
// 包括：单链表的销毁、清空单链表、求单链表的长度、判断链表是否为空、查找、插入、删除等

// 单链表的查找、插入、删除算法的时间效率分析
// 查找：时间复杂度O(n)
// 插入和删除：不需要移动元素，时间复杂度O(1),但是寻找第i个插入位置或删除位置需要O(n)


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

/*
* 6、取单链表的第i个元素的内容
*/
int getElem(LinkList L, int i ,ElemType &e) {

	// 计数器的初始值为1
	int j = 1;

	Lnode* p;
	// 从首元结点开始
	p = L->next;

	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	
	if (p == NULL || j > i) {
	
		// 找到最后也没有找到，或者i的值小于j
		return -1;
	}

	// j == i，找到了
	e = p->data;

	return 0;
}

/*
* 7、查找值为e的元素的的地址
*/
Lnode* locateElem(LinkList L, int e) {

	Lnode* p;
	p = L->next;
	// 此处使用年龄age作为例子
	while (p != NULL && p->data.age != e) {
		p = p->next;
	}

	return p;
}

/*
* 8、在第i个元素之前插入一个新节点
* 此处L使用引用类型，插入一个新元素后，L变长，使用L返回
*/
int insertE(LinkList &L, int i, ElemType e) {

	Lnode* p;
	p = L;

	int j = 0;
	// 循环结束，p指针指向第i-1个节点
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}

	// i大于表长+1或者小于1，插入位置非法
	if (p == NULL || j > i - 1) {
		return -1;
	}

	Lnode* s = new Lnode;
	s->data = e;
	s->next = p->next;
	p->next = s;

	return 0;
}

/*
* 9、删除第i个节点
*/
int deleteE(LinkList& L, int i) {

	Lnode* p,*q;
	p = L;

	int j = 0;

	// 循环结束，p指针指向第i-1个节点
	while (p->next != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}

	if (p->next == NULL || j > i - 1) {
		return -1;
	}

	// 保存第i个元素的地址，后面的语句执行完后，p->next的值就变了
	q = p->next;

	// 等价于p->next = q->next;
	p->next = p->next->next;
	delete q;

	return 0;
}

/*
* 线性表的合并
*/
int union_list(LinkList& La, LinkList Lb) {
	int la_Len = lenList(La);
	int lb_Len = lenList(Lb);

	for (int i = 1; i <= lb_Len; i++) {
	
		ElemType e;
		getElem(Lb, i, e);

		// 在La中找e
		Lnode * p = locateElem(La, e.age);
		if (p == NULL) {
			// 在La尾部插入
		}

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
	
	// test


}

