#include<iostream>
using namespace std;

// ���е���ʽ��ʾ

typedef struct {
	int data;
	//...
}QElemType;

typedef struct Qnode {
	QElemType data;
	struct Qnode* next;
}QNode, * QueuePtr;

typedef struct {
	// ��ͷָ��
	QueuePtr front;
	// ��βָ��
	QueuePtr rear;
}LinkQueue;

/*
* �����г�ʼ��
*/
int initQueue(LinkQueue& Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) {
		return -1;
	}
	Q.front->next = NULL;

	return 0;
}

/*
* ���ٶ���
*/
int destroyQueue(LinkQueue& Q) {
	QueuePtr p;
	while (Q.front) {
		p = Q.front->next;
		free(Q.front);
		Q.front = p;
	}

	return 0;
}

/*
* ���������
*/
int enterQueue(LinkQueue& Q, QElemType e) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) {
		return -1;
	}

	p->data = e;
	p->next = NULL;
	Q.rear = p;

	return 0;
}

// 581