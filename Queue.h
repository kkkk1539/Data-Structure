#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//typedef struct BinaryTreeNode* QueueDataType;
typedef int QueueDataType;

typedef struct QueueNode {
	struct QueueNode* next;
	QueueDataType data;
}QueueNode;

typedef struct Queue {
	QueueNode* head;
	QueueNode* tail;
	int size;
}Queue;

void QueueInit(Queue*);

void QueueDestory(Queue*);

void QueuePush(Queue*, QueueDataType);

void QueuePop(Queue*);

int QueueSize(Queue*);

bool QueueEmpty(Queue*);

QueueDataType QueueFront(Queue*);

QueueDataType QueueBack(Queue*);