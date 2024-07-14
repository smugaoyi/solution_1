#include<iostream>
using namespace std;

/*
* ����ElemTypeΪ�ṹ������
*/
typedef struct {
	string name;
	int age;
	int score;
} ElemType;

/*
* ���Ͷ���
*/
typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}Lnode, * LinkList;


LinkList L;

/* 
* 1����ʼ������������ͷ���
*/
int initList_L(LinkList& L) {
	// �����µĽ����Ϊͷ��㣬����ͷָ��ָ��ͷ���
	L = new Lnode;
	// ��ͷ����ָ�����ÿ�
	L->next = NULL;

	return 0;
}

/*
* 2���ж������Ƿ������
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
* 3�����ٵ�����
* ͷָ���ͷ���Ҳ������
*/
int destroyList(LinkList& L) {
	// ָ��Ҫ���ٵĽ��
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
* 4���������
* ͷָ���ͷ�����Ȼ����
* ͷ����ָ����ΪNULL
* 
*/
int clearList(LinkList& L) {

	Lnode* p, * q;
	// ��ʼʱ��pָ��ָ����Ԫ���
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
* 5��������ĳ���
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
		std::cout << "����ǿ�";
	}
	else
	{
		std::cout << "����Ϊ��";
	}
	
	// test


}

