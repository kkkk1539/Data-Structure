#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef struct stack {
    char* data;
    int top;
    int capacity;
}st;

void Init(st* s) {
    s->data = (char*)malloc(sizeof(char) * 4);
    if (s->data == NULL) {
        return;
    }
    s->top = -1;
    s->capacity = 4;
}

void Destory(st* s) {
    free(s->data);
    s->top = 0;
    s->capacity = 0;
}

void Push(st* s, char x) {
    if (s->top == s->capacity - 1) {
        char* tmp = (char*)realloc(s->data, sizeof(char) * s->capacity * 2);
        if (tmp != NULL) {
            s->data = tmp;
            s->capacity *= 2;
        }
    }
    s->data[++s->top] = x;
}

void Pop(st* s) {
    if (s->data != NULL)
        s->top--;
}

char STop(st* s) {
    if (s->data != NULL && s->top != -1) {
        return s->data[s->top];
    }
    return '\0'; // 返回一个默认值
}

bool isValid(char* s) {
    st stack;
    Init(&stack);
    while (*s) {
        if (*s != ')' && *s != '}' && *s != ']') {
            Push(&stack, *s);
        } else {
            if (*s == ')' && (stack.top == -1 || STop(&stack) != '(')) {
                return false;
            } else if (*s == ']' && (stack.top == -1 || STop(&stack) != '[')) {
                return false;
            } else if (*s == '}' && (stack.top == -1 || STop(&stack) != '{')) {
                return false;
            }
            Pop(&stack);
        }
        s++;
    }
    bool result = (stack.top == -1);
    Destory(&stack);
    return result;
}