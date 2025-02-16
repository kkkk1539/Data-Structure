#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int STDataType;

typedef struct Stack {
	int* data;
	int top;
	int capacity;
}ST;

void STInit(ST*);

void STDestory(ST*);

void STPush(ST*, STDataType);

void STPop(ST*);

STDataType STTop(ST*);

int STSize(ST*);

bool IsEmpty(ST*);



