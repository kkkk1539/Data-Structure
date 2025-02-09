#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void SL_Init(SL* ps) {
    assert(ps);
    ps->data = (ElementType*)malloc(sizeof(ElementType) * Init_Capacity);
    if (ps->data != NULL) {
        ps->capacity = Init_Capacity;
        ps->size = 0;
    } else {
        perror("SL_Init::malloc");
        return;
    }
}

void SL_Destroy(SL* ps) {
    assert(ps);
    free(ps->data);
    ps->data = NULL;
    ps->capacity = ps->size = 0;
}

void SL_Print(SL* ps) {
    assert(ps);
    for (size_t i = 0; i < ps->size; i++) {
        printf("%d ", ps->data[i]);
    }
    printf("\n");
}

void Check_Capacity(SL* ps) {
    assert(ps);
    if (ps->size == ps->capacity) {
        ElementType* tmp = (ElementType*)realloc(ps->data, sizeof(ElementType) * ps->capacity * 2);
        if (tmp != NULL) {
            ps->data = tmp;
            ps->capacity *= 2;
        } else {
            perror("Check_Capacity::realloc");
            return;
        }
    }
}

void SL_PushFront(SL* ps, ElementType x) {
    assert(ps);
    SL_Insert(ps, 0, x);
}

void SL_PushBack(SL* ps, ElementType x) {
    assert(ps);
    Check_Capacity(ps);
    ps->data[ps->size++] = x;
}

void SL_PopFront(SL* ps) {
    assert(ps);
    SL_Delete(ps, 0);
}

void SL_PopBack(SL* ps) {
    assert(ps);
    if (ps->size > 0) {
        ps->size--;
    }
}

void SL_Modify(SL* ps, size_t pos, ElementType x) {
    assert(ps);
    if (pos < ps->size) {
        ps->data[pos] = x;
    }
}

int SL_Search(const SL* ps, ElementType x) {
    assert(ps);
    for (size_t i = 0; i < ps->size; i++) {
        if (ps->data[i] == x) {
            return i;
        }
    }
    return -1;
}

void SL_Insert(SL* ps, size_t pos, ElementType x) {
    assert(ps);
    if (pos <= ps->size) {
        Check_Capacity(ps);
        for (size_t i = ps->size; i > pos; i--) {
            ps->data[i] = ps->data[i - 1];
        }
        ps->data[pos] = x;
        ps->size++;
    }
}

void SL_Delete(SL* ps, size_t pos) {
    assert(ps);
    if (pos < ps->size) {
        for (size_t i = pos; i < ps->size - 1; i++) {
            ps->data[i] = ps->data[i + 1];
        }
        ps->size--;
    }
}