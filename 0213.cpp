#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<assert.h>
typedef struct {
    int* data;
    int front;
    int rear;
    int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (queue == NULL) {
        perror("malloc failed");
        return NULL;
    }
    queue->data = (int*)malloc(sizeof(int) * (k + 1));
    if (queue->data == NULL) {
        perror("malloc failed");
        return NULL;
    }
    queue->front = queue->rear = 0;
    queue->k = k + 1;
    return queue;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    return (obj->rear + 1) % (obj->k) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    if (!myCircularQueueIsFull(obj)) {
        obj->data[(obj->rear++) % (obj->k)] = value;
        return true;
    }
    else {
        return false;
    }

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    if (!myCircularQueueIsEmpty(obj)) {
        obj->front = (obj->front + 1) % (obj->k);
        return true;
    }
    else {
        return false;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    if (!myCircularQueueIsEmpty(obj)) {
        return obj->data[obj->front];
    }
    else {
        return -1;
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    if (!myCircularQueueIsEmpty(obj)) {
        return obj->rear == 0 ? obj->data[obj->k - 1] : obj->data[obj->rear - 1];
    }
    else {
        return -1;
    }
}


void myCircularQueueFree(MyCircularQueue* obj) {
    assert(obj);
    free(obj->data);
    obj->data = NULL;
    free(obj);
}
