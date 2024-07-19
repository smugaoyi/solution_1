#include<iostream>
using namespace std;

// ������Ļ���������
// ����������������١���յ�����������ĳ��ȡ��ж������Ƿ�Ϊ�ա����ҡ����롢ɾ����

// ������Ĳ��ҡ����롢ɾ���㷨��ʱ��Ч�ʷ���
// ���ң�ʱ�临�Ӷ�O(n)
// �����ɾ��������Ҫ�ƶ�Ԫ�أ�ʱ�临�Ӷ�O(1),����Ѱ�ҵ�i������λ�û�ɾ��λ����ҪO(n)


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

/*
* 6��ȡ������ĵ�i��Ԫ�ص�����
*/
int getElem(LinkList L, int i ,ElemType &e) {

	// �������ĳ�ʼֵΪ1
	int j = 1;

	Lnode* p;
	// ����Ԫ��㿪ʼ
	p = L->next;

	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	
	if (p == NULL || j > i) {
	
		// �ҵ����Ҳû���ҵ�������i��ֵС��j
		return -1;
	}

	// j == i���ҵ���
	e = p->data;

	return 0;
}

/*
* 7������ֵΪe��Ԫ�صĵĵ�ַ
*/
Lnode* locateElem(LinkList L, int e) {

	Lnode* p;
	p = L->next;
	// �˴�ʹ������age��Ϊ����
	while (p != NULL && p->data.age != e) {
		p = p->next;
	}

	return p;
}

/*
* 8���ڵ�i��Ԫ��֮ǰ����һ���½ڵ�
* �˴�Lʹ���������ͣ�����һ����Ԫ�غ�L�䳤��ʹ��L����
*/
int insertE(LinkList &L, int i, ElemType e) {

	Lnode* p;
	p = L;

	int j = 0;
	// ѭ��������pָ��ָ���i-1���ڵ�
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}

	// i���ڱ�+1����С��1������λ�÷Ƿ�
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
* 9��ɾ����i���ڵ�
*/
int deleteE(LinkList& L, int i) {

	Lnode* p,*q;
	p = L;

	int j = 0;

	// ѭ��������pָ��ָ���i-1���ڵ�
	while (p->next != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}

	if (p->next == NULL || j > i - 1) {
		return -1;
	}

	// �����i��Ԫ�صĵ�ַ����������ִ�����p->next��ֵ�ͱ���
	q = p->next;

	// �ȼ���p->next = q->next;
	p->next = p->next->next;
	delete q;

	return 0;
}

/*
* ���Ա�ĺϲ�
*/
int union_list(LinkList& La, LinkList Lb) {
	int la_Len = lenList(La);
	int lb_Len = lenList(Lb);

	for (int i = 1; i <= lb_Len; i++) {
	
		ElemType e;
		getElem(Lb, i, e);

		// ��La����e
		Lnode * p = locateElem(La, e.age);
		if (p == NULL) {
			// ��Laβ������
		}

	}

	return 0;
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

