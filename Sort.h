#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void PrintArray(int* a, int n);

void InsertSort(int* a, int n);

void ShellSort(int* a, int n);

void SelectSort(int* a, int n);

void HeapSort(int* a, int n);

void BubbleSort(int* a, int n);

int PartSort1(int* a, int left, int right);

int PartSort2(int* a, int left, int right);

int PartSort3(int* a, int left, int right);

void QuickSort(int* a, int left, int right);

void QuickSortNonR(int* a, int left, int right);

void _MergeSort(int* a, int left, int right,int* tmp);

void MergeSort(int* a, int left, int right);

void MergeSortNonR(int* a, int n, int* tmp);

void CountSort(int* a, int n);

void RadixSort(int* a, int left, int right);