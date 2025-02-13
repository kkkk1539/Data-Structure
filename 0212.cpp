//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//typedef struct stack {
//    char* data;
//    int top;
//    int capacity;
//}st;
//
//void Init(st* s) {
//    s->data = (char*)malloc(sizeof(char) * 4);
//    if (s->data == NULL) {
//        return;
//    }
//    s->top = -1;
//    s->capacity = 4;
//}
//
//void Destory(st* s) {
//    free(s->data);
//    s->top = 0;
//    s->capacity = 0;
//}
//
//void Push(st* s, char x) {
//    if (s->top == s->capacity - 1) {
//        char* tmp = (char*)realloc(s->data, sizeof(char) * s->capacity * 2);
//        if (tmp != NULL) {
//            s->data = tmp;
//            s->capacity *= 2;
//        }
//    }
//    s->data[++s->top] = x;
//}
//
//void Pop(st* s) {
//    if (s->data != NULL)
//        s->top--;
//}
//
//char STop(st* s) {
//    if (s->data != NULL && s->top != -1) {
//        return s->data[s->top];
//    }
//    return '\0'; // 返回一个默认值
//}
//
//bool isValid(char* s) {
//    st stack;
//    Init(&stack);
//    while (*s) {
//        if (*s != ')' && *s != '}' && *s != ']') {
//            Push(&stack, *s);
//        } else {
//            if (*s == ')' && (stack.top == -1 || STop(&stack) != '(')) {
//                return false;
//            } else if (*s == ']' && (stack.top == -1 || STop(&stack) != '[')) {
//                return false;
//            } else if (*s == '}' && (stack.top == -1 || STop(&stack) != '{')) {
//                return false;
//            }
//            Pop(&stack);
//        }
//        s++;
//    }
//    bool result = (stack.top == -1);
//    Destory(&stack);
//    return result;
//}
//
//typedef struct QueueNode {
//    struct QueueNode* next;
//    int data;
//}QueueNode;
//
//typedef struct Queue {
//    QueueNode* head;
//    QueueNode* tail;
//    int size;
//}Queue;
//
//void QueueInit(Queue* pq) {
//    if (pq == NULL) return;
//    pq->head = pq->tail = NULL;
//    pq->size = 0;
//}
//
//void QueueDestory(Queue* pq) {
//    if (pq == NULL) return;
//    QueueNode* cur = pq->head;
//    while (cur) {
//        QueueNode* nextNode = cur->next;
//        free(cur);
//        cur = nextNode;
//    }
//    pq->head = pq->tail = NULL;
//    pq->size = 0;
//}
//
//void QueuePush(Queue* pq, int x) {
//    if (pq == NULL) return;
//    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
//    if (newNode == NULL) {
//        perror("malloc");
//        return;
//    }
//    newNode->data = x;
//    newNode->next = NULL;
//    if (pq->head == NULL && pq->tail == NULL) {
//        pq->head = pq->tail = newNode;
//    }
//    else {
//        pq->tail->next = newNode;
//        pq->tail = newNode;
//    }
//    pq->size++;
//}
//
//void QueuePop(Queue* pq) {
//    if (pq == NULL || pq->head == NULL) return;
//    QueueNode* tmp = pq->head->next;
//    free(pq->head);
//    pq->head = tmp;
//    if (pq->head == NULL) {
//        pq->tail = NULL;
//    }
//    pq->size--;
//}
//
//bool IsEmpty(Queue* pq) {
//    return pq->size == 0;
//}
//
//int QueueFront(Queue* pq) {
//    if (pq == NULL) return -1;
//    return pq->head->data;
//}
//
//int QueueBack(Queue* pq) {
//    if (pq == NULL) return -1;
//    return pq->tail->data;
//
//}
//
//int QueueSize(Queue* pq) {
//    if (pq == NULL) return -1;
//    return pq->size;
//}
//
//typedef struct {
//    Queue q1;
//    Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
//    if (pst == NULL) {
//        perror("malloc failed");
//        return NULL;
//    }
//    QueueInit(&pst->q1);
//    QueueInit(&pst->q2);
//    return pst;
//}
//
//void myStackPush(MyStack* obj, int x) {
//    Queue* emptyQueue = &obj->q1;
//    Queue* nonemptyQueue = &obj->q2;
//    if (IsEmpty(&obj->q2)) {
//        emptyQueue = &obj->q2;
//        nonemptyQueue = &obj->q1;
//    }
//    QueuePush(nonemptyQueue, x);
//}
//
//int myStackPop(MyStack* obj) {
//    Queue* emptyQueue = &obj->q1;
//    Queue* nonemptyQueue = &obj->q2;
//    if (IsEmpty(&obj->q2)) {
//        emptyQueue = &obj->q2;
//        nonemptyQueue = &obj->q1;
//    }
//    while (QueueSize(nonemptyQueue) > 1) {
//        QueuePush(emptyQueue, QueueFront(nonemptyQueue));
//        QueuePop(nonemptyQueue);
//    }
//    int top = QueueFront(nonemptyQueue);
//    QueuePop(nonemptyQueue);
//    return top;
//}
//
//int myStackTop(MyStack* obj) {
//    Queue* emptyQueue = &obj->q1;
//    Queue* nonemptyQueue = &obj->q2;
//    if (IsEmpty(&obj->q2)) {
//        emptyQueue = &obj->q2;
//        nonemptyQueue = &obj->q1;
//    }
//    return QueueBack(nonemptyQueue);
//}
//
//bool myStackEmpty(MyStack* obj) {
//    return IsEmpty(&obj->q1) && IsEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) {
//    QueueDestory(&obj->q1);
//    QueueDestory(&obj->q2);
//    free(obj);
//}
