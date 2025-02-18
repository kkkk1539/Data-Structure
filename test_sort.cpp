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
int main() {
	testinsert();
	testshell();
	return 0;
}