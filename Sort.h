#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void PrintArray(int* a, int n);

void InsertSort(int* a, int n);

void ShellSort(int* a, int n);

void SelectSort(int* a, int n);

void HeapSort(int* a, int n);

void BubbleSort(int* a, int n);

int PartSort1(int* a, int left, int right);

int PartSort2(int* a, int left, int right);

void QuickSort(int* a, int left, int right);