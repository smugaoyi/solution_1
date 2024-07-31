#include<iostream>
using namespace std;

// ˳�����

#define MAX_Q_SIZE 100

// �������Ԫ������
typedef struct {
	int data;
}QElemType;

// ����˳�����
typedef struct {
	QElemType* base;
	int front;
	int rear;
}SqQueue;

/*
* ��ʼ��˳�����
*/
int initSqQueue(SqQueue& Q) {
	Q.base = new QElemType[MAX_Q_SIZE];
	if (Q.base == NULL) {
		// �洢�ռ����ʧ��
		return -1;
	}
	Q.front = Q.rear = 0;

	return 0;
}

/*
* ����еĳ��ȣ�ѭ�����У�
*/
int queueLen(SqQueue Q) {
	return (Q.rear - Q.front + MAX_Q_SIZE) % MAX_Q_SIZE;
}

/*
* ѭ�����е���ӣ�����ʱfrontͬ��
*/
int enterQueue(SqQueue& Q, QElemType e) {
	// �ж϶���
	// �ж϶����Ƿ������ģ����ܽ���ʹ��Q.rear == Q.front����Ϊ�ն��е�����£�Ҳ��Q.rear == Q.front
	if ((Q.rear + 1) % MAX_Q_SIZE == Q.front) {
		return -1;
	}

	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAX_Q_SIZE;

	return 0;
}

