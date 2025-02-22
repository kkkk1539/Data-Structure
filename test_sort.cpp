#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
void testinsert() {
	int a[] = { 5,4,1,3,7,2,8,9,0,6 };
	int sz = sizeof(a) / sizeof(int);
	InsertSort(a, sz);
	PrintArray(a, sz);
}

void testshell() {
	int a[] = { 2,34,5,6456,576,756,42,-342,534,5,66,45 };
	int sz = sizeof(a) / sizeof(int);
	ShellSort(a, sz);
	PrintArray(a, sz);
}

void testselect() {
	int a[] = { 1,8,8,5,3,8,9 };
	int sz = sizeof(a) / sizeof(int);
	SelectSort(a, sz);
	PrintArray(a, sz);
}

void testheap() {
	int a[] = { 1,43,53,5,351,21,352,56,36 };
	int sz = sizeof(a) / sizeof(int);
	HeapSort(a, sz);
	PrintArray(a, sz);
}

void testbubble() {
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(a) / sizeof(int);
	BubbleSort(a, sz);
	PrintArray(a, sz);
}

void testquick() {
	int a[] = {3,1,3,2 };
	int sz = sizeof(a) / sizeof(int);
	QuickSort(a, 0, sz - 1);
	PrintArray(a, sz);
}

void testquicknonr() {
	int a[] = { 9,6,4,23,2,3,1,7,3 };
	int sz = sizeof(a) / sizeof(int);
	QuickSortNonR(a, 0, sz - 1);
	PrintArray(a, sz);
}
void testradixsort() {
	int a[] = { 278,109,63,930,589,184,505,269,8,83 };
	int sz = sizeof(a) / sizeof(a[0]);
	RadixSort(a, 0, sz - 1);
	PrintArray(a, sz);
	
}
//int main() {
//	testinsert();
//	testshell();
//	testselect();
//	testheap();
//	testbubble();
//	testquick();
//	testquicknonr();
//	testradixsort();
//	return 0;
//}