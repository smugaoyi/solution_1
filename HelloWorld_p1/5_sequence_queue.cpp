#include<iostream>
using namespace std;

// ˳�����

#define MAX_Q_SIZE 100

// �������Ԫ������
typedef struct {
	int data;
}QElemType;

typedef struct {
	QElemType* base;
	int front;
	int rear;
}SqQueue;

