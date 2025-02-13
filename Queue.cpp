#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void QueueInit(Queue* pq) {
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QueueDestory(Queue* pq) {
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur) {
		QueueNode* nextNode = cur->next;
		free(cur);
		cur = nextNode;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QueueDataType x) {
	assert(pq);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) {
		perror("QueuePush::malloc");
		return;
	}
	newNode->data = x;
	newNode->next = NULL;
	if (pq->head == NULL) {
		assert(!pq->tail);
		pq->head = pq->tail= newNode;
	}
	else {
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
	pq->size++;
}

void QueuePop(Queue* pq) {
	assert(pq);
	assert(pq->head);
	QueueNode* tmp = pq->head->next;
	free(pq->head);
	pq->head = tmp;
	if (pq->head == NULL)
		pq->tail = NULL;
	pq->size--;
}

int QueueSize(Queue* pq) {
	assert(pq);
	/*QueueNode* cur = pq->head;
	int size = 0;
	while (cur) {
		cur = cur->next;
		size++;
	}*/
	return pq->size;
}

bool QueueEmpty(Queue* pq) {
	assert(pq);
	return pq->head == NULL;
}

QueueDataType QueueFront(Queue* pq) {
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}

QueueDataType QueueBack(Queue* pq) {
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}