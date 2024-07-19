#include<iostream>
using namespace std;

// 不念过去，不畏将来

/*
* 定义ElemType为结构体类型
*/
typedef struct {
	string name;
	int age;
	int score;
} ElemType;

/*
* 双向链表的结构定义
*/
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode, * DuLinkList;

/*
* 双向链表的第i个结点前插入
*/
int insertDuL(DuLinkList& L, int i, ElemType e) {

	DuLNode* p;
	p = getElemP_Dul(L, i);
	if (p == NULL) {
		return -1;
	}

	DuLNode* s = new DuLNode;
	s->data = e;

	s->prior = p->prior;
	p->prior->next = s;

	s->next = p;
	p->prior = s;

	return 0;
}

/*
* 在双向链表中查找第i个节点，使用p指针指向它
*/
DuLNode* getElemP_Dul(DuLinkList L, int i) {

	int j = 1;

	DuLNode* p;
	p = L->next;

	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || j > i) {

		// 找到最后也没有找到，或者i的值小于j
		return NULL;
	}
	return p;
}