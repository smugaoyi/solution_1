#include<iostream>
using namespace std;

// 顺序队列

#define MAX_Q_SIZE 100

// 定义队列元素类型
typedef struct {
	int data;
}QElemType;

// 定义顺序队列
typedef struct {
	QElemType* base;
	int front;
	int rear;
}SqQueue;

/*
* 初始化顺序队列
*/
int initSqQueue(SqQueue& Q) {
	Q.base = new QElemType[MAX_Q_SIZE];
	if (Q.base == NULL) {
		// 存储空间分配失败
		return -1;
	}
	Q.front = Q.rear = 0;

	return 0;
}

/*
* 求队列的长度（循环队列）
*/
int queueLen(SqQueue Q) {
	return (Q.rear - Q.front + MAX_Q_SIZE) % MAX_Q_SIZE;
}

/*
* 循环队列的入队（出队时front同理）
*/
int enterQueue(SqQueue& Q, QElemType e) {
	// 判断队满
	// 判断队列是否是满的，不能仅仅使用Q.rear == Q.front，因为空队列的情况下，也是Q.rear == Q.front
	if ((Q.rear + 1) % MAX_Q_SIZE == Q.front) {
		return -1;
	}

	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAX_Q_SIZE;

	return 0;
}

