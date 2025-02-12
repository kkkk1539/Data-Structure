#include"Stack.h"
void STInit(ST* ps) {
    assert(ps);
    ps->data = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (ps->data == NULL) {
        perror("STInit::malloc");
        return;
    }
    ps->capacity = 4;
    ps->top = -1;
}

void STDestory(ST* ps) {
    assert(ps);
    free(ps->data);
    ps->top = -1;
    ps->capacity = 0;
}

void STPush(ST* ps, STDataType x) {
    assert(ps);
    if (ps->top == ps->capacity - 1) {
        STDataType* tmp = (STDataType*)realloc(ps->data, sizeof(STDataType) * ps->capacity * 2);
        if (tmp == NULL) {
            perror("STPush::realloc");
            return;
        }
        ps->data = tmp;
        ps->capacity *= 2;
    }
    ps->data[++ps->top] = x;
}

bool IsEmpty(ST* ps) {
    assert(ps);
    return ps->top == -1;
}

void STPop(ST* ps) {
    assert(ps);
    assert(!IsEmpty(ps));
    ps->top--;
}

STDataType STTop(ST* ps) {
    assert(ps);
    assert(!IsEmpty(ps));
    return ps->data[ps->top];
}

int STSize(ST* ps) {
    assert(ps);
    return ps->top + 1;
}