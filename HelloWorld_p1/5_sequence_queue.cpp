#include<iostream>
using namespace std;

// 顺序队列

#define MAX_Q_SIZE 100

// 定义队列元素类型
typedef struct {
	int data;
}QElemType;

typedef struct {
	QElemType* base;
	int front;
	int rear;
}SqQueue;

