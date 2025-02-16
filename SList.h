#pragma once //防止多次展开 还有就是文件创建的时候你选择的模板是.cpp不是.h导致的
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define Init_Capacity 5
typedef int ElementType;

typedef struct SList {
	ElementType* data;
	size_t size;
	size_t capacity;
}SL;

void SL_Init(SL*);

void SL_Destroy(SL*);

void SL_Print(SL*);

void SL_PushFront(SL*,ElementType);

void SL_PushBack(SL*,ElementType);

void SL_PopFront(SL*);

void SL_PopBack(SL*);

void SL_Modify(SL*, size_t,ElementType);

int SL_Search(SL*, ElementType);

void SL_Insert(SL*, size_t, ElementType);

void SL_Delete(SL*, size_t);

void Check_Capacity(SL*);