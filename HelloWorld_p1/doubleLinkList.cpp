#include<iostream>
using namespace std;

// �����ȥ����η����

/*
* ����ElemTypeΪ�ṹ������
*/
typedef struct {
	string name;
	int age;
	int score;
} ElemType;

/*
* ˫������Ľṹ����
*/
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode, * DuLinkList;

/*
* ˫������ĵ�i�����ǰ����
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
* ��˫�������в��ҵ�i���ڵ㣬ʹ��pָ��ָ����
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

		// �ҵ����Ҳû���ҵ�������i��ֵС��j
		return NULL;
	}
	return p;
}