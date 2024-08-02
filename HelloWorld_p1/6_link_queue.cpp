#include<iostream>
using namespace std;

// 队列的链式表示

typedef struct {
	int data;
	//...
}QElemType;

typedef struct Qnode {
	QElemType data;
	struct Qnode* next;
}QNode, * QueuePtr;

typedef struct {
	// 队头指针
	QueuePtr front;
	// 队尾指针
	QueuePtr rear;
}LinkQueue;

/*
* 链队列初始化
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
* 销毁队列
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
* 链队列入队
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