#include<iostream>
using namespace std;

// Last In First Out �����Ա����LIFO�ṹ��
// ˳��ջֻ���������β�����в�������ջֻ���������ͷ�����в�����

#define MAXSIZE 10
typedef struct {
	int data;
	//...
}SElemType;

typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

