#include<iostream>
using namespace std;

// Last In First Out �����Ա����LIFO�ṹ��
// ˳��ջֻ���������β�����в�������ջֻ���������ͷ�����в�����


typedef struct {
	int data;
	//...
}SElemType;

typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

/*
* ��ջ����ջ������ͷ���ĵ�����
*/
int push(LinkStack& S, SElemType e) {
	StackNode* p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;

	return 0;
}